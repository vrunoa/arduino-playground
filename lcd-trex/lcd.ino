// include the library code:
#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

byte q1[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B10000,
  B11001,
  B11111,
};

byte q2[8] = {
  B00111,
  B01011,
  B01111,
  B01111,
  B01111,
  B11110,
  B11111,
  B11110,
};

byte q3[8] = {
  B11100,
  B11110,
  B11110,
  B00000,
  B11000,
  B00000,
  B10000,
  B10000,
};

byte q4[8] = {
  B11111,
  B01111,
  B00111,
  B00011,
  B00011,
  B00011,
  B00010,
  B00011,
};

byte q4l[8] = {
  B11111,
  B01111,
  B00111,
  B00011,
  B00011,
  B00010,
  B00010,
  B00011,
};

byte q5[8] = {
  B11110,
  B11110,
  B11100,
  B11000,
  B01000,
  B01000,
  B01000,
  B01100,
};

byte q5l[8] = {
  B11110,
  B11110,
  B11100,
  B11000,
  B01000,
  B01000,
  B01000,
  B01100,
};

void setup() {
  lcd.begin(16, 2);
};

void printTrex(int x) {
  lcd.createChar(1, q1);
  lcd.createChar(2, q2);
  lcd.createChar(3, q3);
  lcd.createChar(4, q4);
  lcd.createChar(6, q4l);
  lcd.createChar(5, q5);
  lcd.createChar(7, q5l);
  // write q1
  lcd.setCursor(x,0);
  lcd.write(1);
  // write q2
  lcd.setCursor(x+1,0);
  lcd.write(2);
  // write q3
  lcd.setCursor(x+2,0);
  lcd.write(3);
  // write q4
  lcd.setCursor(x,1);
  if (x%2 == 0) {
    lcd.write(4);
  } else {
    lcd.write(6);
  }
  // write q5
  lcd.setCursor(x+1,1);
  if(x%2 == 0) {
    lcd.write(5);       
  } else {
    lcd.write(7);
  }
}

void loop() {
  int i = 0;
  while (true) {
    if(i<1) {
      lcd.print("R");
    } else if(i<2){
      lcd.print("ER");
    } else if(i<3) {
      lcd.print("EER");
    } else if(i<4) {
      lcd.print("BEER");
    } else {
      lcd.setCursor(i-3,0);
      lcd.print("BEER");
      if(i>5) {
        printTrex(i-7);
      }
    }
    delay(300);
    lcd.clear();
    if (i==22) {
      i=0;
    } else {
      i++;
    }
  }
};
