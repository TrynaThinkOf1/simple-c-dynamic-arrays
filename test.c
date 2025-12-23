#include <stdio.h>

#include "headers/String.h"
#include "headers/IntArray.h"
#include "headers/DoubleArray.h"

/////////////////////
void printIntArray(IntArray* arr) {
	printf("[");
	for (size_t i = 0; i < getIntArrayEnd(arr) - 1; i++) {
		printf("%d, ", intArrayAt(arr, i));
	}
	printf("%d]", intArrayAt(arr, getIntArrayEnd(arr) - 1));
}
void printDoubleArray(DoubleArray* arr) {
	printf("[");
	for (size_t i = 0; i < getDoubleArrayEnd(arr) - 1; i++) {
		printf("%lf, ", doubleArrayAt(arr, i));
	}
	printf("%lf]", doubleArrayAt(arr, getDoubleArrayEnd(arr) - 1));
}
/////////////////////

int main() {
	{
	/// STRING REGIMENT ///
	printf("┏━━━━━━━━━━━━━━━━━━━━━━STRING TESTING━━━━━━━━━━━━━━━━━━━━━━┓\n");
	
	String* str = createString("Hello");
	printf("┃ CREATE (\"Hello\")           str: %s | size: %lu          ┃\n", getStringData(str), getStringSize(str));

	resizeString(str, 11);
	printf("┃ RESIZE (11)                str: %s | size: %lu         ┃\n", getStringData(str), getStringSize(str));

	String* toApp = createString(", worl");
	stringAppendString(str, toApp);
	destroyString(toApp);
	printf("┃ APPEND STRING (\", world\")  str: %s | size: %lu   ┃\n", getStringData(str), getStringSize(str));

	charAppendString(str, "d!");
	printf("┃ APPEND CHAR* (\"d!\")        str: %s | size: %lu ┃\n", getStringData(str), getStringSize(str));

	ssize_t fidx = stringFirstIndexOf(str, 'o');
	printf("┃ FIRST INDEX OF 'o'         idx: %zd                        ┃\n", fidx);
	
	ssize_t lidx = stringLastIndexOf(str, 'o');
	printf("┃ LAST INDEX OF 'o'          idx: %zd                        ┃\n", lidx);

	String* substr = createSubstring(str, 7, 12);
	printf("┃ SUBSTRING (7 - 12)         substr: %s                 ┃\n", getStringData(substr));
	destroyString(substr);

	resizeString(str, 4);
	printf("┃ RESIZE (4)                 str: %s | size: %lu           ┃\n", getStringData(str), getStringSize(str));

	destroyString(str);
	
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	/// ///
	}


	{
	/// INTARRAY REGIMENT ///
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━INTARRAY TESTING━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

	IntArray* arr = createIntArray((int[]){2, 3, 10, 20}, 4);
	printf("┃ CREATE            arr: ");
	printIntArray(arr);
	printf(" | size: %lu                    ┃\n", getIntArraySize(arr));

	resizeIntArray(arr, 6);
	printf("┃ RESIZE (6)        arr: ");
	printIntArray(arr);
	printf(" | size: %lu                    ┃\n", getIntArraySize(arr));

	IntArray* toApp = createIntArray((int[]){30, 4}, 2);
	intArrayAppendIntArray(arr, toApp);
	destroyIntArray(toApp);
	printf("┃ APP. INTARRAY     arr: ");
	printIntArray(arr);
	printf(" | size: %lu             ┃\n", getIntArraySize(arr));

	intAppendIntArray(arr, (int[]){40, 5, 50}, 3);
	printf("┃ APP. INT*         arr: ");
	printIntArray(arr);
	printf(" | size: %lu  ┃\n", getIntArraySize(arr));

	ssize_t fidx = intArrayFirstIndexOf(arr, 4);
	printf("┃ FIRST IDX OF 4    idx: %zd                                           ┃\n", fidx);

	ssize_t lidx = intArrayLastIndexOf(arr, 60);
	printf("┃ LAST IDX OF 60    idx: %zd                                          ┃\n", lidx);

	IntArray* subseq = createIntArraySubsequence(arr, 2, 6);
	printf("┃ SUBSEQ. (2 - 6)   subseq: ");
	printIntArray(subseq);
	printf(" | size: %lu                ┃\n", getIntArraySize(subseq));
	destroyIntArray(subseq);

	resizeIntArray(arr, 3);
	printf("┃ RESIZE (3)        arr: ");
	printIntArray(arr);
	printf(" | size: %lu                        ┃\n", getIntArraySize(arr));

	destroyIntArray(arr);

	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	/// ///
	}


	{
	/// DOUBLEARRAY REGIMENT ///
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━DOUBLEARRAY TESTING━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

	DoubleArray* arr = createDoubleArray((double[]){1.0, 1.4142, 3.14159}, 3);
	printf("┃ CREATE               arr: ");
	printDoubleArray(arr);
	printf(" | size: %lu                                          ┃\n", getDoubleArraySize(arr));

	resizeDoubleArray(arr, 5);
	printf("┃ RESIZE (5)           arr: ");
	printDoubleArray(arr);
	printf(" | size: %lu                                          ┃\n", getDoubleArraySize(arr));

	DoubleArray* toApp = createDoubleArray((double[]){2.71828, 1.7321}, 2);
	doubleArrayAppendDoubleArray(arr, toApp);
	destroyDoubleArray(toApp);
	printf("┃ APP. DOUBLEARRAY     arr: ");
	printDoubleArray(arr);
	printf(" | size: %lu                      ┃\n", getDoubleArraySize(arr));

	doubleAppendDoubleArray(arr, (double[]){0.0821, 9.81}, 2);
	printf("┃ APP. DOUBLE*         arr: ");
	printDoubleArray(arr);
	printf(" | size: %lu  ┃\n", getDoubleArraySize(arr));

	ssize_t fidx = doubleArrayFirstIndexOf(arr, 1.4142);
	printf("┃ FIRST IDX OF 1.4142  idx: %zd                                                                                 ┃\n", fidx);

	ssize_t lidx = doubleArrayLastIndexOf(arr, 1.7321);
	printf("┃ LAST IDX OF 1.7321   idx: %zd                                                                                 ┃\n", lidx);

	DoubleArray* subseq = createDoubleArraySubsequence(arr, 0, 3);
	printf("┃ SUBSEQ. (0 - 3)      subseq: ");
	printDoubleArray(subseq);
	printf(" | size: %lu                                       ┃\n", getDoubleArraySize(subseq));
	destroyDoubleArray(subseq);

	resizeDoubleArray(arr, 3);
	printf("┃ RESIZE (3)           arr: ");
	printDoubleArray(arr);
	printf(" | size: %lu                                          ┃\n", getDoubleArraySize(arr));

	destroyDoubleArray(arr);

	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	/// ///
	}

	return 0;
}
