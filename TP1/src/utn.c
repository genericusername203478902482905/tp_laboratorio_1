/*
 * utn.c
 *
 *  Created on: Sep 10, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>

int menu(int* pResultado,char* mensaje, char* mensajeError, int min, int max, int reintentos, int* op1, int op1Check, int* op2, int op2Check)
{
	int ret;
	int num;
//	int mOp1;
//	int mOp2;
//	*op1=mOp1;
//	*op2=mOp2;
	while(reintentos>0)
	{

		if(op1Check == 0 && op2Check == 0){
		printf(mensaje);
		}
		else if (op1Check == 1 && op2Check == 0){
		printf(mensaje,*op1);
		}
		else if (op1Check == 0 && op2Check == 1){
		printf(mensaje,*op2);
		}
		else{
		printf(mensaje,*op1,*op2);
		}
		scanf("%d",&num);
		if(num<=max && num>=min)
		{break;}
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
