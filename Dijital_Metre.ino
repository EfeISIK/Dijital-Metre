#include <LiquidCrystal.h>

int TrigPin = 7;
int EchoPin = 6;
int sure;
int uzaklik;

int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3,d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  lcd.begin(16,2);
}

void loop() {

digitalWrite(TrigPin, LOW);
delayMicroseconds(5);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);

sure = pulseIn(EchoPin, HIGH, 11600);

uzaklik = sure*0.0345/2;

delay(250);

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Uzaklik:");
lcd.setCursor(0,1);
lcd.print(uzaklik);
lcd.print("cm");
}
