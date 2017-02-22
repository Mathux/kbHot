void home () {
  if(!mode_home) {
    mode_home = 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Kbot of power !");
    lcd.setCursor(0, 1);
    lcd.print("Mathis Petrovich");
  }
}

void afficherM ()  {
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
  char s[20]; 
  lcd.clear();
  sprintf(s,"%d | %d | %d", (int) (v2*100), (int) (v3*100), (int) (v4*100));
  lcd.print("Battery state : ");
  lcd.setCursor(0, 1);
  lcd.print(s);  
  mode_home = 0;
} 

void afficherPos () {
  char s[20];
  lcd.clear();
  sprintf(s, "p1:%d p2:%d", pos1, pos2);
  lcd.setCursor(0, 0);
  lcd.print("Positions : ");
  lcd.setCursor(0, 1);
  lcd.print(s);
  mode_home = 0;
}
