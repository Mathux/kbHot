int wait_menu() {
  switch (mode) {     
     case mhome :
       return 0;
     break;
     
     case mpos :
       return 3000;
     break;
     
     case mbat :
       return 3000;
     break;
     
   }  
}

void menu_lcd () {
   switch (mode) {     
     case mhome :
       home ();
     break;
     
     case mpos :
       afficherPos ();
     break;
     
     case mbat :
       afficherM ();
     break;
     
   }
}

unsigned long previousMillis_refresh = 0;
unsigned long previousMillis_wait = 0;

int refresh = 700;

void affiche_lcd() {    
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

