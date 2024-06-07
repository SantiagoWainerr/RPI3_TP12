#include <stdio.h>
#include "getData.h"

int getData(void){
	int count = 0;
	int c,d;
	while((c = getchar()) && (c != '\n')){
		count++;
		d = c;
	}

	if(count != 1){
		return DATO_ERR;

	}else{
		if((d >= '0' && d <= '7') || (d == 't') || (d == 'c') || (d == 's') || (d == 'q')){
			return d;

		}else{
			return DATO_ERR;

		}
	}
}
