unsigned long previousMillisA = 0;
int refreshA = 50;
//#define pi 3.14159265358979323846264338327950288419716939937510

void asserv(int cons1, int cons2) {
  static float kp1 = 1.55/3.;
  static float kp2 = 1.18/3.;
  static float ki1 = 0;//1./10.;
  static float ki2 = 0;//1./10.;
  unsigned long currentMillisA = millis();
  
  if (currentMillisA - previousMillisA >= refreshA) {
    previousMillisA = currentMillisA;
    int erreur1 = cons1 - pos1;
    int erreur2 = cons2 - pos2;
    float pterm1 = kp1*erreur1;
    float pterm2 = kp2*erreur2;
    static float iterm1 = 0;
    static float iterm2 = 0;
    iterm1 += ki1*refreshA*erreur1;
    iterm2 += ki2*refreshA*erreur2;
    float command1 = pterm1 + iterm1 + 3;
    float command2 = pterm2 + iterm2 + 4;
    //motor1(20*(cons1-pos1)/360 + 8);
    //motor2(20*(cons2-pos2)/360 + 16);
    
    motor1(command1 < 15 ? 0 : command1);
    motor2(command2 < 15 ? 0 : command2);
  }
   
}
