void motor1(float vit1) {
  if(vit1 > 0 && vit1 < 100) {
    analogWrite(MOT1_2, (int) vit1*2.55);
    analogWrite(MOT1_1,0);
  }
  else if(vit1 <= 0 && vit1 > -100) {
    analogWrite(MOT1_2,0);
    analogWrite(MOT1_1,(int) -vit1*2.55);
  }
  else if(vit1 >= 100) {
    analogWrite(MOT1_2,255);
    analogWrite(MOT1_1,0);
  }
  else if(vit1 <= -100) {
    analogWrite(MOT1_2,0);
    analogWrite(MOT1_1,255);
  }
  else { 
    analogWrite(MOT1_2,0);
    analogWrite(MOT1_1,0);
  }
}

void motor2(float vit2) {
  if(vit2 > 0 && vit2 < 100) {
    analogWrite(MOT2_2,(int) vit2*2.55);
    analogWrite(MOT2_1,0);
  }
  else if(vit2 <= 0 && vit2 > -100) {
    analogWrite(MOT2_1,(int) -vit2*2.55);
    analogWrite(MOT2_2,0);
  }
  else if(vit2 > 100) {
    analogWrite(MOT2_2,255);
    analogWrite(MOT2_1,0);
  }
  else if(vit2 <= -100) {
    analogWrite(MOT2_1,255);
    analogWrite(MOT2_2,0);
  }
  else { 
    analogWrite(MOT2_2,0);
    analogWrite(MOT2_1,0);
  }
}

void stop_motor () {
  analogWrite(MOT1_1,0);
  analogWrite(MOT1_2,0);
  analogWrite(MOT2_1,0);
  analogWrite(MOT2_2,0);
}
