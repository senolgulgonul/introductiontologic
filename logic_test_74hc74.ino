// Define the pins
const int dataPin = 5; // Data (D) connected to Arduino pin 5
const int clkPin = 6;  // Clock (CLK) connected to Arduino pin 6
const int qPin = 7;    // Q connected to Arduino pin 7

// Variables to store the last toggle time
unsigned long previousMillisData = 0;
unsigned long previousMillisClk = 0;

// Variables to store the state of the pins
int dataState = LOW;
int clkState = LOW;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the pin modes
  pinMode(dataPin, OUTPUT);
  pinMode(clkPin, OUTPUT);
  pinMode(qPin, INPUT);  // Set Q pin as input without pull-up resistor
}

void loop() {
  // Get the current time
  unsigned long currentMillis = millis();

  // Toggle data pin every 2000 ms (4-second period)
  if (currentMillis - previousMillisData >= 2000) {
    previousMillisData = currentMillis;
    dataState = !dataState;
    digitalWrite(dataPin, dataState);
  }

  // Toggle clock pin every 500 ms (1-second period)
  if (currentMillis - previousMillisClk >= 500) {
    previousMillisClk = currentMillis;
    clkState = !clkState;
    digitalWrite(clkPin, clkState);
  }

  // Print the state of the Q pin
  Serial.print(digitalRead(dataPin));
  Serial.print(" ");
  Serial.print(digitalRead(clkPin));
  Serial.print(" ");
  Serial.println(digitalRead(qPin));

  // Small delay to make the serial output readable
  delay(100);
}