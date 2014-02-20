	/*
  Electric Eel
  The code used for the electric eel digital condom prototype
  hacked from blink examples ...etc
  
  measures input from a resistive sensor (like the breath sensor). 
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
float speedtopulse= 10;
float sensorValue = 0;
int sensorPin = A1;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
for(int j=0; j<14;j++){
  pinMode(j, OUTPUT);

}  
  Serial.begin(9600);
  
}

// the loop routine runs over and over again forever:
void loop() {
  sensorValue = analogRead(sensorPin);
  speedtopulse = ((sensorValue/200)*100);
Serial.println(speedtopulse);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(speedtopulse);               // wait for a second
  digitalWrite(led, LOW);    // taurn the LED off by making the voltage LOW
  delay(speedtopulse);               // wait for a second
  
  
    digitalWrite(led-1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(speedtopulse);               // wait for a second
  digitalWrite(led-1, LOW);    // turn the LED off by making the voltage LOW
  delay(speedtopulse);               // wait for a second
  
led++;
  if(led >13){led=0;}

}
