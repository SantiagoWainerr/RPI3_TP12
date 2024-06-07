#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hardware.h"

#define TAM_MAX 50

FILE * archivo;

char * mapeo[8] = {"17", "4", "19", "23", "24", "25", "22", "27"};

void inicialization (void){
	char numPin[TAM_MAX];
	char * exportar = "/sys/class/gpio/export";
	int i;
	for(i = 0; i < 8; i++){
		if ((archivo = fopen(exportar, "w")) == NULL){
			printf("No es posible exportar el gpio %s.\n", mapeo[i]);
			exit(1);
		}
		fprintf(archivo, mapeo[i]);
		fclose(archivo);

		if (snprintf(numPin, TAM_MAX, "/sys/class/gpio/gpio%s/direction", mapeo[i]) < 0){
			printf("ERROR: La direccion es erronea.\n");
			exit(1);
		}
		if((archivo = fopen(numPin, "w")) == NULL){
			printf("No es posible acceder al gpio %s.\n", mapeo[i]);
			exit(1);
		}
		if(fprintf(archivo,"out") == -1){
			printf("No ha sido posible establecer la direccion del gpio %s.", mapeo[i]);
			exit(1);
		}
		fclose(archivo);
		delay(0.5);
	}
}

void led_On (int led){
	char numPin[TAM_MAX];
	if (snprintf(numPin, TAM_MAX, "/sys/class/gpio/gpio%s/value", mapeo[led]) < 0){
		printf("ERROR: La direccion es erronea.\n");
		exit(1);
	}
	if((archivo = fopen(numPin, "w")) == NULL){
		printf("No es posible acceder al pin %s.\n", mapeo[led]);
		exit(1);
	}
	if(fputc('1', archivo) == -1){
		printf("No ha sido posible encender el led %d.", led);
		exit(1);
	}
	fclose(archivo);
}

void turnOn (void){
	int led;
	char numPin[TAM_MAX];
	for(led = 0; led < 8; led++){
		if (snprintf(numPin, TAM_MAX, "/sys/class/gpio/gpio%s/value", mapeo[led]) < 0){
			printf("ERROR: La direccion es erronea.\n");
			exit(1);
		}
		if((archivo = fopen(numPin, "w")) == NULL){
			printf("No es posible acceder al pin %s.\n", mapeo[led]);
			exit(1);
		}
		if(fputc('1', archivo) == -1){
			printf("No ha sido posible encender el led %d.", led);
			exit(1);
		}
		fclose(archivo);
	}
}

void turnOff (void){
	int led;
	char numPin[TAM_MAX];
	for(led = 0; led < 8; led++){
		if (snprintf(numPin, TAM_MAX, "/sys/class/gpio/gpio%s/value", mapeo[led]) < 0){
			printf("ERROR: La direccion es erronea.\n");
			exit(1);
		}
		if((archivo = fopen(numPin, "w")) == NULL){
			printf("No es posible acceder al pin %s.\n", mapeo[led]);
			exit(1);
		}
		if(fputc('0', archivo) == -1){
			printf("No ha sido posible apagar el led %d.", led);
			exit(1);
		}
		fclose(archivo);
	}
}

void toggle (void){
	int led;
	char numPin[TAM_MAX];
	FILE * copia;
	char * estado = " ";
	for(led = 0; led < 8; led++){
		if (snprintf(numPin, TAM_MAX, "/sys/class/gpio/gpio%s/value", mapeo[led]) < 0){
			printf("ERROR: La direccion es erronea.\n");
			exit(1);
		}
		if((archivo = fopen(numPin, "r+")) == NULL){
			printf("No es posible acceder al pin %s.\n", mapeo[led]);
			exit(1);
		}
		copia = archivo;

		fgets(estado, 1, copia);

		if(*estado == '1'){
			if(fputc('0', archivo) == -1){
				printf("No ha sido posible apagar el led %d.", led);
				exit(1);
			}
		}else{
			if(fputc('1', archivo) == -1){
				printf("No ha sido posible encender el led %d.", led);
				exit(1);
			}
		}
		fclose(archivo);
	}
}
