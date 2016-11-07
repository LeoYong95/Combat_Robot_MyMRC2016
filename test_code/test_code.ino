/*
Auth: Leo Yong


*/
 #include "Receiver.h"

 #define updateInterval  100


Channel *ch1;
Channel *ch2;
Motor *m;

unsigned long sigIn1, sigIn2,previousMillis;


void setup() {
  
  ch1 = new Channel(5);
  ch2 = new Channel(6);
  m = new Motor();
  

  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}

  SIGNAL(TIMER0_COMPA_vect)
{
  unsigned long currentMillis = millis();
  
 /*  sigIn1 = ch1->sigRead(currentMillis);
   sigIn2 = ch2->sigRead(currentMillis);
   
*/
if (currentMillis -previousMillis == updateInterval) {
 sigIn1 = ch1->sigRead();
  sigIn2 = ch2->sigRead();
  m->pwmMixing(sigIn1,sigIn2);
      previousMillis = currentMillis;
}
 
}
void loop() { 
 

  
  }
