// C++ code
//

const int buttonPin1 = 10;
const int buttonPin2 = 9;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonpressed1 = 0;

void setup()
{
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  
  Serial.begin(9600);

}

void loop()
{
	buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
}
