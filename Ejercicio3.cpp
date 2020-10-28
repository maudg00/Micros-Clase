#include "mbed.h"
Timer timer_fast; // define Timer with name "timer_fast"
Timer timer_slow; // define Timer with name "timer_slow"
DigitalOut ledA(PTB0);
DigitalOut ledB(PTB1);
void task_fast(void); //Prototipos de funciones
void task_slow(void);
int main() {
 timer_fast.start(); //start the Timers
 timer_slow.start();
 while (1){
 if (timer_fast.read()>0.2){ //test Timer value
 task_fast(); //call the task if trigger time is reached
 timer_fast.reset(); //and reset the Timer
 }
 if (timer_slow.read()>1){ //test Timer value
 task_slow();
 timer_slow.reset();
 }
 }
}
void task_fast(void){ //”Fast” Task
 ledA = !ledA;
}
void task_slow(void){ //”Slow” Task
 ledB = !ledB;
}
