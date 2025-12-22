#include <stdio.h>

#include "String.h"

/////////////////////

int main() {
	/// STRING TESTING ///
	String* str = createString("Hello");
	printf("str: %s, size: %lu\n", getStringData(str), getStringSize(str));

	destroyString(str);
	/// ///

	return 0;
}
