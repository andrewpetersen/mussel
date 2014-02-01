/*
  Jan 31, 2014
  Andrew Petersen, 
  Electrical Engineering Senior Project 
 */

//pin definitions
const int pVcc = A0;  //Pin for Vcc
const int pVo = A5;   //Pin for Vo

const float R = 19580; //Known resistor, in Ohms

int Vcc = 0;      
int Vo = 0;
float Rt = 0;
float I = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  Vcc = analogRead(pVcc);            
  Vo = analogRead(pVo);            
  
  //outputValue = map(sensorValue, 0, 1023, 0, 255);  
 // analogWrite(analogOutPin, outputValue);           
  I = (Vcc - Vo)/R;
  Rt = Vo/I;
  
  
  // print the results to the serial monitor:
  Serial.print("Vcc = ");                       
  Serial.print(Vcc);      
  Serial.print("  Vo = ");                       
  Serial.print(Vo);      
  Serial.print("  Rt = ");      
  Serial.println(int(Rt));   

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(200);                     
}
