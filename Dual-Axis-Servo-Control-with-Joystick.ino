#include <Servo.h>

int xPin=A0;
int yPin=A1;
int sPin=8;
int xSpin=9;
int ySpin=10;
int ledPin=4;
int xVal;
int yVal;
int sState; //Switch State

int yPos;
int xPos;
Servo xServo;
Servo yServo;

void setup() {
  Serial.begin(9600);
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
  pinMode(sPin,INPUT);
  pinMode(ledPin,OUTPUT);
  digitalWrite(sPin,HIGH);
  pinMode(xSpin,OUTPUT);
  pinMode(ySpin,OUTPUT);

  xServo.attach(xSpin);
  yServo.attach(ySpin);
}

void loop() {
  xVal=analogRead(xPin);
  yVal=analogRead(yPin);
  sState=digitalRead(sPin);

  xPos=(180/1023.)*xVal;
  yPos=(180/1023.)*yVal;

  xServo.write(xPos);
  yServo.write(yPos);
  if(sState==0){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }

  Serial.print(xPos);
  Serial.print(" ");
  Serial.print(yPos);
  Serial.print(" ");
  Serial.println(sState);
}
