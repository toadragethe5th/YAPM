#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

/* Bitmasks for easy flag making. */
#define NONFREE    0b100
#define DEPRECATED 0b010
#define ISDEP      0b001

typedef struct YPF_t {
	char name;
	char version;
	uint16_t fsize; /* Size of binary tarball */
	char contains[16]; /* Contents of binary tarball */
	char depends[16]; /* Dependencies needed */
	char source; /* URL for source (Webpage or source tarball) */
	uint8_t flags;
} YPF_t;

#endif
