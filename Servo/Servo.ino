#include <Adafruit_PWMServoDriver.h>
#include <config.h>
#include <Wire.h>
#include <SoftwareSerial.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

void setup(){  
  
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  
}


uint16_t servo (float angle) {

  uint16_t puls = 2.5*angle + 150;

  return puls > SERVOMAX ? SERVOMAX : (puls < SERVOMIN ? SERVOMIN : puls);
}

void loop() {

  pwm.setPWM(0, 0, servo(90));
  delay(500);
  pwm.setPWM(0, 0, servo(80));
  delay(500);
  pwm.setPWM(0, 0, servo(100));
  delay(500);
  pwm.setPWM(0, 0, servo(70));
  delay(500);
  pwm.setPWM(0, 0, servo(110));
  delay(500);
  pwm.setPWM(0, 0, servo(60));
  delay(500);
  pwm.setPWM(0, 0, servo(120));
  delay(500);
  pwm.setPWM(0, 0, servo(50));
  delay(500);
  pwm.setPWM(0, 0, servo(130));
  delay(500);
  pwm.setPWM(0, 0, servo(40));
  delay(500);
  pwm.setPWM(0, 0, servo(140));
  delay(500);
  pwm.setPWM(0, 0, servo(30));
  delay(500);
  pwm.setPWM(0, 0, servo(150));
  delay(500);
  pwm.setPWM(0, 0, servo(20));
  delay(500);
  pwm.setPWM(0, 0, servo(160));
  delay(500);
  pwm.setPWM(0, 0, servo(10));
  delay(500);
  pwm.setPWM(0, 0, servo(170));
  delay(500);
  pwm.setPWM(0, 0, servo(0));
  delay(500);
  pwm.setPWM(0, 0, servo(180));
  
  
  /*
  for (int angle = 0; angle < 180; angle++) {
    pwm.setPWM(0, 0, servo (angle));
  }

  delay(500);
  
  for (int angle = 180; angle > 0; angle--) {
    pwm.setPWM(0, 0, servo (angle));
  }
  
  delay(500);
  */

 
}



