/*
inspired by http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1287148367
*/

int calibrationTime = 30;

long unsigned int lowIn;

long unsigned int pause = 1000;

byte motionCounter = 0;

int pirPin = 2;    
int ledPin = 9;
//SETUP
void setup(){
 Serial.begin(9600);
 pinMode(pirPin, INPUT);
 pinMode(ledPin, OUTPUT);
 digitalWrite(pirPin, LOW);  

 Serial.print("calibrating sensor ");
   for(int i = 0; i < calibrationTime; i++){
   Serial.print(".");
   delay(1000);
   }
   Serial.println(" done");
   Serial.println("SENSOR ACTIVE");
   delay(50);
 }

////////////////////////////
//LOOP

void loop(){
  if(digitalRead(pirPin) == HIGH){
    Serial.println("Continuous motion ended.");
    motionCounter = 0;
    digitalWrite(ledPin, LOW);
  }
  else if(digitalRead(pirPin) == LOW){
    motionCounter += 1;  
    Serial.print("Single motion detected ");
    Serial.print(motionCounter);
    Serial.println(" times in a row.");
  }
  if(motionCounter > 5){
    Serial.println("Continuous motion detected!");
    digitalWrite(ledPin, HIGH);
  }
  delay(pause);  
}
