
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 20 , 4);

int trigPin = 13; //Sensor Trip pin connected to Arduino pin 13
int echoPin = 11; //Sensor Echo pin connected to Arduino pin 11
int myCounter = 0; //declare your variable myCounter and set to 0
int servoControlPin = 6; //Servo control line is connected to pin 6
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in inches
float speedOfSound = 776.5; //Speed of sound in miles per hour when temp is 77 degrees.
//Motor A
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
const int enable = 3;
//buttons
const int buttonPin1 = 2;
const int buttonPin2 = 4;
const int buttonPin3 = 7;
const int buttonPin4 = 8;
const int ledPin = 13;
int buttonPushCounter1 = 0;   // counter for the number of button presses
int buttonState1 = 0;         // current state of the button
int lastButtonState1 = 0;     // previous state of the button
int buttonState2 = 0;         // current state of the button
int lastButtonState2 = 0;    // previous state of the button
int buttonState3 = 0;         // current state of the button
int lastButtonState3 = 0;     // previous state of the button
int buttonState4 = 0;         // current state of the button
int lastButtonState4 = 0;     // previous state of the button
int x = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enable, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);// initialize the LCD
  lcd.begin();// Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Level from Top :");  //Print Message on First Row
}

void loop() {

  digitalWrite(trigPin, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Let signal settle
  digitalWrite(trigPin, HIGH); //Set trigPin high
  delayMicroseconds(15); //Delay in high state
  digitalWrite(trigPin, LOW); //ping has now been sent
  delayMicroseconds(10); //Delay in high state

  pingTime = pulseIn(echoPin, HIGH);  //pingTime is presented in microceconds
  pingTime = pingTime / 1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
  pingTime = pingTime / 3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
  targetDistance = speedOfSound * pingTime; //This will be in miles, since speed of sound was miles per hour
  targetDistance = targetDistance / 2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  targetDistance = targetDistance * 63360; //Convert miles to inches by multipling by 63360 (inches per mile)

  lcd.setCursor(0, 1); //Set cursor to first column of second row
  lcd.print("                "); //Print blanks to clear the row
  lcd.setCursor(0, 1);  //Set Cursor again to first column of second row
  lcd.print(targetDistance); //Print measured distance
  lcd.print(" Inches");  //Print your units.
  delay(250); //pause to let things settle

  // CODE FOR THE BUTTON PRESSES

  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 != lastButtonState1)
  {
    if (buttonState1 == LOW)
    {
      if (buttonPushCounter1 < 10)
      {
        x = x + 25;

        analogWrite(enable, x);
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        buttonPushCounter1++;
        Serial.print("number of button pushes:  ");
        Serial.println(buttonPushCounter1);
      }
    }
  }
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 != lastButtonState2)
  {
    if (buttonState2 == LOW)
    {
      if (buttonPushCounter1 > 0)
      {
        x = x - 25;
        analogWrite(enable, x);
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        buttonPushCounter1--;
        Serial.print("number of button pushes:  ");
        Serial.println(buttonPushCounter1);
      }
    }

    else if (buttonPushCounter1 == 0)
    {
      analogWrite(enable, 0);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  buttonState3 = digitalRead(buttonPin3);
  {
    if (buttonState3 == LOW)
    {
      analogWrite(enable, 255);
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      Serial.println("on");
    }
  }
  buttonState4 = digitalRead(buttonPin4);
  {
    if (buttonState4 == LOW)
    {
      analogWrite(enable, 0);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      Serial.println("off");
    }
  }

  if (targetDistance <= 1)
  {
    analogWrite(enable, 255);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    Serial.println("AUTO ON ");
  }
  /*if (targetDistance == 4.8 )
  {
    analogWrite(enable, 0);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    Serial.println("AUTO OFF");
  }*/
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
  lastButtonState3 = buttonState3;
  lastButtonState4 = buttonState4;

}



