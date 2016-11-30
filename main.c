#include "main.h"
// No hagas #include aquí, hazlos en main.h

int main(int argc, char const *argv[])
{
    // Verifica si hay al menos de 3 parametros
    // sino entonces se imprimen las instrucciones
    // y se para la ejecución del programa
    if (argc < 3) {
        imprime_instrucciones();
        return 0;
	}

	int i;
	FILE *archivo = fopen(argv[argc-1], "a+");
	printf("Nombre del archivo\tPalabra más repetida\tNúmero de repeticiones\n");
    fputs("Nombre del archivo\tPalabra más repetida\tNúmero de repeticiones\n", archivo);
    fclose(archivo);
	for (i = 1; i < argc-1; i++) {
		escribir_palabra_mas_repetida(argv[i], argv[argc-1]);
	}
	printf("Se guardó el resultado en el archivo %s\n", argv[argc-1]);
    return 0;
}

/* ------ Aquí va la implementación de tus funciones ------ */
void imprime_instrucciones() {
	printf("Error: El formato de entrada es incorrecto\n");
	printf("Uso: cuenta_palabras <archivo> [<archivo> [<archivo> ...]] <archivo>\n");
}

void escribir_palabra_mas_repetida(
	const char* in_filename, const char* out_filename
) {
	/* Encuentra la palabra mas repetida en in_filename, la imprime y
	 * la escribe en out_filename
	 *
	 * const char* in_filename; Archivo de donde se leera la entrada.
	 * const char* out_filename; Archivo en donde se escribira la salida.
	 *
	 * */
    char buffer[200];
    int i, j, num_palabras = 0, repeticiones, mayor_id, mayor = 0;
    char copia[200];
	char palabras[10000][200];
    char* token_actual;
    FILE *archivo = fopen(in_filename, "a+");
    FILE *archivo_salida = fopen(out_filename, "a+");

    fseek (archivo, 0, SEEK_SET);

    for(i = 0; fgets(buffer, 100, archivo) != NULL; i++) {
		memcpy(copia, buffer, sizeof(char)*200);
		token_actual = strtok(copia, " ,.-");
		while(token_actual != NULL) {
			num_palabras += 1;
			strcpy(palabras[num_palabras-1], token_actual);
			token_actual = strtok (NULL, " ,.-");
		}
    }
    for (i = 0; i < num_palabras; i++) {
		repeticiones = 1;
		for (j = i+1; j < num_palabras; j++) {
			if (strcmp(palabras[i], palabras[j]) == 0) {
				repeticiones += 1;
				if (mayor < repeticiones) {
					mayor = repeticiones;
					mayor_id = i;
				}
			}
		}
	}
	char salida[200];
	sprintf(salida, "%s\t\t\t%s\t\t\t%d\n", in_filename, palabras[mayor_id], mayor);
	printf(salida);
    fputs(salida, archivo_salida);
    fclose(archivo);
    fclose(archivo_salida);
	
}
