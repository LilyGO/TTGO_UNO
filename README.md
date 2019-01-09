
# Arduino test demo

![image](https://github.com/LilyGO/TTGO_UNO/blob/master/image/uno1.png)

## Module 1 Buzzer

```c
int buzzer = 8; // set the buzzer control digital IO pin

void setup() {
  pinMode(buzzer, OUTPUT); // set pin 8 as output
}

void loop() {
  for (int i = 0; i < 80; i++) {  // make a sound
    digitalWrite(buzzer, HIGH); // send high signal to buzzer 
    delay(1); // delay 1ms
    digitalWrite(buzzer, LOW); // send low signal to buzzer
    delay(1);
  }
  delay(50);
  for (int j = 0; j < 100; j++) { //make another sound
    digitalWrite(buzzer, HIGH);
    delay(2); // delay 2ms
    digitalWrite(buzzer, LOW);
    delay(2);
  }
  delay(100);
}
```
### The buzzer works with the PWM function, PWN pin: 3, 5, 6, 9, 10, 11
---
### Buzzer Connection Diagram

![image](https://github.com/LilyGO/TTGO_UNO/blob/master/image/image1.png)


## Module 2 Button

```c
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
```
### Press，light on. Release，light off
---
### Button Connection Diagram
![image](https://github.com/LilyGO/TTGO_UNO/blob/master/image/image2.png)


## Module 3 RGB_LED

```c
int red = 11; // select the pin for the red LED
int blue =10; // select the pin for the  blue LED
int green =9; // select the pin for the green LED

int val;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(val = 255; val > 0; val--)
  {
    analogWrite(11, val);
    analogWrite(10, 255 - val);
    analogWrite(9, 128 - val);

    Serial.println(val, DEC);
    delay(5); 
  }
  for(val = 0; val < 255; val++)
  {
    analogWrite(11, val);
    analogWrite(10, 255 - val);
    analogWrite(9, 128 - val);
    
    Serial.println(val, DEC);
    delay(5); 
  }
}
```
### Red:GPIO11,Blue:GPIO10,Green:9
---
### RGB Connection Diagram
![image](https://github.com/LilyGO/TTGO_UNO/blob/master/image/image3.png)



## Module 4 DHT11_Sensor

```c
int DHpin = 8; // input/output pin
byte dat[5];   

byte read_data()
{
  byte i = 0;
  byte result = 0;
  for (i = 0; i < 8; i++) {
      while (digitalRead(DHpin) == LOW); // wait 50us
      delayMicroseconds(30); //The duration of the high level is judged to determine whether the data is '0' or '1'
      if (digitalRead(DHpin) == HIGH)
        result |= (1 << (8 - i)); //High in the former, low in the post
    while (digitalRead(DHpin) == HIGH); //Data '1', waiting for the next bit of reception
    }
  return result;
}

void start_test()
{
  digitalWrite(DHpin, LOW); //Pull down the bus to send the start signal
  delay(30); //The delay is greater than 18 ms so that DHT 11 can detect the start signal
  digitalWrite(DHpin, HIGH);
  delayMicroseconds(40); //Wait for DHT11 to respond
  pinMode(DHpin, INPUT);
  while(digitalRead(DHpin) == HIGH);
  delayMicroseconds(80); //The DHT11 responds by pulling the bus low for 80us;
  
  if(digitalRead(DHpin) == LOW)
    delayMicroseconds(80); //DHT11 pulled up after the bus 80us to start sending data;
  for(int i = 0; i < 5; i++) //Receiving temperature and humidity data, check bits are not considered;
    dat[i] = read_data();
  pinMode(DHpin, OUTPUT);
  digitalWrite(DHpin, HIGH); //After the completion of a release of data bus, waiting for the host to start the next signal
}

void setup()
{
  Serial.begin(9600);
  pinMode(DHpin, OUTPUT);
}

void loop()
{
  start_test();
  Serial.print("Humdity = ");
  Serial.print(dat[0], DEC); //Displays the integer bits of humidity;
  Serial.print('.');
  Serial.print(dat[1], DEC); //Displays the decimal places of the humidity;
  Serial.println('%');
  Serial.print("Temperature = ");
  Serial.print(dat[2], DEC); //Displays the integer bits of temperature;
  Serial.print('.');
  Serial.print(dat[3], DEC); //Displays the decimal places of the temperature;
  Serial.println('C');

  byte checksum = dat[0] + dat[1] + dat[2] + dat[3];
  if (dat[4] != checksum) 
    Serial.println("-- Checksum Error!");
  else
    Serial.println("-- OK");
 
  delay(1000);
}
```
### Display Temperature (Fahrenheit and Celsius)， Humidity value
---

### DHT11 Connection Diagram
![image](https://github.com/LilyGO/TTGO_UNO/blob/master/image/image4.png)



## Module 5 Photoresistance

```c
int sensorPin = 2; //define analog pin 2
int value = 0; 

void setup() {
  Serial.begin(9600); 
} 

void loop() {
  value = analogRead(sensorPin); 
  Serial.println(value, DEC); // light intensity
                // high values for bright environment
                // low values for dark environment
  delay(100); 
}
```
### The greater the light intensity, the larger the resistance value
---

### Photoresistance Connection Diagram
![image](https://github.com/LilyGO/TTGO_UNO/blob/master/image/image5.png)

