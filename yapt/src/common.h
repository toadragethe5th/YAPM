#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

/* Bitmasks for easy flag making. */
#define NONFREE    0b100
#define DEPRECATED 0b010
#define ISDEP      0b001

typedef struct YPF {
	char name;
	char version;
	uint16_t fsize; /* Size of binary tarball */
	node_t* contents_headnode; /* Contents of binary tarball */
	node_t* deps_headnode; /* Dependencies needed */
	char author;
	char time;
	uint8_t flags;
} YPF;

#endif
