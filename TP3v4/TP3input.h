/*
 * TP3input.h
 *
 *  Created on: Nov 7, 2020
 *      Author: david
 */

#ifndef TP3INPUT_H_
#define TP3INPUT_H_

void getInt(int* puntero);
void getFloat(float* puntero);
void getChar(char* mensaje);
int getString(char* input);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
int getSringLetras(char input[]);
int menuPrincipal();
int menuInformes();


#endif /* TP3INPUT_H_ */
