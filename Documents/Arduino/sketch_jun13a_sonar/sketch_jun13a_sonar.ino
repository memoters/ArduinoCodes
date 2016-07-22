const int triggerPin = 12;
const int echoPin = 13;

const int maxRange = 200;
const int minRange = 0;

long duration, distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration/58.2;
  
  if(distance >= maxRange || distance <= minRange)
  {
    Serial.print("out of range");    
  }
  else
  {
    Serial.println("Distance: ");
    Serial.println(distance);
  }
  
  delay(50);
}
