//Analog pin used to find resistance
int Apin=7;

//values of r1 to r5
float r1=1000;
float r2=4700;
float r3=10000;
float r4=47000;
float r5=100000;

//pins of r1 to r5
int r1_pin=2;
int r2_pin=3;
int r3_pin=4;
int r4_pin=5;
int r5_pin=6;


float reading=0; //read from analog pin and store here
float R=0;       //calculate unknown and store here

String finalR;   //final value to be displayed along with units

int caseno;   //for debugging, stores the case number
              // we divide the entire range into cases and assign each a number, total 5 cases
              // case1 : less than 2850
              // case2 : 2850  to   7350
              // case3 : 7350  to   28500
              // case4 : 28500 to   73500
              // case5 : more than 73500

#include <stdlib.h> // needed for converting float to string, has the String(float,n) function. Explained below.

void setup() {
 Serial.begin(9600);

}

void loop() {

  //first we find unknown resistance using 1kOhm resistor
  //Therefore, disable R2, R3, R4 and R5
   digitalWrite(r2_pin, LOW);   //turn each pin to LOW before setting it as INPUT
   pinMode(r2_pin, INPUT);      // turning it INPUT when its HIGH enables the internal pullup resistor 
     
   digitalWrite(r3_pin, LOW);
   pinMode(r3_pin, INPUT);
   
   digitalWrite(r4_pin, LOW);
   pinMode(r4_pin, INPUT);
  
   digitalWrite(r5_pin, LOW);
   pinMode(r5_pin, INPUT);
   
   pinMode(r1_pin, OUTPUT);
   digitalWrite(r1_pin, HIGH);  

 
   //read and calculate resistance
   reading=analogRead(Apin);
   R=(reading*r1)/(1023-reading);

   // if value < 2850, finalR = value(using 1kOhm)
  if(R<2850){
    
    caseno=1;
    
      if(R<1000){ //if value less than 1000 use "Ohm" not "kOhm"                   
      finalR = String(R,2) + "Ohm";  //String(float,n) Converting float to string with n digits after decimal
                                     // attach "Ohm" after value to the string, '+' joins two strings here
    }
    else{ //use "kOhm
      R=R/1000;
      finalR = String(R,2) + "kOhm";
    }
  }

  
  //if value between 2850 and 7350 , use value obtained by 4.7kOhm 
  else if(R>=2850 && R<7350){
     caseno=2; 
     
   digitalWrite(r1_pin, LOW);  //Enable only 4.7kOhm
   pinMode(r1_pin, INPUT);
     
   digitalWrite(r3_pin, LOW);
   pinMode(r3_pin, INPUT);
   
   digitalWrite(r4_pin, LOW);
   pinMode(r4_pin, INPUT);
  
   digitalWrite(r5_pin, LOW);
   pinMode(r5_pin, INPUT);
   
   pinMode(r2_pin, OUTPUT);
   digitalWrite(r2_pin, HIGH);
   
   reading=analogRead(Apin);  
   R=(reading*r2)/(1023-reading)/1000;
   finalR = String(R,2) + "kOhm"; 
   
  }

  //if value between 7350 and 28500, use value obtained by 10kOhm
  else if(R>=7350 && R<28500){
      caseno=3;
      
   digitalWrite(r1_pin, LOW);
   pinMode(r1_pin, INPUT);
     
   digitalWrite(r2_pin, LOW);
   pinMode(r2_pin, INPUT);
   
   digitalWrite(r4_pin, LOW);
   pinMode(r4_pin, INPUT);
  
   digitalWrite(r5_pin, LOW);
   pinMode(r5_pin, INPUT);
   
   pinMode(r3_pin, OUTPUT);
   digitalWrite(r3_pin, HIGH);

   reading=analogRead(Apin); 
   R=(reading*r3)/(1023-reading)/1000;
   finalR= String(R,2) + "kOhm";
  }
  
  //if value between 28500 and 73500, use value obtained by 47kOhm
  else if(R>=28500 && R<73500){
       caseno=4;
       
   digitalWrite(r1_pin, LOW);
   pinMode(r1_pin, INPUT);
     
   digitalWrite(r2_pin, LOW);
   pinMode(r2_pin, INPUT);
   
   digitalWrite(r3_pin, LOW);
   pinMode(r3_pin, INPUT);
  
   digitalWrite(r5_pin, LOW);
   pinMode(r5_pin, INPUT);
   
   pinMode(r4_pin, OUTPUT);
   digitalWrite(r4_pin, HIGH);

   reading=analogRead(Apin); 
   R=(reading*r4)/(1023-reading)/1000;
   finalR = String(R,2) + "kOhm";

  }

  //if value more than 73500, use value obtained by 100kOhm
  else if(R>=73500){
       caseno=5;
       
   digitalWrite(r1_pin, LOW);
   pinMode(r1_pin, INPUT);
     
   digitalWrite(r2_pin, LOW);
   pinMode(r2_pin, INPUT);
   
   digitalWrite(r3_pin, LOW);
   pinMode(r3_pin, INPUT);
  
   digitalWrite(r4_pin, LOW);
   pinMode(r4_pin, INPUT);
   
   pinMode(r5_pin, OUTPUT);
   digitalWrite(r5_pin, HIGH);

   reading=analogRead(Apin);   
   R=(reading*r5)/(1023-reading)/1000;
   finalR = String(R,2) + "kOhm" ;

  }

   
 
   
   Serial.println(finalR); //printing the final string with units
   Serial.println(" ");

   delay(1000);

  

 

}
