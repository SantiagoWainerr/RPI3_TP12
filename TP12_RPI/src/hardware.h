
#ifndef SRC_HARDWARE_H_
#define SRC_HARDWARE_H_

void inicialization (void);
/*La función "inicialization" se encarga de exportar los gpios a utilizar y a su vez de setearlos como salida.*/
void led_On (int pin);
/*La función "led_On" se encargar de encender el número de led que recibe.*/
void turnOn (void);
/*"turnOn" enciende todos los leds.*/
void turnOff(void);
/*"turnOff" apaga todos los leds.*/
void toggle (void);
/*"toggle" es una función que se encarga de encender aquellos ledsque están apagados, y de apagar aquellos que están prendidos.*/

#endif
