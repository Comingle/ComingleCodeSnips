/*
Comingle{♥}
Polar Heart Rate Sensor

NOTE!!!: the GND and + designations are WRONG on the PCB
here is a correct diagram
|--------------------------------|
| ^            Heart beat Output |>
| Top of the PCB       Vin (3-5v)|>
|                        GND     |>
|--------------------------------|

The Digital read doesn't always work properly with all boards. This one uses an analog input and a threshold
Adapted from the Parallax Tutorial via adafruit
*/

//Definitions  
const int HR_RX = A2;
int oldSample, sample;
int led=13;
int beatThreshold = 50;
void setup() {
  Serial.begin(9600);
  pinMode (HR_RX, INPUT);  //Signal pin to input  
 
  Serial.println("Waiting for heart beat...");
while(!analogRead(HR_RX)>beatThreshold){};
 Serial.println ("Heart beat detected!  ");
 
}

void loop() {
  sample = analogRead(HR_RX);
  if(sample>beatThreshold&&sample>oldSample+50){
    Serial.print("Beat    ");
 Serial.println(sample);
        digitalWrite(13,HIGH);
  }
    digitalWrite(13,LOW);
  oldSample = sample;           //Store last signal received 

  /*
  sample = digitalRead(HR_RX);  //Store signal output 
 analogRead(HR_RX));
  if (sample && (oldSample != sample)) {
    Serial.println("Beat");
    digitalWrite(13,HIGH);
  }
  digitalWrite(13,LOW);
  oldSample = sample;           //Store last signal received 
 */ 
}
