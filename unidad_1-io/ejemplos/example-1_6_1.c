#define __AVR_ATmega328P__ 1
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(PCINT1_vect){   
    PORTB ^= (1<<2); //Conmutamos PB2
}
ISR(PCINT2_vect){   
    PORTD ^= (1<<6); //Conmutamos PD6 
}

int main(){
    DDRB |= (1<<0)|(1<<2); 
    DDRD |= (1<<6); 
    DDRC &= ~(1<<4); 
    DDRD &= ~(1<<2);
    PORTB |= (1<<2); 
    
    SREG  |= (1<<7);         
    PCICR |= (1<<2)|(1<<1);  
    PCMSK1 |= (1<<4);        
    PCMSK2 |= (1<<2);        
}