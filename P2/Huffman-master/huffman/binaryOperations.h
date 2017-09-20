#ifndef BINARYOPERATIONS_H
#define BINARYOPERATIONS_H
#include <stdio.h>
#include <stdbool.h>

/*
 * Function: setBit
 * ----------------------------
 *   byte: unsigned integer to set
 *   i: position to set
 *
 *   returns: unsigned integer with i position setted
 */
unsigned int setBit(unsigned int byte, int i);

/*
 * Function: isBitiSet
 * ----------------------------
 *   byte: unsigned integer to check
 *   i: integer position to check
 *
 *   returns: boolean wheter i position in a unsigned int is setted or not
 */
bool isBitiSet(unsigned int byte, int i);

/*
 * Function: printByte
 * ----------------------------
 *   Bit a bit prints a unsigned integer of a given size
 *
 *   byte: unsigned integer to print
 *   size: size to print
 *
 *   returns: nothing
 */
void printByte(unsigned int byte, int size);

#endif //BINARYOPERATIONS_H
