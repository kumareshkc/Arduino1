// this code is used to switch between the four leds and the menu is being created for the same 
// this code is INCOMPLETE !!! 

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);

// initialise the buttons 

const int buttonPin1 = 2;
const int buttonPin2 = 4;
const int buttonPin3 = 5;
const int buttonPin4 = 8;

//initialise the outputs 

const int enable1 = 11;
const int enable2 = 10;
const int enable3 = 9;
const int enable4 = 6;

// initialise the input for the leds

int x = 5;

// initialise the counter for choosing the leds 

int buttonPushCounter = 0;

// counter for choosing the brightness of the leds  

int buttonPushCounter1 = 0;   

// initialise the status for all the buttons 

int buttonState1 = 0;         // current state of the button 1
int lastButtonState1 = 0;     // previous state of the button1

int buttonState2 = 0;         // current state of the button2
int lastButtonState2 = 0;     // previous state of the button2

int buttonState3 = 0;         // current state of the button3
int lastButtonState3 = 0;     // previous state of the button3

int buttonState4 = 0;         // current state of the button4
int lastButtonState4 = 0;     // previous state of the button4

//initialise the states of the leds 

int blueLedState1 = 0;
int yellowLedState1 = 0;
int greenLedState1 = 0;
int redLedState1 = 0;

int blueLedState2 = 0;
int yellowLedState2 = 0;
int greenLedState2 = 0;
int redLedState2 = 0;

// initialise the confirmation of the led 

int blueLedConfirmation = 0;
int yellowLedConfirmation = 0;
int greenLedConfirmation = 0;
int redLedConfirmation = 0;

// initialise the brightness confirmation for the leds

int blueLedBrightnessConfirmation = 0;
int yellowLedBrightnessConfirmation = 0;
int greenLedBrightnessConfirmation = 0;
int redLedBrightnessConfirmation = 0;


void setup()

  {
    Serial.begin(115200);   // Initialize virtual COM port
    // initialise the input pins 
    pinMode(buttonPin1, INPUT_PULLUP);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    pinMode(buttonPin2, INPUT_PULLUP);
    pinMode(buttonPin3, INPUT_PULLUP);
    pinMode(buttonPin4, INPUT_PULLUP);
    //initialise the output pins 
    pinMode(enable1, OUTPUT);
    pinMode(enable2, OUTPUT);
    pinMode(enable3, OUTPUT);
    pinMode(enable4, OUTPUT);
    // initially all the leds are off 
    digitalWrite(enable1 ,LOW);  
    digitalWrite(enable2 ,LOW);
    digitalWrite(enable3 ,LOW);  
    digitalWrite(enable4 ,LOW);
    // initialise the lcd 
    delay(500);
    lcd.begin();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(7,1);
    lcd.print("HELLO");
    delay(2000);
    lcd.clear();
    lcd.setCursor(7,1);
    lcd.print("WELCOME");
    delay(2000);
    lcd.clear();
    }
    
void loop()

