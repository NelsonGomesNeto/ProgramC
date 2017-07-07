#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Function: updateProgress
 * ----------------------------
 *   Updates the progress of a progess bar
 *
 *   string: char array (string) of wanted information about the progress bar
 *   porcentage: integer of the porcentage progress
 *   cleaning: boolean wheter you will keep refreshing it or it's just to print the progress
 *
 *   returns: nothing
 */
void updateProgress(char string[], int porcentage, bool cleaning);

/*
 * Function: createProgressBar
 * ----------------------------
 *   pFile: FILE* of the file to create a progress bar from
 *
 *   returns: long long int* of a size 100 array where each position is a the porcentage equivalent position inside the file
 */
long long int* createProgressBar(FILE *pFile);

#endif //PROGRESSBAR_H
