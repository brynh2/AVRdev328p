#define PORTB *(unsigned char*) 0x25
#define PORTD *(unsigned char*) 0x2B
#define DDRB  *(unsigned char*) 0x24
#define DDRD  *(unsigned char*) 0x2A

int main(){
    PORTB = (1<<1)|(1<<0);  
    DDRB  = (1<<1)|(1<<0);
    PORTD = (1<<7)|(1<<5);  
    DDRD  = (1<<7)|(1<<5);
}
