// Define the pins
const int pin5 = 5; // Square wave with 1-second period
const int pin6 = 6; // Square wave with 2-second period
const int pin7 = 7; // Monitor state

// Variables to store the last toggle time
unsigned long previousMillis5 = 0;
unsigned long previousMillis6 = 0;

// Variables to store the state of the pins
int state5 = LOW;
int state6 = LOW;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the pin modes
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, INPUT);
}

void loop() {
  // Get the current time
  unsigned long currentMillis = millis();

  // Toggle pin 5 every 500 ms (1-second period)
  if (currentMillis - previousMillis5 >= 500) {
    previousMillis5 = currentMillis;
    state5 = !state5;
    digitalWrite(pin5, state5);
  }

  // Toggle pin 6 every 1000 ms (2-second period)
  if (currentMillis - previousMillis6 >= 1000) {
    previousMillis6 = currentMillis;
    state6 = !state6;
    digitalWrite(pin6, state6);
  }

  // Print the states of pins 5, 6, and 7 with spaces between values
  Serial.print(digitalRead(pin5));
  Serial.print(" ");
  Serial.print(digitalRead(pin6));
  Serial.print(" ");
  Serial.println(digitalRead(pin7));

  // Small delay to make the serial output readable
  delay(100);
}