/*
 ============================================================================
 Name        : TP1.c

 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir

 • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.

 • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
 (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

 • Deberán contemplarse los casos de error (división por cero, etc)

 • Documentar todas las funciones


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);

	int op1 = 0;
	int op2 = 0;

	int respuestaSuma;
	int resultadoSuma;

	int respuestaResta;
	int resultadoResta;

	int respuestaDivision;
	float resultadoDiv;

	int respuestaMultiplicacion;
	int resultadoMult;

	long int respuestaFactorial1;
	long int respuestaFactorial2;

	int x;
	char z;
	char t;

	int calcCheck = 0;
	int op1Check = 0;
	int op2Check = 0;

	do {
//para mostrar los operandos en el menu principal use If-Else con chequeos de operandos
		if (op1Check == 0 && op2Check == 0) {
			printf("\n------------------------------------"
					"\n Seleccione su opcion:\n"
					"1. Ingresar 1er operando \n"
					"2. Ingresar 2do operando \n"
					"3. Calcular todas las operaciones\n"
					"4. Informar resultados\n"
					"5. Salir\n\n");
		} else if (op1Check == 1 && op2Check == 0) {
			printf("\n------------------------------------"
					"\n Seleccione su opcion:\n"
					"1. Ingresar 1er operando (A=%d)\n"
					"2. Ingresar 2do operando \n"
					"3. Calcular todas las operaciones\n"
					"4. Informar resultados\n"
					"5. Salir\n\n", op1);
		} else if (op1Check == 0 && op2Check == 1) {
			printf("\n------------------------------------"
					"\n Seleccione su opcion:\n"
					"1. Ingresar 1er operando \n"
					"2. Ingresar 2do operando (B=%d)\n"
					"3. Calcular todas las operaciones\n"
					"4. Informar resultados\n"
					"5. Salir\n\n", op2);
		} else {
			printf("\n------------------------------------"
					"\n Seleccione su opcion:\n"
					"1. Ingresar 1er operando (A=%d)\n"
					"2. Ingresar 2do operando (B=%d)\n"
					"3. Calcular todas las operaciones\n"
					"4. Informar resultados\n"
					"5. Salir\n\n", op1, op2);
		}
		if (scanf("%d", &x) == 1) {

			switch (x) {
			case 1:

				printf("\nIngresar 1er operando: ");
				if (scanf("%d", &op1) == 1) {
					op1Check = 1;
				} else {
					printf("\nDebe ingresar un operando valido.");
				}

				break;
			case 2:

				printf("\nIngresar 2do operando: ");
				if (scanf("%d", &op2) == 1) {
					op2Check = 1;
				} else {
					printf("\nDebe ingresar un operando valido.");
				}

				break;

			case 3: //Calcular operaciones

				if (op1Check == 1 && op2Check == 1) {

					printf("\nDesea calcular las siguientes operaciones?\n"
							"Calcular la suma (%d+%d)\n"
							"Calcular la resta (%d-%d)\n"
							"Calcular la division (%d/%d)\n"
							"Calcular la multiplicacion (%d*%d)\n"
							"Calcular el factorial de %d y de %d\n"
							"(s/n)\n\n", op1, op2, op1, op2, op1, op2, op1, op2,
							op1, op2);

					fflush(stdin);
					scanf("%c", &z);

					if (z != 's') {
						z = 'n';
					}

					if (z == 's') {
						calcCheck = 1;

						respuestaSuma = sumar(&resultadoSuma, op1, op2);

						respuestaResta = restar(&resultadoResta, op1, op2);

						respuestaDivision = dividir(&resultadoDiv, op1, op2);

						respuestaMultiplicacion = multiplicar(&resultadoMult,
								op1, op2);

						respuestaFactorial1 = factorial(op1);
						respuestaFactorial2 = factorial(op2);

						printf("\n\nOperaciones calculadas.");
					}

				} else {
					printf("\n\nDebe ingresar ambos operandos para calcular.");
				}

				break;

			case 4: //mostrar resultados

				if (calcCheck == 0) {
					printf("\n\nDebe calcular antes de mostrar resultados.");
				} else {

					//suma
					if (respuestaSuma == 0) {
						printf("\n\nEl resultado de %d+%d es: %d", op1, op2,
								resultadoSuma);
					} else {
						printf("\n\nERROR EN LA SUMA");
					}

					//resta
					if (respuestaResta == 0) {
						printf("\n\nEl resultado de %d-%d es: %d", op1, op2,
								resultadoResta);
					} else {
						printf("\n\nERROR EN LA RESTA");
					}

					//division
					if (respuestaDivision == 0) {

						printf("\n\nEl resultado de %d/%d es: %.2f", op1, op2,
								resultadoDiv);
					} else {
						printf("\n\nNo es posible dividir por 0.");
					}

					//multiplicacion
					if (respuestaMultiplicacion == 0) {
						printf("\n\nEl resultado de %d*%d es: %d", op1, op2,
								resultadoMult);
					} else {
						printf("\n\nERROR EN LA MULTIPLICACION");
					}

					//factorial
					if (respuestaFactorial1 == 1 && op1 != 1 && op1 != 0) {
						printf(
								"\n\nNo es posible sacar el factorial de numeros negativos (%d).",
								op1);
					} else {
						printf("\n\nEl factorial de %d es: %ld", op1,
								respuestaFactorial1);
					}

					if (respuestaFactorial2 == 1 && op2 != 1 && op2 != 0) {
						printf(
								"\n\nNo es posible sacar el factorial de numeros negativos (%d).",
								op2);
					} else {
						printf("\n\nEl factorial de %d es: %ld", op2,
								respuestaFactorial2);
					}

				}

				break;

			case 5: //salir
				printf("\nEsta seguro que desea salir? (s/n)\n");

				fflush(stdin);
				scanf("%c", &t);

				if (t != 's') {
					x = 6;
				}

				break;

			case 6:
				break;

			default:
				printf("\nSeleccione una opcion valida.\n");
				break;
			}
			fflush(stdin);
		} else {
			fflush(stdin);
			printf("\nSeleccione una opcion valida.\n"); //si ingresa un caracter en vez de un numero muestra esto
		}

	} while (x != 5);

	return EXIT_SUCCESS;
}

