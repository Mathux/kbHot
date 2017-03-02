int button () {
  if(digitalRead(UI_BTN_LEFT)==LOW){
    motor1(50);
    motor2(50);
  }
  if(digitalRead(UI_BTN_RIGHT)==LOW){
    mode = mpos;
    return 1;
  }
  if(digitalRead(UI_BTN_CENTER)==LOW) {
    int note = 400;
    //lune(note);   
    //piece();
    while (1) {stop_motor();};
  }
  if(digitalRead(UI_BTN_UP)==LOW) {
    stop_motor();
    mode = mpos;
    return 1;
  }
  if(digitalRead(UI_BTN_DOWN)==LOW) {
    mode = mbat;
    return 1;
  } 
  return 0;
}
