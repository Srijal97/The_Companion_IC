/*  RCTiming_capacitance_meter
 *  code concept taken from Paul Badger 2008
 *  
 *    The capacitor's voltage at one time constant is defined as 63.2% of the charging voltage.
 *    i.e, A Capacitor is filled to 63.2% of its total capacity in 1 Time Constant
 */

 int analogPin=0 ;         // analog pin for measuring capacitor voltage
 int chargePin=7 ;        // pin to charge the capacitor - connected to one end of the charging resistor
 int dischargePin=12 ;        // pin to discharge the capacitor, same used for diode test(chechPin1)
 float resistorValue=10000.0;   // We use 10kOhm resistor
                                  
 unsigned long startTime;
 unsigned long elapsedTime;
 float microFarads;                // floating point variable to preserve precision, make calculations
 float nanoFarads;

void setup(){

  pinMode(chargePin, OUTPUT);     // set chargePin to output
  digitalWrite(chargePin, LOW);  

  Serial.begin(9600);             // initialize serial transmission for debugging
}

void loop(){
 
  digitalWrite(chargePin, HIGH);  // set chargePin HIGH and capacitor charging
  startTime = millis();

  while(analogRead(analogPin) < 648){       // 647 is 63.2% of 1023, which corresponds to full-scale voltage 
  }

  elapsedTime= millis() - startTime;
 // convert milliseconds to seconds ( 10^-3 ) and Farads to microFarads ( 10^6 ),  net 10^3 (1000)  
  microFarads = ((float)elapsedTime / resistorValue) * 1000;  // (float) converts "unsigned long" elapsed time to float
  Serial.print(elapsedTime);       // print the value to serial port
  Serial.print(" mS    ");         // print units


  if (microFarads > 1){
    Serial.print((long)microFarads);       // print the value to serial port
    Serial.println(" microFarads");         // print units
  }
  else
  {
    // if value is smaller than one microFarad, convert to nanoFarads (10^-9 Farad). 

    nanoFarads = microFarads * 1000.0;      // multiply by 1000 to convert to nanoFarads (10^-9 Farads)
    Serial.print((long)nanoFarads);         // print the value to serial port
    Serial.println(" nanoFarads");          // print units
  }

  /* dicharge the capacitor  */
  digitalWrite(chargePin, LOW);             // set charge pin to  LOW 
  pinMode(dischargePin, OUTPUT);            // set discharge pin to output 
  digitalWrite(dischargePin, LOW);          // set discharge pin LOW 
  while(analogRead(analogPin) > 0){         // wait until capacitor is completely discharged
  }

  pinMode(dischargePin, INPUT);            // set discharge pin back to input
}
