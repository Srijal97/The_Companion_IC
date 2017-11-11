//for mode change 
    
    const int  buttonPin = 11;    // the that the pushbutton is attached to
   
    int mode = 0;   // counter for the number of button presses
    int buttonState = 0;         // current state of the button
    int lastButtonState = 0;     // previous state of the button


//for clock

    //array containing days of the week for printing
    char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; 
    //array containing month names for printing
    char months[12][12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
//for ohm meter

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
 

   
   int caseno;   //for debugging, stores the case number
              // we divide the entire range into cases and assign each a number, total 5 cases
              // case1 : less than 2850
              // case2 : 2850 to 7350
              // case3 : 7350 to 28500
              // case4 :
              // case5 : more than 73500


//for capacitance meter

     int analogPin=0 ;         // analog pin for measuring capacitor voltage
     int chargePin=7 ;        // pin to charge the capacitor - connected to one end of the charging resistor
     int dischargePin=12 ;        // pin to discharge the capacitor
     float resistorValue=10000.0;   // We use 4.7kOhm resistor
                                  
     unsigned long startTime;
     unsigned long elapsedTime;
     float microFarads;                // floating point variable to preserve precision, make calculations
     float nanoFarads;



//for diode test
    
     int checkPin1 = 12;
     int checkPin2 = 6;  //analog pin 6
     int stateCase=0;
     
   


//used to prevent delayed button response from delay()
     float time1;
     float time2;


     
     
              
