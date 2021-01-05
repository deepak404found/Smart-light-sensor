#define LED 7 //LED light
#define LDR A0 //LDR Sensor
bool checkValue = true;
int sensorValue = 0; // variable to store the value coming from the sensor

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(LDR,INPUT);
  Serial.begin(9600); //sets serial port for communication
  }

void loop() {
  sensorValue = analogRead(LDR); // read the value from the sensor
  Serial.println(sensorValue); //prints the values coming from the sensor on the screen
  if(checkValue)
  {
    if(sensorValue < 10)//in dark mode
    {
      digitalWrite(LED, HIGH);
      delay(21600000);
      digitalWrite(LED, LOW);
      delay(1000);
      checkValue = false;
      
    }
  }
  if(sensorValue >= 10)//in light mode
    {
      checkValue = true;
    }
}
