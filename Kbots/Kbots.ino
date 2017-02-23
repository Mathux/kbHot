#include <Wire.h>
#include <config.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long previousMillis_refresh = 0;
unsigned long previousMillis_wait = 0;

enum mode_dispo {
  mhome,
  mpos,
  mbat
};

mode_dispo mode = mhome;

void setup(){  
  //hacheur
  TCCR4B = TCCR4B & B11111000 | B00000001; //D6,D7,D8 ,31372.55 Hz
  TCCR2B = TCCR2B & B11111000 | B00000001; //D9,D10   ,31372.55 Hz
  TCCR1B = TCCR1B & B11111000 | B00000001; //D11,D12  ,31372.55 Hz
  
  // port serie
  Serial2.begin(9600);
  pinMode(13, OUTPUT);
  
  //lcd
  lcd.begin();
  lcd.backlight();
  home ();

  // led
  pinMode(UI_LED5,OUTPUT);
  pinMode(UI_LED4,OUTPUT);
  pinMode(UI_LED3,OUTPUT);
  pinMode(UI_LED2,OUTPUT);
  pinMode(UI_LED1,OUTPUT);
  pinMode(UI_LED0,OUTPUT);

  pinMode(UI_BTN_DOWN,INPUT_PULLUP);
  pinMode(UI_BTN_CENTER,INPUT_PULLUP);
  pinMode(UI_BTN_RIGHT,INPUT_PULLUP);
  pinMode(UI_BTN_UP,INPUT_PULLUP);
  pinMode(UI_BTN_LEFT,INPUT_PULLUP);
  
  // motor
  pinMode(MOT1_1,OUTPUT);
  pinMode(MOT1_2,OUTPUT);
  pinMode(COD1_A,INPUT);
  pinMode(COD1_B,INPUT);
  pinMode(MOT1_EN,OUTPUT);
  
  pinMode(MOT2_1,OUTPUT);
  pinMode(MOT2_2,OUTPUT);
  pinMode(COD2_A,INPUT);
  pinMode(COD2_B,INPUT);
  pinMode(MOT2_EN,OUTPUT);

  // codeur
  attachInterrupt(0,change_codeur1_A,CHANGE);
  attachInterrupt(1,change_codeur1_B,CHANGE);
  attachInterrupt(4,change_codeur2_A,CHANGE);
  attachInterrupt(5,change_codeur2_B,CHANGE);


  // home
  menu_lcd();
}

int refresh = 700;

void loop() {
  //monitor ();
  char c; 
  while((c=Serial2.read())==-1) {
    unsigned long currentMillis_refresh = millis();
    unsigned long currentMillis_wait = millis();
    
    if (currentMillis_refresh - previousMillis_refresh >= refresh) {
      previousMillis_refresh = currentMillis_refresh;
      unsigned long currentMillis_wait = millis();
      if (button()) {
       previousMillis_wait = currentMillis_wait; 
      }
      if(mode!=mhome) {
        menu_lcd();
        if (currentMillis_wait - previousMillis_wait >= wait_menu()) {
          mode = mhome;
          menu_lcd();
        }
      }
    }
    else {
     if (button()) {
      previousMillis_wait = currentMillis_wait;
      previousMillis_refresh = 0; // refresh direct
     }      
    }
  }
  static int vit = 60;
  static int t = 1000;
  static int v1 = 0;
  static int v2 = 0;
  motor1(v1);
  motor2(v2);
  switch (c) {
    case 's' :
      v1 = vit;
      v2 = vit;
    break;    
    case 'l' :
      v1 = -40;
      v2 = 40;
    break;
    case 'r' :
      v1 = 40;
      v2 = -40;
    break;
    case 'd' :
      v1 = -vit;
      v2 = -vit;
    break;
    case 'm' :
      v1 = 0;
      v2 = 0;      
    break;
    case '+' :
      if (vit+10 > 100) {
       vit = 100; 
      }
      else {
        vit = vit + 10;
      }
      if (v1>0) v1=vit;
      else if (v1<0) v1=-vit;
      if (v2>0) v2=vit;
      else if (v2<0) v2=-vit;
    break;
    case '-' :
      if (vit-10 < 0) {
       vit = 0; 
      }
      else {
        vit = vit - 10;
      }
      if (v1>0) v1=vit;
      else if (v1<0) v1=-vit;
      if (v2>0) v2=vit;
      else if (v2<0) v2=-vit;
    break;
    case 'x' :
      piece ();
    break;
   }
  motor1(v1);
  motor2(v2);
}
