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

int menuInformes(){
    int opcion;
    printf ("*******Menu Informes******\n");
    printf ("\n2- Ingrese dos para imprimir el promedio y total de juegos alquilados");
    printf ("\n3- Ingrese tres para imprimir los juegos por importe");
    printf ("\n\nIngrese el numero: ");
    getInt(&opcion);
    return opcion;
}

int menuPrincipal(){
    int opcion;
    printf ("*******Menu Inicial******\n");
    printf ("\n1- Ingrese uno para acceder al menu de juegos");
    printf ("\n2- Ingrese dos para acceder al menu de clientes");
    printf ("\n3- Ingrese tres para dar de alta un alquiler");
    printf ("\n4- Ingrese cinco para acceder al menu de informes");
    printf ("\n\nIngrese el numero: ");
    getInt(&opcion);
    return opcion;
}

/**************ENTRADA DE DATOS*****************/

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

/**************VALIDACION DE DATOS*****************/

int esNumerico(char str[]){
    int i=0;
    while(str[i] != '\0' ){
        if(str[i]<'0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[]){
    int i=0;
    while(str[i] != '\0'){
        if ((str[i] != ' ') &&
            (str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z')){
            return 0;}
        i++;
    }
    return 1;
}

int esAlfaNumerico(char str[]){
    int i=0;
     while(str[i] != '\0'){
        if ((str[i] != ' ') &&
            (str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' || str[i] > '9'))
        return 0;
    }
    return 1;
}

int esTelefono(char str[]){
    int i = 0;
    int contadorGuiones = 0;
    while (str[i] != '\0'){
        if ((str[i] != ' ') && (str[i] != '-') &&
            (str[i] < '0' || str[i] > '9')){
            return 0;}
        if (str[i] == '-'){
            contadorGuiones++;
        }
        i++;
    }
    if (contadorGuiones==1){
        return 1;
    }
    return 0;
}

int getSringLetras(char input[]){
    char aux[256];
    getString(aux);
    if (esSoloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
