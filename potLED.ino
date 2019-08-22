const int analogPinIn = A0;
const int analogPinOut = 9;

int sensorValue = 0;
int outputValue = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  sensorValue = analogRead(analogPinIn);
  outputValue = map(sensorValue, 0, 1023, 0, 253);
  analogWrite(analogPinOut, outputValue);
  
  Serial.print("Sensor=");
  Serial.print(sensorValue);
  Serial.print("Output=");
  Serial.print(outputValue);
  
  delay(10);
}
