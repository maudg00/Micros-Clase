#include "mbed.h"
Timer t; // Definir un Timer de librería timer.h
Serial pc(USBTX, USBRX);
int main() {
 t.start(); //Empezar timer
 pc.printf("Hello World!\n");
 t.stop(); //detener timer
 pc.printf("El tiempo fue de %f segundos\n", t.read()); //Imprimir
}
