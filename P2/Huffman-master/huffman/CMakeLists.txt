cmake_minimum_required(VERSION 3.7)
project(huffman)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        fotoIn.jpg
        huffTree.h
        list.c
        list.h
        main.c
        binaryOperations.c
        binaryOperations.h
        fileSetup.h
        huffTree.c)

add_executable(huffman ${SOURCE_FILES})