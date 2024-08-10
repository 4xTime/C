#pragma once
#include <stdlib.h>

typedef struct {
	void** DATA;
	int size;
}cVec;

cVec* create_cVec() {
	cVec* vec = (cVec*)malloc(sizeof(cVec));
	if (vec) {
		vec->DATA = NULL;
		vec->size = 0;
	}
	return vec;
}

void cVec_destroy(cVec* vec) {
	free(vec->DATA);
	free(vec);
}

void cVec_add(cVec* vec, void* arg) {
	void** newData = (void**)malloc((vec->size + 1) * sizeof(void*));
	if (!newData) {
		printf("%s", "Error->cVec_add");
		return;
	}

	memcpy_s(newData, (vec->size + 1) * sizeof(void*), vec->DATA, vec->size * sizeof(void*));
	newData[vec->size] = arg;

	free(vec->DATA);
	vec->DATA = newData;
	vec->size++;
}

void cVec_remove_last(cVec* vec) {
	if (vec->size == 0) {
		printf("Error: Vector is empty.\n");
		return;
	}

	void** newData = (void**)malloc((vec->size-1) * sizeof(void*));
	if (!newData) {
		printf("%s", "Error->cVec_remove_last");
		return;
	}

	memcpy_s(newData, (vec->size-1) * sizeof(void*), vec->DATA, (vec->size-1) * sizeof(void*));

	free(vec->DATA);
	vec->DATA = newData;
	vec->size--;
	if (vec->size == 0) { vec->DATA = NULL; }
}

void cVec_remove_object_by_index(cVec* vec,const int index) {
	if (vec->size == 0) {
		printf("Error: Vector is empty.\n");
		return;
	}

	void** newData = (void**)malloc((vec->size-1) * sizeof(void*));
	if (!newData) {
		printf("%s", "Error->cVec_remove_object_by_index");
		return;
	}
	
	if (index == vec->size) {
		cVec_remove_last(vec);
	}
	else {
		int count = 0;
		for (int i = 0; i < vec->size; i++) {
			if (i != index) {
				newData[count] = vec->DATA[i];
				count++;
			}
		}
	}

	free(vec->DATA);
	vec->DATA = newData;
	vec->size--;
}

void cVec_remove_object_by_argument(cVec* vec,void* arg) {
	if (vec->size == 0) {
		printf("Error: Vector is empty.\n");
		return;
	}

	cVec* index_vec = create_cVec();
	int amount_of_deleted_elements = 0;
	for (int i = 0; i < vec->size; i++) {
		if (vec->DATA[i] == arg) {
			amount_of_deleted_elements++;
			cVec_add(index_vec, (void*)(intptr_t)i);
		}
	}

	for (int i = index_vec->size - 1; i >= 0; i--) {
		cVec_remove_object_by_index(vec, (int)(intptr_t)index_vec->DATA[i]);
	}

	cVec_destroy(index_vec);
}

