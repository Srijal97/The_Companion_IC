/* if((time1-time2)> x){ //code }
   is just a delay of x millisecond, but it improves button response
   In delay(x) , the program stops and waits for x milliseconds but here,
   it runs through the whole loop in main file till the condition is satisfied
   In this way, button state is checked even when its waiting */


int diodeTest(){
 time1 = millis();
 if((time1-time2)>600){
   pinMode(checkPin1, OUTPUT);
   digitalWrite(checkPin1, LOW);

 //analog read is normally pulled up by the 10k resistor, so null reading is 1023
 //In forward bias, the analog pin gets connected to checkPin1, which is LOW. So reading less than 1023
 //Practically a small current flows in reverse bias as well, so we take 700 to differentiate
   if(analogRead(checkPin2)<700){
     state="    Forward";
     stateCase=1;
   }
 
   if(stateCase==1){
     lcd.clear();
     lcd.print(state);
     lcd.setCursor(0,1);
     lcd.print("    ---");
     
 
     lcd.write(byte(1)); //printing the diode custom character
     lcd.print("---     ");
   }
   
   else{
     lcd.clear();
     lcd.print(state);
     lcd.setCursor(0,1);
     lcd.print("    --- ");
  
     lcd.print("---     ");
   }
   
  state = "     null";
  stateCase=0;
  
  time2 = millis();
 }
 
}

