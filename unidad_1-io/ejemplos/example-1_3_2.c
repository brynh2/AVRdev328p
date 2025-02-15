#include "../include/registros.h"

int main(){
    DDRB |= (1<<0)|(1<<2); //LEDs 
    DDRD |= (1<<6); 
    DDRC &= ~((1<<3)|(1<<4)); // Pulsadores 
    DDRD &= ~(1<<2);
    PORTC |= (1<<3);  //Pull-up
    
    while(1){
        while((PINC & (1<<4))){    // Presionando S1
            PORTB &= ~(1<<2);      // Apagamos D1
            PORTB |= (1<<2);       // Encendemos D1 
            if(!(PINC & (1<<4))){  // Si deja de presionarse
                PORTB |= (1<<2);   // Encendemos D1 
            }
        }
        while((PIND & (1<<2))){    // Presionando S3
            PORTD |= (1<<6);       // Encendemos D3 
            if(!(PIND & (1<<2))){  // Si deja de presionarse
                PORTD &= ~(1<<6);  // Apagamos D3
            }
        }
        if(~(PINC & (1<<3))){  // Si se presiona S5
            PORTB ^= (1<<0);  // Conmutamos el pin PB0
        }
    }
}