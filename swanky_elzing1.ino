// C++ code
//

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

void setup()
{
  Serial.begin(9600);
  
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  
  pinMode(buzzer, OUTPUT);

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
    if (buttonState2 == HIGH) {
    	buttonpressed2 = buttonpressed2 + 1;
    	Serial.println("Minutes: " + String(buttonpressed2));
      	delay(500);
    }
  	if (buttonState3 == HIGH) {
    	buttonpressed3 = buttonpressed3 + 1;
    	Serial.println("Mode: " + String(buttonpressed3));
      	delay(500);
    }
  	if (buttonpressed3 == 1){
      int time = buttonpressed1 * 60 + buttonpressed2;
      while (i < time) {
        Serial.println("Time Remaining: " + String(time));
        time = time - 1;
        delay(60000);
      	buttonpressed2 = buttonpressed2 - 1;
        if (buttonpressed2 = 0 && buttonpressed1 != 0) {
          buttonpressed2 = 60;
          buttonpressed1 = buttonpressed1 - 1;
        }
        
      }
    }
}