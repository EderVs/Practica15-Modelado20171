#ifndef MAIN_H // Guarda para evitar include circulares
#define MAIN_H
/* ------ Se hacen todos los includes necesarios ------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ------ Definición de tus estructuras ------ */

/* ------ Definición de tus funciones ------ */

/*Imprime las instrucciones de uso del programa*/
void imprime_instrucciones();

void escribir_palabra_mas_repetida(
	const char* in_filename, const char* out_filename
);

#endif //MAIN_H
