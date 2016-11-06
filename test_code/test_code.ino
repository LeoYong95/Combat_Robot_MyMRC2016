/*
Auth: Leo Yong


*/
 #include "Receiver.h"

Channel *ch1;
Channel *ch2;

int sigIn1, sigIn2,count;

void setup() {
  
  ch1 = new Channel(5);
  ch2 = new Channel(6);
  

  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}

  SIGNAL(TIMER0_COMPA_vect)
{
  unsigned long currentMillis = millis();
  
   sigIn1 = ch1->sigRead(currentMillis);
   sigIn2 = ch2->sigRead(currentMillis);
 
}
void loop() { 
  }
