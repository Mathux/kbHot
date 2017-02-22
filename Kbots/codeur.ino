int codeur1_A = 0;
int codeur1_B = 0;
int codeur2_A = 0;
int codeur2_B = 0;
int pos1 = 0;
int pos2 = 0;

void change_codeur1_A() {
  if (codeur1_A) {
    codeur1_A = 0;
    if (codeur1_B) pos1 +=1;
    else pos1 -= 1;          
  }
  else {
    codeur1_A = 1;
    if (codeur1_B) pos1 -=1;
    else pos1 += 1;
  }
} 

void change_codeur1_B() {
  if (codeur1_B) {
    codeur1_B = 0;
    if (codeur1_A) pos1 -=1;
    else pos1 += 1;          
  }
  else {
    codeur1_B = 1;
    if (codeur1_A) pos1 +=1;
    else pos1 -= 1;
  }
} 

void change_codeur2_A() {
  if (codeur2_A) {
    codeur2_A = 0;
    if (codeur2_B) pos2 +=1;
    else pos2 -= 1;          
  }
  else {
    codeur2_A = 1;
    if (codeur2_B) pos2 -=1;
    else pos2 += 1;
  }
} 

void change_codeur2_B() {
  if (codeur2_B) {
    codeur2_B = 0;
    if (codeur2_A) pos2 -=1;
    else pos2 += 1;          
  }
  else {
    codeur2_B = 1;
    if (codeur2_A) pos2 +=1;
    else pos2 -= 1;
  }
} 
