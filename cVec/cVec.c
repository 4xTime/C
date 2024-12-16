#include "cVec.h"

cVec* create_cVec() {
	cVec* vec = (cVec*)malloc(sizeof(cVec));
	if (!vec) {
		printf("Error: Memory allocation failed in create_cVec.\n");
		return NULL;
	}
	vec->DATA = NULL;
	vec->size = 0;
	return vec;
}

void cVec_destroy(cVec* vec) {
	if (!vec) return;
	free(vec->DATA);
	free(vec);
}

void cVec_add(cVec* vec, void* arg) {
	if (!vec) return;

	size_t new_size = vec->size == 0 ? 1 : vec->size * 2;
	void** newData = realloc(vec->DATA, new_size * sizeof(void*));
	if (!newData) {
		printf("Error: Memory allocation failed in cVec_add.\n");
		return;
	}

	vec->DATA = newData;
	vec->DATA[vec->size] = arg;
	vec->size++;
}

void cVec_remove_last(cVec* vec) {
	if (!vec || vec->size == 0) {
		printf("Error: Vector is empty or NULL in cVec_remove_last.\n");
		return;
	}

	vec->size--;
	if (vec->size == 0) {
		free(vec->DATA);
		vec->DATA = NULL;
	}
	else {
		void** newData = realloc(vec->DATA, vec->size * sizeof(void*));
		if (!newData) {
			printf("Error: Memory allocation failed in cVec_remove_last.\n");
			return;
		}
		vec->DATA = newData;
	}
}

void cVec_remove_object_by_index(cVec* vec, const int index) {
	if (!vec || index < 0 || index >= vec->size) {
		printf("Error: Invalid index or NULL vector.\n");
		return;
	}

	for (int i = index; i < vec->size - 1; i++) {
		vec->DATA[i] = vec->DATA[i + 1];
	}

	cVec_remove_last(vec);
}

void cVec_remove_object_by_argument(cVec* vec, void* arg) {
	if (!vec || vec->size == 0) {
		printf("Error: Vector is empty or NULL in cVec_remove_object_by_argument.\n");
		return;
	}

	for (int i = vec->size - 1; i >= 0; i--) {
		if (vec->DATA[i] == arg) {
			cVec_remove_object_by_index(vec, i);
		}
	}
}

void cVec_transfer(cVec* vec_dest, cVec* vec_source) {
	if (!vec_dest || !vec_source) {
		printf("Error: One or both vectors are NULL in cVec_transfer.\n");
		return;
	}

	size_t new_capacity = vec_dest->size + vec_source->size;
	void** new_data = realloc(vec_dest->DATA, new_capacity * sizeof(void*));
	if (!new_data) {
		printf("Error: Memory allocation failed in cVec_transfer.\n");
		return;
	}

	vec_dest->DATA = new_data;

	errno_t result = memcpy_s(vec_dest->DATA + vec_dest->size, (new_capacity - vec_dest->size) * sizeof(void*), vec_source->DATA, vec_source->size * sizeof(void*));

	if (result != 0) {
		printf("Error: memcpy_s failed in cVec_transfer with error code %d.\n", result);
		return;
	}

	vec_dest->size += vec_source->size;
}

void cVec_erase_transfer(cVec* vec_dest, cVec* vec_source) {
	if (!vec_dest || !vec_source) {
		printf("Error: One or both vectors are NULL in cVec_erase_transfer.\n");
		return;	
	}

	cVec_clear(vec_dest);

	size_t new_capacity = vec_source->size;
	void** new_data = realloc(vec_dest->DATA, new_capacity * sizeof(void*));
	if (!new_data) {
		printf("Error: Memory allocation failed in cVec_erase_transfer.\n");
		return;
	}

	vec_dest->DATA = new_data;

	errno_t result = memcpy_s(vec_dest->DATA + vec_dest->size, (new_capacity - vec_dest->size) * sizeof(void*), vec_source->DATA, vec_source->size * sizeof(void*));

	if (result != 0) {
		printf("Error: memcpy_s failed in cVec_erase_transfer with error code %d.\n", result);
		return;
	}
	vec_dest->size = vec_source->size;
}

void cVec_clear(cVec* vec) {
	free(vec->DATA);
	vec->DATA = NULL;
	vec->size = 0;
}

void cVec_resize(cVec* vec, size_t new_capacity) {
	if (!vec) {
		printf("Error: Vector is NULL in cVec_resize.\n");
		return;
	}

	if (new_capacity == vec->size) {
		return;
	}

	void** newData = realloc(vec->DATA, new_capacity * sizeof(void*));
	if (!newData) {
		printf("Error: Memory allocation failed in cVec_resize.\n");
		return;
	}

	if (new_capacity > vec->size) {
		for (size_t i = vec->size; i < new_capacity; ++i) {
			newData[i] = NULL;
		}
	}

	vec->DATA = newData;
	vec->size = new_capacity;
}