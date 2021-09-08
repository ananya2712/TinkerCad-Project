#include <LiquidCrystal.h>
int t=0;
int c=0;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(A0, INPUT);
  pinMode(6,OUTPUT);

  Serial.begin(9600);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  t=40;
  c=map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print(c);
  
  if(c>50)
    digitalWrite(6,HIGH);
  else
    digitalWrite(6,LOW);
  delay(1000);
  lcd.clear();
  
  if(c>20)
  {   
    if(c>=40)
    {
      analogWrite(9,255);
      lcd.print("Fan speed:100%");
      delay(1000);
      lcd.clear();
    }
  }
  else 
    lcd.print("FAN OFF");
  
  delay(1000);
  lcd.clear();
}


