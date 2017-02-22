#define DO3 261.63
#define RE3 293.66
#define MI3 329.63
#define FA3 349.23
#define SOL3 392.00
#define LA3 440.00
#define SI3 493.88
#define DO4 523.25
#define RE4 587.33
#define MI4 659.26
#define FA4 698.46
#define SOL4 783.99
#define LA4 880.00
#define SI4 987.77
#define DO5 1046.50
#define MARIO 150

void lune (int note) {
 tone(BUZZER,DO3,note);
 delay(note);
 tone(BUZZER,DO3,note);
 delay(note);
 tone(BUZZER,DO3,note);
 delay(note);
 tone(BUZZER,RE3,note);
 delay(note);
 tone(BUZZER,MI3,note);
 delay(note);
 delay(note);
 tone(BUZZER,RE3,note);
 delay(note);
 delay(note);
 tone(BUZZER,DO3,note);
 delay(note);
 tone(BUZZER,MI3,note);
 delay(note);
 tone(BUZZER,RE3,note);
 delay(note);
 tone(BUZZER,RE3,note);
 delay(note);
 tone(BUZZER,DO3,note);
 delay(note);  
}

void piece () {
  int note = MARIO;
  tone(BUZZER,SI3,note);
  delay(note);
  tone(BUZZER,MI4,note);
  delay(note*3);
}
