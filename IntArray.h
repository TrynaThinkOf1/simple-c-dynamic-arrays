#include <stdlib.h>
#include <limits.h>

/// NON-SPECIFIC UTILITIES ///
size_t intarr_len(int* arr) {
	size_t l = 0;
	while (*arr != INT_MAX) {
		arr++;
		l++;
	}
	return l;
}

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
/// ///


/// MODIFIERS ///
static void resizeIntArray(IntArray* arr, size_t new_size) {
	arr->__size = new_size;
	arr->__data = realloc(arr->__data, arr->__size);
}

static void intAppendIntArray(IntArray* arr, int* app) {
	size_t app_len = intarr_len(app);

	if (arr->__size < arr->__end + app_len) {
		resizeIntArray(arr, arr->__end + app_len);
	}

	for (size_t i = 0; i < app_len; i++) {
		arr->__data[arr->__end] = app[i];
		arr->__end++;
	}
}

static void intArrayAppendIntArray(IntArray* arr, IntArray* app) {
	intAppendIntArray(arr, app->__data);
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
static IntArray* createIntArray(int* initial) {
	IntArray* new_arr = (String*)(malloc(sizeof(String)));
	new_arr->__size = intarr_len(initial);
	new_arr->__end = intarr_len(initial);

	resizeIntArray(new_arr, new_arr->__size);

	for (size_t i = 0; i < new_arr->__size; i++) {
		new_arr->__data[i] = initial[i];
	}

	return new_arr;
}

static IntArray* copyIntArray(IntArray* arr) {
	return createIntArray(arr->__data);
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
