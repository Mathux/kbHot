void monitor ()  {
  int u4 = analogRead(BATT_0);
  int u3 = analogRead(BATT_1);
  int u2 = analogRead(BATT_2);
  float r1 = 470.0,r2 = 240.0,r3 = 470.0,r4 = 240.0;
  float v2 = u2;
  float v3 = ((r4 + r3)/r4)*u3 - v2;
  float v4 = ((r4 + r3)/r4)*u4 - (v3 + v2);
  v2 = (v2*5)/1024;
  v3 = (v3*5)/1024;
  v4 = (v4*5)/1024;
  if (v3 <= 3.6 || v2 <= 3.6 || v4 <= 3.6) {
    stop_motor ();
    while (1) {    
      tone(BUZZER,261.626,500);
    }
  }    
} 
