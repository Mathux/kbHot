int button () {
  if(digitalRead(UI_BTN_LEFT)==LOW){
    motor1(50);
    motor2(50);
  }
  if(digitalRead(UI_BTN_RIGHT)==LOW){
    afficherPos();
  }
  if(digitalRead(UI_BTN_CENTER)==LOW) {
    int note = 400;
    //lune(note);   
    piece();
  }
  if(digitalRead(UI_BTN_UP)==LOW) {
    stop_motor();
    afficherPos();
    return 300;
  }
  if(digitalRead(UI_BTN_DOWN)==LOW) {
    afficherM ();
    return 1000;
  } 
  return 400;
}
