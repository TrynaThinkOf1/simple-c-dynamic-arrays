To use, simply download any or all of the .h files inside of headers/ and add them to your project.
They all only depend on the C standard library.

```
.
├── include
│   ├── dynamic_arrays
│   │   ├── 2DArrays.h
│   │   ├── IntArray.h
│	│	├── DoubleArray.h
│   │   └── String.h
│   ├── other
│   │   └── file.h
│   └── utils.h
└── src
    ├── file.c
    └── main.c
```


# TEST OUTPUT:

```
┏━━━━━━━━━━━━━━━━━━━━━━STRING TESTING━━━━━━━━━━━━━━━━━━━━━━┓
┃ CREATE ("Hello")           str: Hello | size: 5          ┃
┃ RESIZE (11)                str: Hello | size: 11         ┃
┃ APPEND STRING (", world")  str: Hello, worl | size: 11   ┃
┃ APPEND CHAR* ("d!")        str: Hello, world! | size: 13 ┃
┃ FIRST INDEX OF 'o'         idx: 4                        ┃
┃ LAST INDEX OF 'o'          idx: 8                        ┃
┃ SUBSTRING (7 - 12)         substr: world                 ┃
┃ RESIZE (4)                 str: Hell | size: 4           ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
┏━━━━━━━━━━━━━━━━━━━━━━━━━━INTARRAY TESTING━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃ CREATE            arr: [2, 3, 10, 20] | size: 4                    ┃
┃ RESIZE (6)        arr: [2, 3, 10, 20] | size: 6                    ┃
┃ APP. INTARRAY     arr: [2, 3, 10, 20, 30, 4] | size: 6             ┃
┃ APP. INT*         arr: [2, 3, 10, 20, 30, 4, 40, 5, 50] | size: 9  ┃
┃ FIRST IDX OF 4    idx: 5                                           ┃
┃ LAST IDX OF 60    idx: -1                                          ┃
┃ SUBSEQ. (2 - 6)   subseq: [10, 20, 30, 4] | size: 4                ┃
┃ RESIZE (3)        arr: [2, 3, 10] | size: 3                        ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━DOUBLEARRAY TESTING━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃ CREATE               arr: [1.000000, 1.414200, 3.141590] | size: 3                                          ┃
┃ RESIZE (5)           arr: [1.000000, 1.414200, 3.141590] | size: 5                                          ┃
┃ APP. DOUBLEARRAY     arr: [1.000000, 1.414200, 3.141590, 2.718280, 1.732100] | size: 5                      ┃
┃ APP. DOUBLE*         arr: [1.000000, 1.414200, 3.141590, 2.718280, 1.732100, 0.082100, 9.810000] | size: 7  ┃
┃ FIRST IDX OF 1.4142  idx: 1                                                                                 ┃
┃ LAST IDX OF 1.7321   idx: 4                                                                                 ┃
┃ SUBSEQ. (0 - 3)      subseq: [1.000000, 1.414200, 3.141590] | size: 3                                       ┃
┃ RESIZE (3)           arr: [1.000000, 1.414200, 3.141590] | size: 3                                          ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
```
