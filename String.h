#include <stdlib.h>

/// NON-SPECIFIC UTILITIES ///
size_t len(char* arr) {
	size_t l = 0;
	while (*arr != '\0') {
		arr++;
		l++;
	}
	return l;
}

/////////////////////
typedef struct {
	size_t __size;

	char* __data;

	size_t __end;
} String;
/////////////////////


/// GETTERS ///
static const char* getStringData(String* str) {
	return str->__data;
}

static size_t getStringSize(String* str) {
	return str->__size;
}

static size_t  getStringEnd(String* str) {
	return str->__end;
}
///


/// MODIFIERS ///
static void resizeString(String* str, size_t new_size) {
	str->__size = new_size;
	str->__data = realloc(str->__data, str->__size);
}

static void charAppendString(String* str, char* app) {
	size_t app_len = len(app);
	
	if (str->__size < str->__end + app_len) {
		resizeString(str, str->__end + app_len);
	}

	for (size_t i = 0; i < app_len; i++) {
		str->__data[str->__end] = app[i];
		str->__end++;
	}
}

static void stringAppendString(String* str, String* app) {
	charAppendString(str, app->__data);
}

static String* createSubstring(String* str, size_t begindex, size_t endex) {
	String* new_str = (String*)(malloc(sizeof(String)));
	new_str->__end = new_str->__size;

	resizeString(new_str, endex - begindex);

	size_t idx = 0;
	for (size_t i = begindex; i < endex; i++) {
		new_str->__data[idx] = str->__data[i];
		idx++;
	}

	return new_str;
}
/// ///


/// CONSTRUCTORS & DESTRUCTORS ///
static String* createString(char* initial) {
	String* new_str = (String*)(malloc(sizeof(String)));
	new_str->__size = len(initial);
	new_str->__end = len(initial);

	resizeString(new_str, new_str->__size);

	for (size_t i = 0; i < new_str->__size; i++) {
		new_str->__data[i] = initial[i];
	}

	return new_str;
}

static String* copyString(String* str) {
	return createString(str->__data);
}

//

static void destroyString(String* str) {
	if (str->__size > 0) free(str->__data);
	str->__size = 0;
	str->__end = 0;

	free(str);
}
/// ///
