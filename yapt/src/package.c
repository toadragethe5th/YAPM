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
int wrYPF(YPF_t* packageData)
{
	FILE* file;
	
	char* fname = strcat(packageData->&name, ".ypf");
	file = fopen(fname, "w");

	if (file == NULL){
		fprintf(stderr, "\nError: failed to create %s.", fname);
		exit(1);
	}
	
	int op = fwrite(packageData, sizeof(YPF_t), 1, file);
	if op {
		printf("%s written succesfully", fname);
	} else
		fprintf(stderr, "\nError: failed to write to %s.", fname);
	
	fclose(file);

	return 0;
}

int 
