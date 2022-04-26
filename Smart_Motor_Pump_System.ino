
int highInp = 3;
int midInp = 2;
int lowInp = 8;

int motor = 4;

int highOut = 5;
int midOut = 6;
int lowOut = 7;

boolean motorOn = false;
int startTime = 0;
boolean disableMotor = false;
int bufferTime = 10000; // 10 seconds, use 60000 for 1 min
void setup() {
  // put your setup code here, to run once:
  pinMode(highInp, INPUT);
  pinMode(midInp, INPUT);
  pinMode(lowInp, INPUT);
  
  pinMode(motor, OUTPUT);
  
  pinMode(highOut, OUTPUT);
  pinMode(midOut, OUTPUT);
  pinMode(lowOut, OUTPUT);

   Serial.begin(115200);
}

void loop() {
   // print the results to the Serial Monitor:
  Serial.print("High Input = ");
  Serial.print(digitalRead(highInp));
  Serial.print("\n Mid Input = ");
  Serial.println(digitalRead(midInp));
  Serial.print("\n Low Input  = ");
  Serial.println(digitalRead(lowInp));

  Serial.println(millis());
  
  // put your main code here, to run repeatedly:
  if(digitalRead(highInp) == 0)
  {
    digitalWrite(highOut, LOW);
  }
  if(digitalRead(highInp) == 1)
  {
    digitalWrite(motor, LOW); // motor off
    motorOn = false;
    startTime = millis();
    digitalWrite(highOut, HIGH);
  }
  if(digitalRead(midInp) == 0)
  {
    digitalWrite(midOut, LOW);  
  }
  if(digitalRead(midInp) == 1)
  {
    digitalWrite(midOut, HIGH);  
  }
  if(digitalRead(lowInp) == 0)
  {
    //if motor disable is true do noting else do this
        Serial.println(disableMotor);
        digitalWrite(lowOut, LOW);
    if (!disableMotor) {
            Serial.print("counter: ");
            Serial.println(( millis() - startTime ) >= 10000);
        if (!motorOn) {
            digitalWrite(motor, HIGH); // motor on
            motorOn = true;
            startTime = millis();
          }else {
            
             if (( millis() - startTime ) >= bufferTime) {
                //disable motor and turn off motor
                digitalWrite(motor, LOW);
                disableMotor = true;
                motorOn = false;
                Serial.println("Motor is Disabled Restart Controller");
              }else {
                digitalWrite(motor, HIGH);
              }
            }
          } else {
            digitalWrite(motor, LOW);
            Serial.println("Motor is disabled");
            }
  }
  if(digitalRead(lowInp) == 1)
  {
    digitalWrite(lowOut, HIGH); 
  }
}
