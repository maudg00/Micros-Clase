/* Program Example 5: Simple demo of "Ticker". Replicates behaviour of
first led flashing program.
*/
#include "mbed.h"
void led_switch(void);
Ticker time_up; //define a Ticker, with name “time_up”
DigitalOut myled(LED1);
void led_switch(){ //the function that Ticker will call
 myled=!myled;
}
int main(){
 time_up.attach(&led_switch, 0.2); //initialises the ticker
 while(1){ //sit in a loop doing nothing, waiting for
//Ticker interrupt
 }
}
