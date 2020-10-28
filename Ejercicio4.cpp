*Program Example 4: Demonstrates Timeout, by triggering an event a fixed
duration after a button press. */

#include "mbed.h"
Timeout Response; //create a Timeout, and name it "Response"
DigitalIn button (PTA1);
DigitalOut led1(PTB0); //blinks in time with main while(1) loop
DigitalOut led2(PTB1); //set high fixed period after button press
DigitalOut led3(PTB2); //goes high when button is pressed
void blink() { //this function is called at the end of the Timeout
 led2 = 1;
 wait(0.5);
 led2=0;
}
int main() {
 while(1) {
 if(button==1){
 Response.attach(&blink,2.0); //attach blink function to Response
 //Timeout, to occur after 2 seconds
 led3=1; //shows button has been pressed
 }
 else {
 led3=0;
 }
 led1=!led1;
 wait(0.2);
 }
}