{
  // will be printed all the time 
  lcd.setCursor(0,0);
  lcd.print("CHOOSE YOUR COLOUR");
  delay(100);

////////////////////CHOOSING THE LED /////////////////////////////////////////////////////  

buttonState1 = digitalRead(buttonPin1);
  
     if (buttonState1 != lastButtonState1)
       {
        if (buttonState1 == LOW)
       {
        if (buttonPushCounter < 5)
         {
          buttonPushCounter++;
         }
       }
     }
  
buttonState2 = digitalRead(buttonPin2);
  
     if (buttonState2 != lastButtonState2)
         {
         if (buttonState2 == LOW)
           {
           if (buttonPushCounter > 0)
            {
             buttonPushCounter--;
           }
        }
     }

////////////////////CHOOSING THE LED /////////////////////////////////////////////////////



/////////////////////////////BLUE LED ///////////////////////////////////////////////////


if (buttonPushCounter == 1)
    {
       lcd.setCursor(0, 3); //Set cursor to first column of second row
       lcd.print("                     "); //Print blanks to clear the row
       lcd.setCursor(0,3);
       lcd.print("BLUE LED");
       digitalWrite(enable1 ,HIGH);
       digitalWrite(enable2 ,LOW);
       digitalWrite(enable3 ,LOW);
       digitalWrite(enable4 ,LOW);
       
 blueLedConfirmation= digitalRead(buttonPin3);  
 
if (blueLedConfirmation == LOW)
          {
          lcd.clear();
          lcd.setCursor(0,1);
          lcd.print("YOU HAVE CHOSEN");
          delay(1000);
          lcd.setCursor(0,2);
          lcd.clear();
          lcd.print("BLUE LED");
          //analogWrite(enable1, x);

       blueLedState1 = digitalRead(buttonPin1);

       if (blueLedState1 != lastButtonState1)
          {
           if (blueLedState1 == LOW)
            {
             if (buttonPushCounter1 < 24)
             {
             x = x + 10;
   
             //analogWrite(enable1, x);
             buttonPushCounter1++;
             lcd.setCursor(0, 1); //Set cursor to first column of second row
             lcd.print("CHOOSE YOUR BRIGHTNESS"); //Print blanks to clear the row
             lcd.setCursor(0, 2);
             lcd.print(x);
             }
           }
         }

blueLedState2 = digitalRead(buttonPin2);


  if (blueLedState2 != lastButtonState2)
  {
    if (blueLedState2 == LOW)
    {
      if (buttonPushCounter1 > 0)
      {
        x = x - 10;
       // analogWrite(enable1, x);
        buttonPushCounter1--;
        lcd.setCursor(0, 1); //Set cursor to first column of second row
        lcd.print("CHOOSE YOUR BRIGHTNESS"); //Print blanks to clear the row
        lcd.setCursor(0, 2);
        lcd.print(x);
       }
       }
       }
 else if (buttonPushCounter1 == 0)
    {
      analogWrite(enable1 , 0);
       
    // Delay a little bit to avoid bouncing
    delay(50);
  }

blueLedBrightnessConfirmation = digitalRead(buttonPin3);
  {
    if (blueLedBrightnessConfirmation == LOW)
    {
      analogWrite(enable1 , x);
      lcd.setCursor(0, 1); //Set cursor to first column of second row
      lcd.print("                "); //Print blanks to clear the row
      lcd.setCursor(0, 3);  //Set Cursor again to first column of second row
      lcd.print(" BLUE LED IS ON NOW");  //Print your units.
    }
  }
   }
    // Delay a little bit to avoid bouncing
    delay(50);
  }

//////////////////////////BLUE LED ////////////////////////////////////////////////////////////  



/////////////////////////YELLOW LED ///////////////////////////////////////////////////////////


if (buttonPushCounter == 2)
    {
       lcd.setCursor(0, 3); //Set cursor to first column of second row
       lcd.print("                     "); //Print blanks to clear the row
       lcd.setCursor(0,3);
       lcd.print("YELLOW LED");
       digitalWrite(enable1 ,LOW);
       digitalWrite(enable2 ,HIGH);
       digitalWrite(enable3 ,LOW);
       digitalWrite(enable4 ,LOW);
  
 yellowLedConfirmation= digitalRead(buttonPin3);  
 
if (yellowLedConfirmation == LOW)
          {
          lcd.clear();
          lcd.setCursor(0,1);
          lcd.print("YOU HAVE CHOSEN");
          delay(1000);
          lcd.setCursor(0,2);
          lcd.clear();
          lcd.print("YELLOW LED");
          //analogWrite(enable2, x);

       yellowLedState1 = digitalRead(buttonPin1);

       if (yellowLedState1 != lastButtonState1)
          {
           if (yellowLedState1 == LOW)
            {
             if (buttonPushCounter1 < 24)
             {
             x = x + 10;
   
             //analogWrite(enable2, x);
             buttonPushCounter1++;
             lcd.setCursor(0, 1); //Set cursor to first column of second row
             lcd.print("CHOOSE BRIGHTNESS"); //Print blanks to clear the row
             lcd.setCursor(0, 2);
             lcd.print(x);
             }
           }
         }

yellowLedState2 = digitalRead(buttonPin2);

  if (yellowLedState2 != lastButtonState2)
  {
    if (yellowLedState2 == LOW)
    {
      if (buttonPushCounter1 > 0)
      {
        x = x - 10;
       // analogWrite(enable2, x);
        buttonPushCounter1--;
        lcd.setCursor(0, 1); //Set cursor to first column of second row
        lcd.print("CHOOSE BRIGHTNESS"); //Print blanks to clear the row
        lcd.setCursor(0, 2);
        lcd.print(x);
       }
       }
       }
 else if (buttonPushCounter1 == 0)
    {
      analogWrite(enable2 , 0);
       
    // Delay a little bit to avoid bouncing
    delay(50);
  }

yellowLedBrightnessConfirmation = digitalRead(buttonPin3);
  {
    if (yellowLedBrightnessConfirmation == LOW)
    {
      analogWrite(enable2 , x);
      lcd.setCursor(0, 1); //Set cursor to first column of second row
      lcd.print("                "); //Print blanks to clear the row
      lcd.setCursor(0, 3);  //Set Cursor again to first column of second row
      lcd.print("YELLOW LED IS ON NOW");  //Print your units.
    }
  }
   }
    // Delay a little bit to avoid bouncing
    delay(50);
  }

//////////////////////////YELLOW LED ////////////////////////////////////////////////////////////  


/////////////////////////GREEN LED //////////////////////////////////////////////////////////////


if (buttonPushCounter == 3)
    {
       lcd.setCursor(0, 3); //Set cursor to first column of second row
       lcd.print("                     "); //Print blanks to clear the row
       lcd.setCursor(0,3);
       lcd.print("GREEN LED");
       digitalWrite(enable1 ,LOW);
       digitalWrite(enable2 ,LOW);
       digitalWrite(enable3 ,HIGH);
       digitalWrite(enable4 ,LOW);
  
       greenLedConfirmation= digitalRead(buttonPin3);  
 
if (greenLedConfirmation == LOW)
          {
          lcd.clear();
          lcd.setCursor(0,1);
          lcd.print("YOU HAVE CHOSEN");
          delay(1000);
          lcd.setCursor(0,2);
          lcd.clear();
          lcd.print("GREEN LED");
          //analogWrite(enable3, x);

       greenLedState1 = digitalRead(buttonPin1);

       if (greenLedState1 != lastButtonState1)
          {
           if (greenLedState1 == LOW)
            {
             if (buttonPushCounter1 < 24)
             {
             x = x + 10;
   
             //analogWrite(enable3, x);
             buttonPushCounter1++;
             lcd.setCursor(0, 1); //Set cursor to first column of second row
             lcd.print("CHOOSE BRIGHTNESS"); //Print blanks to clear the row
             lcd.setCursor(0, 2);
             lcd.print(x);
             }
           }
         }

greenLedState2 = digitalRead(buttonPin2);

  if (greenLedState2 != lastButtonState2)
  {
    if (greenLedState2 == LOW)
    {
      if (buttonPushCounter1 > 0)
      {
        x = x - 10;
       // analogWrite(enable3, x);
        buttonPushCounter1--;
        lcd.setCursor(0, 1); //Set cursor to first column of second row
        lcd.print("CHOOSE BRIGHTNESS"); //Print blanks to clear the row
        lcd.setCursor(0, 2);
        lcd.print(x);
       }
       }
       }
 else if (buttonPushCounter1 == 0)
    {
      analogWrite(enable3 , 0);
       
    // Delay a little bit to avoid bouncing
    delay(50);
  }

greenLedBrightnessConfirmation = digitalRead(buttonPin3);
  {
    if (greenLedBrightnessConfirmation == LOW)
    {
      analogWrite(enable3 , x);
      lcd.setCursor(0, 1); //Set cursor to first column of second row
      lcd.print("                "); //Print blanks to clear the row
      lcd.setCursor(0, 3);  //Set Cursor again to first column of second row
      lcd.print("GREEN LED IS ON NOW");  //Print your units.
    }
  }
   }
    // Delay a little bit to avoid bouncing
    delay(50);
  }

//////////////////////////GREEN LED ////////////////////////////////////////////////////////////  


/////////////////////////RED LED ///////////////////////////////////////////////////////////


if (buttonPushCounter == 4)
    {
       lcd.setCursor(0, 3); //Set cursor to first column of second row
       lcd.print("                     "); //Print blanks to clear the row
       lcd.setCursor(0,3);
       lcd.print("RED LED");
       digitalWrite(enable1 ,LOW);
       digitalWrite(enable2 ,LOW);
       digitalWrite(enable3 ,LOW);
       digitalWrite(enable4 ,HIGH);
  
         redLedConfirmation= digitalRead(buttonPin3);  
 
if (redLedConfirmation == LOW)
          {
          lcd.clear();
          lcd.setCursor(0,1);
          lcd.print("YOU HAVE CHOSEN");
          delay(1000);
          lcd.setCursor(0,2);
          lcd.clear();
          lcd.print("RED LED");
          //analogWrite(enable4, x);

       redLedState1 = digitalRead(buttonPin1);

       if (redLedState1 != lastButtonState1)
          {
           if (redLedState1 == LOW)
            {
             if (buttonPushCounter1 < 24)
             {
             x = x + 10;
   
             //analogWrite(enable4, x);
             buttonPushCounter1++;
             lcd.setCursor(0, 1); //Set cursor to first column of second row
             lcd.print("CHOOSE BRIGHTNESS"); //Print blanks to clear the row
             lcd.setCursor(0, 2);
             lcd.print(x);
             }
           }
         }

redLedState2 = digitalRead(buttonPin2);

  if (redLedState2 != lastButtonState2)
  {
    if (redLedState2 == LOW)
    {
      if (buttonPushCounter1 > 0)
      {
        x = x - 10;
       // analogWrite(enable4, x);
        buttonPushCounter1--;
        lcd.setCursor(0, 1); //Set cursor to first column of second row
        lcd.print("CHOOSE BRIGHTNESS"); //Print blanks to clear the row
        lcd.setCursor(0, 2);
        lcd.print(x);
       }
       }
       }
 else if (buttonPushCounter1 == 0)
    {
      analogWrite(enable4 , 0);
       
    // Delay a little bit to avoid bouncing
    delay(50);
  }

redLedBrightnessConfirmation = digitalRead(buttonPin3);
  {
    if (redLedBrightnessConfirmation == LOW)
    {
      analogWrite(enable4 , x);
      lcd.setCursor(0, 1); //Set cursor to first column of second row
      lcd.print("                "); //Print blanks to clear the row
      lcd.setCursor(0, 3);  //Set Cursor again to first column of second row
      lcd.print("RED LED IS ON NOW");  //Print your units.
    }
  }
   }
    // Delay a little bit to avoid bouncing
    delay(50);
  }


//////////////////////////RED LED ////////////////////////////////////////////////////////////  



///////////////////////////CONDITION FOR EXIT////////////////////////////////////////////////////

buttonState4 = digitalRead(buttonPin4);
  {
    if (buttonState4 == LOW)
    {
      lcd.clear();
      lcd.setCursor(0, 1); //Set cursor to first column of second row
      lcd.print("                "); //Print blanks to clear the row
      lcd.setCursor(6, 1);  //Set Cursor again to first column of second row
      lcd.print("THANK YOU");  //Print your units.
      digitalWrite(enable1 ,HIGH);
      digitalWrite(enable2 ,HIGH);
      digitalWrite(enable3 ,HIGH);
      digitalWrite(enable4 ,HIGH);
      delay(2000);
      digitalWrite(enable1 ,LOW);
      digitalWrite(enable2 ,LOW);
      digitalWrite(enable3 ,LOW);
      digitalWrite(enable4 ,LOW);
      delay(200);
      digitalWrite(enable1 ,HIGH);
      digitalWrite(enable2 ,HIGH);
      digitalWrite(enable3 ,HIGH);
      digitalWrite(enable4 ,HIGH);
      delay(200);
      digitalWrite(enable1 ,LOW);
      digitalWrite(enable2 ,LOW);
      digitalWrite(enable3 ,LOW);
      digitalWrite(enable4 ,LOW);
      delay(200);
      digitalWrite(enable1 ,HIGH);
      digitalWrite(enable2 ,HIGH);
      digitalWrite(enable3 ,HIGH);
      digitalWrite(enable4 ,HIGH);
      delay(200);
      digitalWrite(enable1 ,LOW);
      digitalWrite(enable2 ,LOW);
      digitalWrite(enable3 ,LOW);
      digitalWrite(enable4 ,LOW);
      delay(200);
      digitalWrite(enable1 ,HIGH);
      digitalWrite(enable2 ,HIGH);
      digitalWrite(enable3 ,HIGH);
      digitalWrite(enable4 ,HIGH);
      delay(200);
      digitalWrite(enable1 ,LOW);
      digitalWrite(enable2 ,LOW);
      digitalWrite(enable3 ,LOW);
      digitalWrite(enable4 ,LOW);
      delay(1000);
      lcd.clear();
    }
  }
  
////////////////////CONDITION FOR EXIT/////////////////////////////////////////////////////////

  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
  lastButtonState3 = buttonState3;
  lastButtonState4 = buttonState4;
}


