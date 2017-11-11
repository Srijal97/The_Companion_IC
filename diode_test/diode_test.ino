String state = "null";

int checkPin1 = 12;
int checkPin2 = 6;


void setup() {
  Serial.begin(9600);

}

void loop() {

pinMode(checkPin1, OUTPUT); 
digitalWrite(checkPin1, LOW); //pin 11 is set to low

//analog read is normally pulled up by the 10k resistor, so null reading is 1023
//In forward bias, the analog pin gets connected to checkPin1, which is LOW. So reading less than 1023
//Practically a small current flows in reverse bias as well, so we take 700 to differentiate

  if(analogRead(checkPin2)<700){ 
    state="forward";
   
  }
 

 Serial.println(state);
 Serial.println(analogRead(checkPin2));
 state = "null";
 delay(500);


}
