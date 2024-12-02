#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include <libtar.h>
#include <zlib.h>

#include "common.h"
#include "llist.h"

/* 
 * What we want to do here is make the ypf file,
 * then compress it and the binary tarballs involved.
 *
 */

#define CHUNK 16384

/* This is from official Zlib docs. */
int compress(FILE *src, FILE *dest, int level)
{
	int ret, flush;
	unsigned have;
	z_stream strm;
	unsigned char in[CHUNK];
	unsigned char out[CHUNK];

	strm.zalloc = Z_NULL;
	strm.zfree  = Z_NULL;
	strm.opaque = Z_NULL;
	ret = deflateInit(&strm, level);
	if (ret != Z_OK) {
		return ret;
	}

	do { /* Compress until end of file! */
		strm.avail_in = fread(in, 1, CHUNK, src); /* Write to buffer in[] input file one chunk at a time */
		if (ferror(src)) { /* Error check */
			(void) deflateEnd(&strm); /* upon error end deflation process */
			return Z_ERRNO;
		}
		flush = feof(src) ? Z_FINISH : Z_NO_FLUSH; /* Checking to see whether we are at EOF yet */
		strm.next_in = in;
		do { /* Deflate data chunk inputs */
			strm.avail_out = CHUNK;
			strm.next_out = out;
			ret = deflate(&strm, flush); /* Actually deflate now */
			assert(ret != Z_STREAM_ERROR);

			have = CHUNK - strm.avail_out;
			if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
				(void) deflateEnd(&strm);
				return Z_ERRNO;
			}

		} while (strm.avail_out == 0);
			
		

/* Write YPF package file.
 */
int writeYPF(YPF* packageData)
{
	FILE* file;
	
	char* fname = strcat(packageData->&name, ".ypf");
	file = fopen(fname, "w");

	if (file == NULL){
		fprintf(stderr, "\nError: failed to create %s.", fname);
		exit(1);
	}
	
	int op = fwrite(packageData, sizeof(YPF), 1, file);
	if op {
		printf("%s written succesfully", fname);
	} else
		fprintf(stderr, "\nError: failed to write to %s.", fname);
	
	fclose(file);

	return 0;
}

/* 
 * Reads from a YPF file and returns a YPF struct.
 */
YPF* readYPF(const char path)
{
	FILE* infile;
	YPF YPF_file;
		
	infile = fopen(path, "r");

	if (file == NULL){
		fprintf(stderr, "\nError: failed to read %s.", path);
		exit(1);
	}
	
	op = fread(&YPF_file, sizeof(YPF), 1, infile);
	
	if op {
		printf("%s read succesfully", path);
	} else
		fprintf(stderr, "\nError: failed to read %s.", path);

	return &YPF_file;
}

/*
	NOTE: providing node_t arguments frees them after the function is called.
*/
int makeYPF(char name, char version,  node_t* contents, node_t* deps, char author, uint8_t flags)
{
	YPF* file = (YPF*) malloc(sizeof(YPF));
	file->name = name;
	file->version = version;
	/* TODO: get filesize of binary tarball */
	file->contents_headnode = contents;
	file->deps_headnode = deps;
	file->author = author;
	file->flags = flags;
	
	int op = writeYPF(file);
	if op {
		printf("%s written succesfully", fname);
	} else
		fprintf(stderr, "\nError: failed to write to %s.", fname);
		exit(1);
	
	free_list(contents);
	free_list(deps);
}


void showYPFcontents(const char path)
{
	YPF* file = readYPF(path);

	printf("Package Name: %s \n \
		Package Version: %s \n \
		Size: %d \n \ 		
		Programs: %s \n \ 		
		Dependencies: %s \n \ 
		Flags: %d \n",
		file->name, file->version,
		file->fsize, print_list(file->contents_headnode),
		print_list(file->deps_headnode),
		file->flags);
}


