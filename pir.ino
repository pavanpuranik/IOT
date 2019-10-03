int calibrationTime=30;
long unsigned int lowln;
long unsigned int pause=5000;
boolean lockLow=true;
boolean takeLowTime;
int pirPin=3;
int ledPin=13;

void setup()
{
  Serial.begin(9600);
  pinMode(pirPin,INPUT);
  pinMode(ledPin,OUTPUT);
  digitalWrite(pirPin,LOW);
  Serial.print("Calibrating Sensor..");
  for(int i=0;i<calibrationTime;i++)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Done");
  Serial.println("Sensor Action");
  delay(50);
}
void loop()
{
  if(digitalRead(pirPin)==HIGH)
  {
    digitalWrite(ledPin,HIGH);
    if(lockLow)
    {
      lockLow=false;
      Serial.println("........");
      Serial.println("Motion Detected at ");
      Serial.println(millis()/1000);
      Serial.println("secs");
      delay(50);
    }
    takeLowTime=true;
  }
  if(digitalRead(pirPin)==LOW)
  {
    digitalWrite(ledPin,LOW);
    if(takeLowTime)
    {
      lowln=millis();
      takeLowTime=false;
    }
    if(lockLow && millis()-lowln>pause)
    {
      lockLow=true;
      Serial.println("Motion ended at ");
      Serial.println((millis()-pause)/1000);
      Serial.println("secs");
      delay(50);
    }
  }
}
    
