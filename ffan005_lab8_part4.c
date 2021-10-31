/*      Author: ffan005
 *  Partner(s) Name: 
 *      Lab Section:
 *      Assignment: Lab #  Exercise #
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 *      Demo: https://www.youtube.com/shorts/Zdr6xMpz10w
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

//unsigned short x = ADC;

void ADC_init(){
ADCSRA |= (1 <<  ADEN) | (1 << ADSC) | (1 << ADATE);
}

/*
 adjusted max value to 256, 767 give werid error :P
 0 => 0x01
 1 => 0x02
 2 => 0x04
 3 => 0x08
 4 => 0x10
 5 => 0x20
 6 => 0x40
 7 => 0x80
 */

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;

    ADC_init();

    while (1) {
        unsigned short x = ADC;
        unsigned char PB = (char)x;

        if (PB <= (32)) {
          PORTB = 0x01;
        }
        else if (PB <= (64)) {
          PORTB = 0x02;
        }
        else if (PB <= (96)) {
          PORTB = 0x04;
        }
        else if (PB <= (128)) {
          PORTB = 0x08;
        }
        else if (PB <= (160)) {
          PORTB = 0x10;
        }
        else if (PB <= (192)) {
          PORTB = 0x20;
        }
        else if (PB <= (224)) {
          PORTB = 0x40;
        }
        else if (PB > 224) {
          PORTB = 0x80;
        }
    }
    return 0;
}

