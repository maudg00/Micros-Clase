#include "mbed.h"
Serial pc(USBTX, USBRX);
Ticker ticker;
InterruptIn interrupt(PTA1);
DigitalIn botonIncrementarEspera(PTA2);
DigitalIn botonPrenderLED(PTD4);
DigitalOut Led1(PTB0);
DigitalOut Led2(PTB1);
Timer t;
Timeout timeout;
void ensenarTiempo()
{
    pc.printf("El tiempo transcurrido es %f.\n", t.read());
}
void prenderLED1()
{
    Led1=1;
}
void prenderLED2()
{
    Led2=1;
}
int main() {
    int espera=1;
    t.start();
    interrupt.rise(&ensenarTiempo);
    ticker.attach(&prenderLED2, 0.5);
    while(1)
     {
        if(botonIncrementarEspera==1)
        {
            espera++;
        }
        if(botonPrenderLED==1)
        {
            timeout.attach(&prenderLED1, espera);
        }
        wait(0.2);
    }
}
