#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/////////////////////
typedef struct {
	size_t __size;
	size_t __end;

	int* __data;
} IntArray;
/////////////////////


/// GETTERS ///
static const int* getIntArrayData(IntArray* arr) {
	return arr->__data;
}

static size_t getIntArraySize(IntArray* arr) {
	return arr->__size;
}

static size_t getIntArrayEnd(IntArray* arr) {
	return arr->__end;
}

int intArrayAt(IntArray* arr, size_t idx) {
	if (idx < 0 || idx >= arr->__end) {
		return INT_MIN;
	}
	return arr->__data[idx];
}

ssize_t intArrayFirstIndexOf(IntArray* arr, int to_find) {
	for	(int i = 0; i < arr->__end; i++) {
		if (arr->__data[i] == to_find) return i;
	}
	return -1;
}
ssize_t intArrayLastIndexOf(IntArray* arr, int to_find) {
	for (int i = arr->__end - 1; i >= 0; i--) {
		if (arr->__data[i] == to_find) return i;
	}
	return -1;
}
/// ///


/// MODIFIERS ///
static void resizeIntArray(IntArray* arr, size_t new_size) {
	if (new_size < arr->__size) arr->__end = new_size;
	arr->__size = new_size;
	arr->__data = realloc(arr->__data, arr->__size * sizeof(int));
}

static void intAppendIntArray(IntArray* arr, int* app, int app_len) {
	if (arr->__size < arr->__end + app_len) {
		resizeIntArray(arr, arr->__end + app_len);
	}

	for (size_t i = 0; i < app_len; i++) {
		arr->__data[arr->__end] = app[i];
		arr->__end++;
	}
}

static void intArrayAppendIntArray(IntArray* arr, IntArray* app) {
	intAppendIntArray(arr, app->__data, app->__end);
}

static IntArray* createSubsequence(IntArray* arr, size_t begindex, size_t endex) {
	IntArray* new_arr = (IntArray*)(malloc(sizeof(IntArray)));

	resizeIntArray(new_arr, endex - begindex);

	new_arr->__end = 0;
	for (size_t i = begindex; i < endex; i++) {
		new_arr->__data[new_arr->__end] = arr->__data[i];
		new_arr->__end++;
	}

	return new_arr;
}
///


/// CONSTRUCTORS & DESTRUCTORS ///
static IntArray* createIntArray(int* initial, int initial_length) {
	IntArray* new_arr = (IntArray*)(malloc(sizeof(IntArray)));
	new_arr->__size = initial_length;
	new_arr->__end = initial_length;

	resizeIntArray(new_arr, new_arr->__size);

	for (size_t i = 0; i < new_arr->__size; i++) {
		new_arr->__data[i] = initial[i];
	}

	return new_arr;
}

static IntArray* copyIntArray(IntArray* arr) {
	return createIntArray(arr->__data, arr->__end);
}

//

static void destroyIntArray(IntArray* arr) {
	if (arr->__size > 0) free(arr->__data);
	arr->__size = 0;
	arr->__end = 0;

	free(arr);
}
/// ///

bool compareIntArrays(IntArray* a, IntArray* b) {
	size_t len = (a->__end <= b->__end ? a->__end : b->__end);
	
	for (int i = 0; i < len; i++) {
		if (a->__data[i] != b->__data[i]) return false;
	}

	return true;
}
