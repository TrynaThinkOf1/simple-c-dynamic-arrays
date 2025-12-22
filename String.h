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
char* getStringData(String* str) {
	return str->__data;
}

size_t getStringSize(String* str) {
	return str->__size;
}

size_t getStringEnd(String* str) {
	return str->__end;
}
///


/// MODIFIERS ///
void resizeString(String* str, size_t new_size) {
	str->__size = new_size;
	str->__data = realloc(str->__data, str->__size);
}
/// ///


/// CONSTRUCTORS & DESTRUCTORS ///
String* createString(char* initial) {
	String* new_str = (String*)(malloc(sizeof(String)));
	new_str->__size = len(initial);
	new_str->__end = len(initial);

	resizeString(new_str, new_str->__size);

	for (int i = 0; i < new_str->__size; i++) {
		new_str->__data[i] = initial[i];
	}

	return new_str;
}

String* copyString(String* str) {
	return createString(str->__data);
}

//

void destroyString(String* str) {
	if (str->__size > 0) free(str->__data);
	str->__size = 0;
	str->__end = 0;

	free(str);
}
/// ///
