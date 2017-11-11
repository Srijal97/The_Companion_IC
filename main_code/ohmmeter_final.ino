
#include <stdlib.h> // needed for converting float to string, has the String(float,n) function. Explained below.

/* if((time1-time2)> x){ //code }
   is just a delay of x millisecond, but it improves button response
   In delay(x) , the program stops and waits for x milliseconds but here,
   it runs through the whole loop in main file till the condition is satisfied
   In this way, button state is checked even when its waiting */
   
int findResistance(){
time1 = millis();

  if((time1-time2)> 500){
     //first we find unknown resistance using 1kOhm resistor
     //Therefore, disable R2, R3, R4 and R5
     digitalWrite(r2_pin, LOW);
     pinMode(r2_pin, INPUT);
     
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

     // case1: if value < 2850, finalR=value (using 1kOhm)
    if(R<2850){
    
       caseno=1;
    
       if(R<1000){ //if value less than 1000 use "Ohm" not "kOhm"                   
         finalR = String(R,2) ;  //String(float,n) Converting float to string with n digits after decimal
                                    
       }
       else{ //use "kOhm
         float x = R/1000;  //we dont use R=R/100 as R value may be needed for other tests
                         
         finalR = String(x,2) + "k"; // attach "k" after value to the string, '+' joins two strings here
       }
     }

  
    //case2: if value between 2850 and 7350 , use value obtained by 4.7kOhm 
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
       R=(reading*r2)/(1023-reading);
       float x = R/1000;
       finalR = String(x,2) + "k"; 
   
     }

    //case3: if value between 7350 and 28500, use value obtained by 10kOhm
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
       R=(reading*r3)/(1023-reading);
       float x =R/1000;
       finalR= String(x,2) + "k";
     }
  
    //case4: if value between 28500 and 73500, use value obtained by 47kOhm
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
       R=(reading*r4)/(1023-reading);
       float x = R/1000;
       finalR = String(x,2) + "k";

     }

    //case5: if value more than 73500, use value obtained by 100kOhm
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
       R=(reading*r5)/(1023-reading);
       float x= R/1000;
       finalR = String(x,2) + "k" ;

     }


   lcd.clear();
   lcd.setCursor(2,0);
   lcd.print("Resistance");
   lcd.setCursor(3,1);
   lcd.print(finalR);

   lcd.write(byte(0)); // 0 contains the omega character, characters are written with lcd.write();
  
  time2 = millis();
 }

}
