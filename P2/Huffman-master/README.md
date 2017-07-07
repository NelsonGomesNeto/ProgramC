# Data Structure (P2) Project

## Group:
### Nelson Gomes Neto
### Lucas Ribeiro Raggi
### França Mac Dowell da Silva Sales
<br />
## Huffman:
### Compiling:
In order to compile, **you will need a C compiler**
#### $ gcc main.c compressFile.c decompressFile.c huffTree.c list.c binaryOperations.c progressBar.c -o main**
### Using:
In order to use, **you will use arguments**
#### $ ./main <"-c" to compress or "-d" to decompress> <"file path">**
#### $ ./main <"-mc" to compress or "-md" to decompress multiple times> <**quantity**> <"file path">**
#### $ ./main <"-mm"> to maximally compress> <"file path">**
<br />
## CP with R:
We've compared heap and priority queue
In order to run tests, **you will need a C compiler, Rscript and okular (on Linux)** (you can change okular to any other PDF reader)
#### Linux: $ ./bashGenerateGraphs
#### Windows: $ generateGraphs.bat
(notice that you can treat any incompatibility of PDF reader by adjusting the scripts)
<br />
## CUnit to test a heap
### Compiling:
In order to compile, **you will need a C compiler and CUnit installed on Linux or Bash**
#### $ gcc CPcunitTest.c heap.c -o main -lcunit
### Testing:
In order to use, **you just need to run it**
#### $ ./main
<br />
## Topological Sort:
### Compiling:
In order to compile, **you will need a C compiler**
#### $ gcc topologicalSort.c graph.c queue.c stack.c -o main
### Using:
In order to use, **you just need to run it and input a graph**
#### $ ./main
<br />
<br />
### (We've tested on Windows, Linux and macOS)
