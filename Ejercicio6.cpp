/* Program Example 6: Event driven LED switching with switch debounce
 */
#include "mbed.h"
InterruptIn button(PTA1); // Interrupt on digital pushbutton input p18
DigitalOut led1(PTB0); // digital out to LED1
Timer debounce; // define debounce timer
void toggle(void); // function prototype
int main() {
 debounce.start();
 button.rise(&toggle); // attach the address of the toggle
 while(1){} // function to the rising edge
} 

void toggle() {
if (debounce.read_ms()>10) // only allow toggle if debounce timer
 led1=!led1; // has passed 10 ms
 debounce.reset(); // restart timer when the toggle is performed
}
