/*  RCTiming_capacitance_meter
 *  code concept taken from Paul Badger 2008
 *  
 * Theory   A capcitor will charge, through a resistor, in one time constant, defined as T seconds where
 *    TC = R * C
 * 
 *    TC = time constant period in seconds
 *    R = resistance in ohms
 *    C = capacitance in farads (1 microfarad (ufd) = .0000001 farad = 10^-6 farads ) 
 *
 *    The capacitor's voltage at one time constant is defined as 63.2% of the charging voltage.
 *    i.e, A Capacitor is filled to 63.2% of its total capacity in 1 Time Constant
 */

 /* if((time1-time2)> x){ //code }
   is just a delay of x millisecond, but it improves button response
   In delay(x) , the program stops and waits for x milliseconds but here,
   it runs through the whole loop in main file till the condition is satisfied
   In this way, button state is checked even when its waiting */

int findCapacitance(){
time1 = millis();  

  if((time1-time2)>500){
    digitalWrite(chargePin, HIGH);
  
    pinMode(dischargePin, INPUT);            // set discharge pin to input
  

    startTime = millis();

       while(analogRead(analogPin) < 648){       // 647 is 63.2% of 1023, which corresponds to full-scale voltage 
       }

    elapsedTime= millis() - startTime;
    // convert milliseconds to seconds ( 10^-3 ) and Farads to microFarads ( 10^6 ),  net 10^3 (1000)  
    microFarads = ((float)elapsedTime / resistorValue) * 1000;  // (float) converts "unsigned long" elapsed time to float 
    digitalWrite(chargePin, LOW);      // set charge pin to  LOW   
  
    lcd.clear();
      if (microFarads > 1){
        lcd.setCursor(2,0);
        lcd.print("Capacitance");
        lcd.setCursor(3,1);
        lcd.print(microFarads);
        
  
        lcd.write(byte(2)); //printing the "micro" custom character
        lcd.print("F");
      }
      else
      {
        // if value is smaller than one microFarad, convert to nanoFarads (10^-9 Farad).  

        nanoFarads = microFarads * 1000.0; // multiply by 1000 to convert to nanoFarads (10^-9 Farads)
        lcd.setCursor(2,0);
        lcd.print("Capacitance");
        lcd.setCursor(3,1);
        lcd.print(nanoFarads);
     
        lcd.print("nF");
      }

    /* dicharge the capacitor  */
  
    pinMode(dischargePin, OUTPUT);            // set discharge pin to output 
    digitalWrite(dischargePin, LOW);     // set discharge pin LOW 
     
      while(analogRead(analogPin) > 0){  // wait until capacitor is completely discharged
      }
  
     pinMode(dischargePin, INPUT);// set discharge pin back to input  

    time2 = millis();
  }

}
