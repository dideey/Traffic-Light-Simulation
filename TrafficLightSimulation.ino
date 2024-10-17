// LED Traffic Light Simulation
// This program simulates a traffic light system with a pedestrian crossing button.

const int redLightPin = 23;   // Red LED connected to GPIO 23
const int yellowLightPin = 22; // Yellow LED connected to GPIO 22
const int greenLightPin = 21;  // Green LED connected to GPIO 21
const int buttonPin = 19;      // Pedestrian crossing button connected to GPIO 19

bool pedestrianButtonPressed = false; // Flag to indicate if the pedestrian button is pressed

void setup() {
  // Initialize the LED pins as outputs
  // TODO: Set the button pin as INPUT
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // implement the traffic lights simulation
  //checks if the button is pressed
  if (digitalRead(buttonPin) == HIGH) {
    pedestrianButtonPressed = true;
  }

  //if the button is pressed, call the pedestrianCrossing function
  if (pedestrianButtonPressed) {
    pedestrianCrossing();
    pedestrianButtonPressed = false;
  }

  //call the trafficLightSequence function
  trafficLightSequence();
}

// Function to control the traffic light sequence, turns the red light on for 5 seconds, then the yellow light for 2 seconds, and finally the green light for 3 seconds
void trafficLightSequence() {
  digitalWrite(redLightPin, HIGH);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
  delay(5000);
  digitalWrite(yellowLightPin, HIGH);
  digitalWrite(redLightPin, LOW);
  delay(2000);
  digitalWrite(greenLightPin, HIGH);
  digitalWrite(yellowLightPin, LOW);
  delay(3000);
}
// Function to control the pedestrian crossing, turns the red light on for 10 seconds
void pedestrianCrossing() {
  digitalWrite(redLightPin, HIGH);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
  delay(10000);
}