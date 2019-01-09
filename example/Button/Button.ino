/*
 * This is Button test sketch
 * 
 * 
 * 
 */
int led = 13; //Define the LED pin
int buttonPin = 3; //Define the push button pin
int val; //Define a numeric variable

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop()
{
  val = digitalRead(buttonPin); // check the state of the button
  if(val==HIGH) // if button is pressed, turn LED on
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
}
