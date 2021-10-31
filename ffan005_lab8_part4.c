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

    if(PB <= (32)){
    PORTB = 0x01;
    }
    if((PB > 32) && (PB <= (64))) {
    PORTB = 0x02;
    }
    if((PB > 64) && (PB <= (96))) {
    PORTB = 0x04;
    }
    if((PB > 96) && (PB <= (128))) {
    PORTB = 0x08;
    }
    if((PB > 128) && (PB <= (160))) {
    PORTB = 0x10;
    }
    if((PB > 160) && (PB <= (192))) {
    PORTB = 0x20;
    }
    if((PB > 192) && (PB <= (224))) {
    PORTB = 0x40;
    }
    if(PB > (224)) {
    PORTB = 0x80;
    }

    /*unsigned short PD = (char)(x >> 8);
    PORTB = PB;
    PORTD = PD;*/
    }
    //PORTB = output;
    return 0;
}
