#include <stdio.h>
#include "getData.h"
#include "hardware.h"
int main (void){
	inicialization();
	int c = DATO_ERR;
	while(c != 'q'){
		printf("Ingrese la operación que quiere realizar: ");
		while ((c = getData()) && c == DATO_ERR){
			printf("Dato inválido. Ingrese nuevamente: ");
		}
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
				break;
			default:				// SET_GPIOx
				led_On(c - '0');
		}
	}
	return 0;
}
