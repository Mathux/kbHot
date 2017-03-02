#include <Wire.h>
#include <config.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pos1 = 0;
int pos2 = 0;

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



void loop() {
  monitor ();
  char c = -1; 
  if ((c=Serial2.read())!=-1) {
    blue(c);
  }
  affiche_lcd();
  asserv(1500,1500);
}
