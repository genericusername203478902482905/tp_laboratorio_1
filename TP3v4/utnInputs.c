/*
 * utnInputs.c
 *
 *  Created on: Sep 24, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utnInputs.h"


int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos)
{
	int ret=0;
	int num;

	while(reintentos>0)
	{
		printf(mensaje);
		if(scanf("%d",&num)==1){
		if(num<=max && num>=min)
			{break;}
		}
		fflush(stdin);
		reintentos--;
		printf(mensajeError);
	}
	if(reintentos==0)
	{
		ret=-1;
	}
	else
	{
		ret=0;
		*pResultado = num;
	}
		return ret;
}

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max, int reintentos)
{
	int ret=0;
	float num;

	while(reintentos>0)
	{
		printf(mensaje);
		if(scanf("%f",&num)==1){
		if(num<=max && num>=min)
			{break;}
		}
		fflush(stdin);
		reintentos--;
		printf(mensajeError);
	}
	if(reintentos==0)
	{
		ret=-1;
	}
	else
	{
		ret=0;
		*pResultado = num;
	}
		return ret;
}


int utn_getString(char* input,char mensaje[],char mensajeError[],int min,int max,int reintentos)
{
    char nombre[51];
    char aux[256];
    int retorno=-1;
    int contReintentos=0;
    int respuestaValidar;
    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(aux);
        respuestaValidar = utn_valCharacter(aux,256);
        if(respuestaValidar == -1)
        {
        	contReintentos++;
            printf("%s",mensajeError);
        }
        else
        {
            if(strlen(aux) < min || strlen(aux) > max)
            {
                printf("%s",mensajeError);
                contReintentos++;
            }
            else
            {
                strcpy(nombre,aux);
                strcpy(input,nombre);
                retorno=0;
                break;
            }
        }

        if(contReintentos==reintentos)
        {
        	retorno=-1;
            printf("\nMaxima cantidad de intentos alcanzada.\n");
            system("pause");
        }

    }while(contReintentos!=reintentos);

    return retorno;

}

int utn_valCharacter(char* string,int max)
{
    int retorno=-1;

    if(string != NULL && max > 0 )
    {

        for(int i=0; i<max && string[i]!='\0'; i++)
        {
            if((string[i]<'a' || string[i]>'z') && (string[i]<' '|| string[i]>' ') && (string[i]<'A' || string[i]>'Z') )
            {
                break;
            }
            else
            {
                retorno=0;
            }
        }
    }

    return retorno;
}

int utn_charMenu(char* opcion,int max)
{
    int retorno=-1;

    if(opcion != NULL && max > 0 )
    {

        for(int i=0; i<max && opcion[i]!='\0'; i++)
        {
            if((opcion[i]<'a' || opcion[i]>'h') && (opcion[i]<' '|| opcion[i]>' ') && (opcion[i]<'A' || opcion[i]>'H') )
            {
                break;
            }
            else
            {
                retorno=0;
            }
        }
    }

    return retorno;
}

