/* if((time1-time2)> x){ //code }
   is just a delay of x millisecond, but it improves button response
   In delay(x) , the program stops and waits for x milliseconds but here,
   it runs through the whole loop in main file till the condition is satisfied
   In this way, button state is checked even when its waiting */
 
int Clock(){
 DateTime now = rtc.now();
 time1 = millis();  
 if((time1-time2) > 500){ 
    lcd.clear();
    lcd.setCursor(4,0);
    
    if(now.hour()<10){
        lcd.print("0"); // I want it to print 01, not 1
    }
    //converting to 12 hour format.
    //for 24hr format just use lcd.print(now.hour());
    if(now.hour()>12){                        
        lcd.print(now.hour()-12);  
    } 
    else{
        lcd.print(now.hour());
    }
    
    // for blinking the semicolon every 500ms
    if(Blink){   //if 'Blink' is true 
     lcd.print(":"); 
    } 
    else{
      lcd.print(" ");
    }
    
     if(now.minute()<10){ //I want it to print 01, not 1
      lcd.print("0");   
     }
     lcd.print(now.minute());

     //AM or PM
     if(now.hour()>12){ 
        lcd.print(" PM");
     }
     else{
        lcd.print(" AM");
     }

     lcd.setCursor(0,1);
     lcd.print(daysOfTheWeek[now.dayOfTheWeek()]); // now.dayOfTheWeek returns 0-6 for Sunday to Saturday
                                                   // daysOfTheWeek[] is an array containing weekday names
                                                   // so Sunday is daysOfTheWeek[0]
     lcd.print(", ");
     lcd.print(now.day());
     lcd.print(" ");
     lcd.print(months[now.month()-1]);             // now.month returns 1-12 for Jan to Dec
                                                   // months[] is an array containing month names
                                                   // so Jan is months[0], i.e, months[1-1]

     Blink=!Blink; 

     time2 = millis();
   }
 

}                        


