#ifndef CVEC_H
#define CVEC_H
#include <stdlib.h>
#include <stdio.h>
#include <errno.h> 
#include <string.h>

typedef struct {
	void** DATA;
	int size;
} cVec;

cVec* create_cVec();
void cVec_destroy(cVec* vec);
void cVec_add(cVec* vec, void* arg);
void cVec_remove_last(cVec* vec);
void cVec_remove_object_by_index(cVec* vec, const int index);
void cVec_remove_object_by_argument(cVec* vec, void* arg);
void cVec_erase_transfer(cVec* vec_dest, cVec* vec_source);
void cVec_clear(cVec* vec);
void cVec_resize(cVec* vec, size_t new_capacity);
void cVec_swap(cVec* vec1, cVec* vec2);

#endif // CVEC_H