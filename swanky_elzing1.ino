// C++ code
//

#include <LiquidCrystal.h>

const int buttonPin1 = 10;
const int buttonPin2 = 9;
const int buttonPin3 = 12;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonpressed1 = 0;
int buttonpressed2 = 0;
int buttonpressed3 = 0;
int i = 0;
int time2 = 0;

const int buzzer = 11;

LiquidCrystal lcd(3, 4, 5, 6, 7, 8);

const int contrast = 2;

void setup()
{
  Serial.begin(9600);
  
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  
  pinMode(buzzer, OUTPUT);
  
  analogWrite(contrast, 100);
  lcd.begin(16, 2);
    	

  
}

void loop()
{
  	
	buttonState1 = digitalRead(buttonPin1);
  	buttonState2 = digitalRead(buttonPin2);
  	buttonState3 = digitalRead(buttonPin3);
    if (buttonState1 == HIGH) {
    	buttonpressed1 = buttonpressed1 + 1;
    	Serial.println("Hours: " + String(buttonpressed1));
      	delay(500);
    }
lcd.setCursor(0, 0);
lcd.print("Hours: " + String(buttonpressed1));

    if (buttonState2 == HIGH) {
    	buttonpressed2 = buttonpressed2 + 1;
    	Serial.println("Minutes: " + String(buttonpressed2));
      	delay(500);
    }      	
  		lcd.setCursor(0, 1);
      	lcd.print("Minutes: " + String(buttonpressed2));
  	if (buttonState3 == HIGH) {
    	buttonpressed3 = buttonpressed3 + 1;
      if (buttonpressed3 == 3) {
      	buttonpressed3 == 0;
      }
    	Serial.println("Mode: " + String(buttonpressed3));
      	delay(500);
    }
  	if (buttonpressed3 == 1){
      int time = buttonpressed1 * 60 + buttonpressed2;
      while (i < time) {
        Serial.println("Time Remaining: " + String(time) + " minutes");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Time Remaining: ");
        lcd.setCursor(0, 1);
        //lcd.print(String(buttonpressed1) + "h " + String(buttonpressed2) + "m");
        lcd.print(String(time) + " minutes");        
        time = time - 1;

        delay(60000);
      	buttonpressed2 = buttonpressed2 - 1;
        if (buttonpressed2 = 0 && buttonpressed1 != 0) {
          buttonpressed2 = 60;
          buttonpressed1 = buttonpressed1 - 1;
        }
        
      }
    if (i == time && buttonpressed3 == 1) {
        tone(buzzer, 1000);
        delay(1000);
        noTone(buzzer);
        delay(1000);
        
      }
    }
}