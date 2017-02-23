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
