#ifndef FILE_H
#define FILE_H
#include "cell.h"

typedef struct file_ { // aka FIFO, queue
	cell* first;
	cell* last;
} file;

file* newFile();
int estVideFile(file* f);
file* addFile(int v, file* f);
cell* pop(file* f);
void afficheFile(file* f);

#endif
