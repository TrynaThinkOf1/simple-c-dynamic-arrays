#include <stdio.h>

#include "String.h"

/////////////////////

int main() {
	/// STRING TESTING ///
	printf("┏━━━━━━━━━━━━━━━━━━━━━━STRING TESTING━━━━━━━━━━━━━━━━━━━━━━┓\n");
	
	String* str = createString("Hello");
	printf("┃ CREATE                     str: %s | size: %lu          ┃\n", getStringData(str), getStringSize(str));

	resizeString(str, 11);
	printf("┃ RESIZE (11)                str: %s | size: %lu         ┃\n", getStringData(str), getStringSize(str));

	String* toApp = createString(", worl");
	stringAppendString(str, toApp);
	destroyString(toApp);
	printf("┃ APPEND STRING (\", world\")  str: %s | size: %lu   ┃\n", getStringData(str), getStringSize(str));

	charAppendString(str, "d!");
	printf("┃ APPEND CHAR* (\"d!\")        str: %s | size: %lu ┃\n", getStringData(str), getStringSize(str));

	String* substr = createSubstring(str, 7, 12);
	printf("┃ SUBSTRING (7 - 12)         substr: %s                 ┃\n", getStringData(substr));
	destroyString(substr);

	resizeString(str, 4);
	printf("┃ RESIZE (4)                 str: %s | size: %lu           ┃\n", getStringData(str), getStringSize(str));

	destroyString(str);
	
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	/// ///

	return 0;
}
