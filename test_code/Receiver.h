//Auth: Leo Yong


//Receive the signal from receiver and process the direction and generate driving pwm.
 #include "Motor.h"


//=====BEGIN Channel CLASS=====
class Channel {

  public:
  int recPin,sigIn,sigOut,dirL,dirR;
  int prevTime;  
  Channel (int rec) : recPin(rec) {
    pinMode (recPin, INPUT);
    Serial.begin(9600); 

    }

   int sigRead() {
  
      sigIn = pulseIn(recPin,HIGH);  ;
      return sigIn;

   }
   
   /*int sig2Motor(int sig) {
     sigOut = map(sig, 1000,2000,-225,225); return sigOut;
   }
  */
};
//=====END CLASS======
