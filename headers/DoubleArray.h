#include <stdlib.h>
#include <float.h>
#include <stdbool.h>

/////////////////////
typedef struct {
	size_t __size;
	size_t __end;

	double* __data;
} DoubleArray;
/////////////////////

/// GETTERS ///
static const double* getDoubleArrayData(DoubleArray* arr) {
	return arr->__data;
}

static size_t getDoubleArraySize(DoubleArray* arr) {
	return arr->__size;
}

static size_t getDoubleArrayEnd(DoubleArray* arr) {
	return arr->__end;
}

double doubleArrayAt(DoubleArray* arr, size_t idx) {
	if (idx < 0 || idx >= arr->__end) {
		return -DBL_MAX;
	}
	return arr->__data[idx];
}

ssize_t doubleArrayFirstIndexOf(DoubleArray* arr, double to_find) {
	for	(size_t i = 0; i < arr->__end; i++) {
		if (arr->__data[i] == to_find) return i;
	}
	return -1;
}
ssize_t doubleArrayLastIndexOf(DoubleArray* arr, double to_find) {
	// ssize_t -- needs to be signed or the loop is infinite
	for (ssize_t i = arr->__end - 1; i >= 0; i--) {
		if (arr->__data[i] == to_find) return i;
	}
	return -1;
}
/// ///


/// MODIFIERS ///
static void resizeDoubleArray(DoubleArray* arr, size_t new_size) {
	if (new_size < arr->__size) arr->__end = new_size;
	arr->__size = new_size;
	arr->__data = realloc(arr->__data, arr->__size * sizeof(double));
}

static void doubleAppendDoubleArray(DoubleArray* arr, double* app, size_t app_len) {
	if (arr->__size < arr->__end + app_len) {
		resizeDoubleArray(arr, arr->__end + app_len);
	}

	for (size_t i = 0; i < app_len; i++) {
		arr->__data[arr->__end] = app[i];
		arr->__end++;
	}
}

static void doubleArrayAppendDoubleArray(DoubleArray* arr, DoubleArray* app) {
	doubleAppendDoubleArray(arr, app->__data, app->__end);
}

static DoubleArray* createDoubleArraySubsequence(DoubleArray* arr, size_t begindex, size_t endex) {
	DoubleArray* new_arr = (DoubleArray*)(malloc(sizeof(DoubleArray)));

	resizeDoubleArray(new_arr, endex - begindex);

	new_arr->__end = 0;
	for (size_t i = begindex; i < endex; i++) {
		new_arr->__data[new_arr->__end] = arr->__data[i];
		new_arr->__end++;
	}

	return new_arr;
}
/// ///


/// CONSTRUCTORS & DESTRUCTORS ///
static DoubleArray* createDoubleArray(double* initial, double initial_length) {
	DoubleArray* new_arr = (DoubleArray*)(malloc(sizeof(DoubleArray)));
	new_arr->__size = initial_length;
	new_arr->__end = initial_length;

	resizeDoubleArray(new_arr, new_arr->__size);

	for (size_t i = 0; i < new_arr->__size; i++) {
		new_arr->__data[i] = initial[i];
	}

	return new_arr;
}

static DoubleArray* copyDoubleArray(DoubleArray* arr) {
	return createDoubleArray(arr->__data, arr->__end);
}

//

static void destroyDoubleArray(DoubleArray* arr) {
	if (arr->__size > 0) free(arr->__data);
	arr->__size = 0;
	arr->__end = 0;

	free(arr);
}
/// ///

bool compareDoubleArrays(DoubleArray* a, DoubleArray* b) {
	size_t len = (a->__end <= b->__end ? a->__end : b->__end);
	
	for (int i = 0; i < len; i++) {
		if (a->__data[i] != b->__data[i]) return false;
	}

	return true;
}
