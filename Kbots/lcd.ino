void home () {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Kbot of power !");
  lcd.setCursor(0, 1);
  lcd.print("Mathis Petrovich");
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
  sprintf(s,"%d.%d| %d.%d |%d.%d", abs((int) (v2)),abs((int) (v2*100) - 100*((int) v2)),abs((int) (v3)),abs((int) (v3*100) - 100*((int) v3)),abs((int) (v4)),abs((int) (v4*100) - 100*((int) v4)));
  lcd.print("Battery state : ");
  lcd.setCursor(0, 1);
  lcd.print(s);  
} 

void afficherPos () {
  char s[20];
  lcd.clear();
  char p1[8];
  char p2[8];
  sprintf(p1, "G:%-6d", pos1);
  sprintf(p2, "D:%-5d", pos2);
  sprintf(s, "%s%s", p1, p2);
  lcd.setCursor(0, 0);
  lcd.print("  Positions : ");
  lcd.setCursor(0, 1);
  lcd.print(s);
}
    

