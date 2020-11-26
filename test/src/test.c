/*
 ============================================================================
 Name        : test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float num=10;
	float *pNum = malloc(sizeof(float));
	*pNum = 2*num;
	free(pNum);
	printf("%f",num);

	return EXIT_SUCCESS;
}
