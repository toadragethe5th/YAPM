#ifndef FILEOPS_H
#define FILEOPS_H

/* (YPF*) is basically just fancy file handler at this point. */

int writeYPF(YPF* packageData);
YPF* readYPF(const char* path);
void showYPFcontents(const char* path);

#endif
