#include <FlexiTimer2.h>


uint8_t i = 0;
uint16_t count = 0;
boolean increment = LOW;

uint8_t table [10] = {
  0x3F,
  0x06,
  0x5B,
  0x4F,
  0x66,
  0x6D,
  0x7D,
  0x07,
  0x7F,
  0x6F
};


void setup() {
  DDRD = B11111100;
  DDRB = B100011;
  DDRC = B001111;

  /*PORTC = (PORTC &= 0x30) | (0x01);
  PORTD = (PORTD &= 0x03) | (table[1]<<2);
  PORTB = (PORTB &= 0x7C) | (table[1]>>6);*/
  FlexiTimer2::set(5, counter);
  FlexiTimer2::start();
  
}

void loop() {
  
}

void counter() {
  
  if (increment == HIGH) {
    increment = LOW;
    count++;
    if (count == 10000) { count = 0; }
  } else {
    increment = HIGH;
  }
  
  uint16_t x = count/(1*pow(10, i));
  showNumber(x%10);
  
  if (i == 0) {
    PINB=(1<<5);
  }
  
  i++;
  
  if (i == 4) {
    i = 0;
  }

}


void showNumber(uint16_t x) {
    PORTC = (PORTC = 0x0F) & ~(1<<i);
    //Serial.println(table[numbers[i]], HEX);
    PORTD = (PORTD &= 0x03) | (table[x]<<2);
    PORTB = (PORTB &= 0x7C) | (table[x]>>6);
    
    
}

