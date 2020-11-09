/*
 * TP3input.c
 *
 *  Created on: Nov 7, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP3input.h"



/* ENTRADA DE DATOS */

void getInt(int* puntero){
    int num;
    scanf("%d",&num);
    *puntero = num;
}

void getFloat(float* puntero){
    float num;
    scanf ("%f",&num);
    *puntero = num;
}

void getChar(char* mensaje){
    char letra;
    fflush(stdin);
    scanf("%c",&letra);
    *mensaje = letra;

}

int getString(char* input){
scanf("%s",input);
return 0;
}


