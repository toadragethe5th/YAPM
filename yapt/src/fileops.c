#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include <libtar.h>
#include <zlib.h>

#include "common.h"

/* 
 * What we want to do here is make the ypf file,
 * then compress it and the binary tarballs involved.
 *
 */

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

uint8_t showYPFcontents(const char path)
{
	YPF* file = readYPF(path);

	printf("Package Name: %s \n \
		Package Version: %s \n \
		Size: %d \n \


