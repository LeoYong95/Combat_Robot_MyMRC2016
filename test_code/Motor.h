//Auth: Leo Yong

//This is the class that process and do mixing on the pwm signal received.
//Note: Motor Direction 0 = front 1 = back
//NOte: Maximum motor PWM signal = 250
//Note: motor 1 is left motor motor 2 is right motor

//=====BEGIN Motor CLASS=====
class Motor_Control {

public:
int motor1Pin,motor2Pin, dir1Pin,dir2Pin;
int chIn;
int ch1PwmIn , ch2PwmIn;
int pwmOut1 , pwmOut2, pwmOut5;
int dir1, dir2;



Motor_Control(int m1,int d1,int m2,int d2) : motor1Pin(m1) ,motor2Pin(m2),dir1Pin(d1), dir2Pin(d2) {
      Serial.begin(9600); 
      pinMode (motor1Pin,OUTPUT);
      pinMode (motor2Pin,OUTPUT);
      pinMode (dir1Pin,OUTPUT);
      pinMode (dir2Pin,OUTPUT);

  }

int pwmCompute(int sig) {
  
  int pwmSig = map(sig, 1000,2000,-250,250);
 
  if (pwmSig <10 && pwmSig >10) {
    
    pwmSig = 0;
  }
  
return pwmSig;
}

void motorCommand(int pwm1, int dir1, int pwm2 , int dir2 , int pwm5 ){

if (pwm5 >1500){
  digitalWrite(dir1Pin,dir1);
  digitalWrite(dir2Pin,dir2);
  digitalWrite(motor1Pin,pwm1);
  digitalWrite(motor2Pin,pwm2);
}else if (pwm5 <1500) {
  Serial.println("Motor Offline");
}
}

void pwmMixing (int pwm1, int pwm2, int pwm5) {              //pwm1 will be the pwm from channel 1 and pwm2 will be pwm signal from channel 2)

    ch1PwmIn = pwmCompute(pwm1); ch2PwmIn = pwmCompute(pwm2);
    pwmOut5 = pwm5;
    
    if (ch1PwmIn > 0 ) {
      pwmOut1 = ch2PwmIn;
      pwmOut2 = ch2PwmIn-ch1PwmIn*0.8 ; 
      if (pwmOut2 <-250) {                        //Just for error catching 
        pwmOut2 = -250;
        //Serial.println("turn Right Maximum");   //DEBUGGING
      }
            

    }else if (ch1PwmIn < 0) {
      pwmOut1 = ch2PwmIn;
      pwmOut2 = ch2PwmIn- ch1PwmIn*0.8 ;
      if (pwmOut2 >250) {
         pwmOut2 = 250;
        //Serial.println("turn Left Maximum");    //DEBUGGING

      }
             
    }

  
  if (pwmOut2 >= -15 && pwmOut2 <= 15 ) {          //Remove direction fluctuation
    pwmOut2 = 0;
     Serial.println("cnadkjcndsjkncdjcn");
    
   
    
  }else if (pwmOut1 >= -15 && pwmOut1 <= 15 ) {
    pwmOut1 = 0;
         Serial.println("cnadkjcndsjkncdjcn");


    
  }

    Serial.println(pwmOut1);                     //DEBUGGING
    Serial.println(pwmOut2);
    
   if (pwmOut2 > 0 ) {
      dir2 = 0;
    }else if (pwmOut2 < 0) {
      dir2 = 1;
    }

    
    if (pwmOut1 > 0 ) {
      dir1 = 0;
    }else if (pwmOut1 < 0) {
      dir1 = 1;
    }
   
    //Serial.println(dir1);                       //DEBUGGING
    //Serial.println(dir2);
    
    motorCommand(pwmOut1,dir1,pwmOut2,dir2, pwmOut5);

}


};
//=====END CLASS======
