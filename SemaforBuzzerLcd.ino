#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  

const int ledRed = 16;     // GPIO16
const int ledYellow = 17;  // GPIO17
const int ledGreen = 18;   // GPIO18
const int buzzerPin = 27;  // GPIO27

void ledChange(int valLedR, int valLedY, int valLedG) {
  digitalWrite(ledRed, valLedR);
  digitalWrite(ledYellow, valLedY);
  digitalWrite(ledGreen, valLedG);
}

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);

  lcd.init();         // Inițializează LCD
  lcd.backlight();    // Activează lumina de fundal
}

void loop() {
  // Roșu - Stop
  ledChange(HIGH, LOW, LOW);
  for (int i = 10; i > 0; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("RED! ");
    lcd.setCursor(0, 1);
    lcd.print("Seconds: ");
    lcd.print(i);

    tone(buzzerPin, 100, 50);
    delay(1000);
  }

  // Galben - Pregătire
  ledChange(LOW, HIGH, LOW);
  for (int i = 3; i > 0; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YELLOW!");
    lcd.setCursor(0, 1);
    lcd.print("Seconds: ");
    lcd.print(i);

    tone(buzzerPin, 1000, 100);
    tone(buzzerPin, 500, 50);
    delay(1000);
  }

  // Verde - Pornire
  ledChange(LOW, LOW, HIGH);
  for (int i = 15; i > 0; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("GREEN!");
    lcd.setCursor(0, 1);
    lcd.print("Seconds: ");
    lcd.print(i);

    tone(buzzerPin, 500, 100); 
    tone(buzzerPin, 1000, 100);
    tone(buzzerPin, 500, 100); 
    tone(buzzerPin, 1000, 100);
    tone(buzzerPin, 500, 100);
    
    delay(1000);
  }

  // Galben - Avertizare
  ledChange(LOW, HIGH, LOW);
  for (int i = 3; i > 0; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YELLOW! ");
    lcd.setCursor(0, 1);
    lcd.print("Seconds: ");
    lcd.print(i);

    tone(buzzerPin, 1000, 100);
    tone(buzzerPin, 500, 50);
    delay(1000);
  }
}
