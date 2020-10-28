/* Ejemplo 1: Sencillo ejemplo de interrupciones. Input externa causa interrupción mientras led parpadea

*/
#include "mbed.h"
InterruptIn button(PTA1); //Nombre del InterruptIn
DigitalOut led(PTB0);
DigitalOut flash(PTB1);

void ISR1() { //ISR, es decir, la respuesta a la interrupción
  led = !led; 
}

int main() {
 button.rise(&ISR1); // Vincular dirección del ISR en el flanco de subida
 while(1) {
  flash = !flash;
  wait(0.25);
 }
}
