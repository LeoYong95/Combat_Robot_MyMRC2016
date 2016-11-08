/*
Auth: Leo Yong

##### ###### ##      # #####   ####### ######## 
##    ##   # ###   # # ##   #  ##    #    ##
##    ##   # ##  #   # ######  #######    ##
##    ##   # ##      # ##    # ##    #    ##  
##### ###### ##      # ######  ##    #    ##
*/

 #include "Receiver.h"
 #include "Param.h"

 
Channel *ch1;
Channel *ch2;
Channel *ch5;
Motor_Control *m;

unsigned long sigIn1,sigIn2,sigIn5,previousMillis;


void setup() {
  
  ch1 = new Channel(RECCHANNEL1);
  ch2 = new Channel(RECCHANNEL2);
  ch5 = new Channel(RECCHANNEL5);
  m = new Motor_Control(MOTOR1PWMPIN,MOTOR1DIRPIN, MOTOR2PWMPIN,MOTOR2DIRPIN);
  

  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}

  SIGNAL(TIMER0_COMPA_vect)
{
  unsigned long currentMillis = millis();
  
if (currentMillis -previousMillis == updateInterval) {
 sigIn1 = ch1->sigRead();
 sigIn2 = ch2->sigRead();
 sigIn5 = ch5->sigRead();
 
 
 m->pwmMixing(sigIn1,sigIn2,sigIn5);
 
 previousMillis = currentMillis;
}
 
}

void loop() {}
