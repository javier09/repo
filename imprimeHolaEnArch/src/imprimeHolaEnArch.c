/*
 ============================================================================
 Name        : imprimeHolaEnArch.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* arch;
	arch=fopen("arch","a+");
	fprintf(arch,"hola github"); /* prints !!!Hello World!!! */
	close(arch);
	return EXIT_SUCCESS;
}
