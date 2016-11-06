//Auth: Leo Yong

//Receive the signal from receiver and process the direction and generate driving pwm.

#define timeOut  25000
#define timeUpdate  100

//=====BEGIN Channel CLASS=====
class Channel {

  public:
  int recPin,sigIn,sigOut,dirL,dirR;
  int prevTime;  
  Channel (int rec) : recPin(rec) {
    pinMode (recPin, INPUT);
    Serial.begin(9600); // Pour a bowl of Serial

    }

   int sigRead(unsigned long currentTime) {
    if (currentTime - prevTime >= timeUpdate){
      sigIn = pulseIn(recPin,HIGH,timeOut);   Serial.println(sigIn);
      prevTime = currentTime;
    }
    return sigIn;
   }
   int sig2Motor(int sig) {
     sigOut = map(sig, 1000,2000,-500,500); return sigOut;
   }
  int dir2Motor () {}
};
//=====END CLASS======
