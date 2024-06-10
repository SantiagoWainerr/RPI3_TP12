#include <stdio.h>
#include "getData.h"
#include "hardware.h"
int main (void){
	// Inicializamos los gpios como salida
	inicialization();
	int c = DATO_ERR;

	// Llamamos a la función getData() y evaluamos que el caracter ingresado no sea una 'q'. Si es una 'q', entonces el programa debe terminar.
	while(c != 'q'){
		printf("Ingrese la operación que quiere realizar: ");
		while ((c = getData()) && c == DATO_ERR){
			printf("Dato inválido. Ingrese nuevamente: ");
		}
		// Utilizamos un switch para evaluar el caracter que se ingresó y en base al caracter, que se realice una tarea específica. 
		switch(c){
			case 't':				// TOGGLE_ALL
				toggle();
				break;
			case 's':				// SET_ALL
				turnOn();
				break;
			case 'c':				// CLEAR_ALL
				turnOff();
				break;
			case 'q':
				turnOff();
				break;
			default:				// SET_GPIOx
				led_On(c - '0');
		}
	}
	return 0;
}
