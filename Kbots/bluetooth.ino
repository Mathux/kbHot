void blue(char c) {
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
