/*      Author: ffan005
 *  Partner(s) Name: 
 *      Lab Section:
 *      Assignment: Lab #  Exercise #
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 *      Demo:
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
 0 => 0x00
 1 => 0x01
 2 => 0x02
 3 => 0x04
 4 => 0x08
 5 => 0x10
 6 => 0x20
 7 => 0x40
 */

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;

 //   unsigned char output = 0x00;

    ADC_init();

    while(1){
    unsigned short x = ADC;
    unsigned short PB = (char)x;

    if(PB <= (67)){
    PORTB = 0x01;
    }
    if((PB > 67) && (PB <= (167))) {
    PORTB = 0x02;
    }
    if((PB > 167) && (PB <= (267))) {
    PORTB = 0x04;
    }
    if((PB > 267) && (PB <= (367))) {
    PORTB = 0x08;
    }
    if((PB > 367) && (PB <= (467))) {
    PORTB = 0x10;
    }
    if((PB > 467) && (PB <= (567))) {
    PORTB = 0x20;
    }
    if((PB > 567) && (PB <= (667))) {
    PORTB = 0x40;
    }
    if(PB > (667)) {
    PORTB = 0x80;
    }

    /*unsigned short PD = (char)(x >> 8);
    PORTB = PB;
    PORTD = PD;*/
    }
    //PORTB = output;
    return 0;
}
