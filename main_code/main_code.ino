#include "definations.h"    //including the header file which contains variable declarations
#include <LiquidCrystal.h>  //for LCD
#include <Wire.h>           //required for RTC
#include <RTClib.h>         //for RTC

            
RTC_DS1307 rtc; //creating "rtc" object of RTC_DS1307, objects are used to access functions
                //more on objects and classes: https://www.youtube.com/watch?v=ABRP_5RYhqU

boolean Blink = true;

byte Omega[8] = {  //creating custom character 'omega' for resistance units
        B00000,
        B01110,
        B10001,
        B10001,
        B10001,
        B01010,
        B11011,
        B00000
};

byte Diode[8] = { //diode symbol
        B10001,
        B11001,
        B10101,
        B10011,
        B10101,
        B11001,
        B10001,
        B00000
};

byte Micro[8] = { // micro sign
        B00000,
        B00000,
        B00000,
        B10010,
        B10010,
        B10010,
        B11100,
        B10000
};
String finalR = "null";   //final value of resistance to be displayed along with units is stored here
String state = "     null";  // used to store state for Diode test

// initialize the lcd library with the numbers of the interface pins
LiquidCrystal lcd(1, 0, 7, 8, 9, 10); //RS, E, D4, D5, D6, D7
  

void setup() {
   lcd.begin(16,2);
   lcd.createChar(0, Omega); //creating the omega character. 0 is the character number
                             //we can create 8 such characters numbered 0-7
                       
   lcd.createChar(1, Diode);
   lcd.createChar(2, Micro);
  lcd.clear();
  pinMode(buttonPin, INPUT);

    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); 
    
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));

  rtc.begin();
  
}

void loop() {


   
 buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) { // if the state has changed, increment the counter
              
    delay(50); //50ms delay to avoid switch bouncing
    
    if (buttonState == HIGH) {
                   // if the current state is still HIGH(after 50ms) then 
                   // increment mode
      mode++; 
      if(mode>3){ //we have only 4 modes (0-3), so repeat count if mode=4
        mode=0;
      }
    }
     
  }
 
  lastButtonState = buttonState;  // save the current state as the last state,
                                  //for next time through the loop

  
  if(mode==0){
   Clock();
  }
  if(mode==1){
   findResistance();
  }
  if(mode==2){
    findCapacitance();
  }
  if(mode==3){
    diodeTest();
  }

  
  

}
