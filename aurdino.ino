const int trigPin = 9;
const int echoPin = 10;
const int greenLedPin = 11;
const int yellowLedPin = 12;
const int redLedPin = 13;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(greenLedPin, OUTPUT); // Sets the greenLedPin as an Output
  pinMode(yellowLedPin, OUTPUT); // Sets the yellowLedPin as an Output
  pinMode(redLedPin, OUTPUT); // Sets the redLedPin as an Output
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Control LEDs based on distance
  if (distance < 15) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, HIGH);
  } else if (distance >= 15 && distance <= 40) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, HIGH);
  } else if (distance >= 40 && distance <= 100){
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }
  
  delay(200); // Wait for 200 milliseconds
}
