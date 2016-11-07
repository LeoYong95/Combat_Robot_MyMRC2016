//Auth: Leo Yong

//This is the class that process and do mixing on the pwm signal received.
//Note: Motor Direction 0 = front 1 = back
//NOte: Maximum motor PWM signal = 250
//Note: motor 1 is left motor motor 2 is right motor

//=====BEGIN Motor CLASS=====
class Motor {

public:
int motorPin;
int chIn;
int ch1PwmIn , ch2PwmIn;
int pwmOut1 , pwmOut2;
int dir1, dir2;



Motor()  {
      Serial.begin(9600); 

  }

int pwmCompute(int sig) {
  
  int pwmSig = map(sig, 1000,2000,-250,250); return pwmSig;

}

void pwmMixing (int pwm1, int pwm2) {       //pwm1 will be the pwm from channel 1 and pwm2 will be pwm signal from channel 2)

    ch1PwmIn = pwmCompute(pwm1); ch2PwmIn = pwmCompute(pwm2);
    
    if (ch1PwmIn > 0) {
      pwmOut1 = ch1PwmIn;
      pwmOut2 = ch2PwmIn-ch1PwmIn ; 
      if (pwmOut2 <-250) {          //Just for error catching 
        pwmOut2 = -250;
        Serial.println("turn Right Maximum");
      }
            

    }else if (ch1PwmIn < 0 ) {
      pwmOut1 = ch1PwmIn;
      pwmOut2 = ch2PwmIn-ch1PwmIn ;
      if (pwmOut2 >250) {
         pwmOut2 = 250;
        Serial.println("turn Left Maximum");

      }
             
    }
    Serial.println(pwmOut1);
    Serial.println(pwmOut2);
/*
  if (pwmOut2 > 0 ) {
      dir1 = 1;
      dir2 = 1;
    }else if (pwmOut2 < 0) {
      dir1 = 0;
      dir2 = 0;
    }
    */
}
  
};
//=====END CLASS======
