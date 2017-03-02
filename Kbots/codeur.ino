
void change_codeur1_A() {
  if (digitalRead(COD1_A)) {
    if (digitalRead(COD1_B)) pos1 -=1;
    else pos1 += 1;          
  }
  else {
    if (digitalRead(COD1_B)) pos1 +=1;
    else pos1 -= 1;
  }
} 

void change_codeur1_B() {
  if (digitalRead(COD1_B)) {
    if (digitalRead(COD1_A)) pos1 +=1;
    else pos1 -= 1;          
  }
  else {
    if (digitalRead(COD1_A)) pos1 -=1;
    else pos1 += 1;
  }
} 

void change_codeur2_A() {
  if (digitalRead(COD2_A)) {
    if (digitalRead(COD2_B)) pos2 +=1;
    else pos2 -= 1;          
  }
  else {
    if (digitalRead(COD2_B)) pos2 -=1;
    else pos2 += 1;
  }
} 

void change_codeur2_B() {
  if (digitalRead(COD2_B)) {
    if (digitalRead(COD2_A)) pos2 -=1;
    else pos2 += 1;          
  }
  else {
    if (digitalRead(COD2_A)) pos2 +=1;
    else pos2 -= 1;
  }
} 


