// Define the pins
const int pin1A = 5; // 1A connected to Arduino pin 5
const int pin1B = 6; // 1B connected to Arduino pin 6
const int pin1Y = 7; // 1Y connected to Arduino pin 7

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the pin modes
  pinMode(pin1A, OUTPUT);
  pinMode(pin1B, OUTPUT);
  pinMode(pin1Y, INPUT);
}

void loop() {
  // Print header
  Serial.println("Testing 74HC08...");

  // Test case 00
  digitalWrite(pin1A, LOW);
  digitalWrite(pin1B, LOW);
  delay(100); // Small delay for stability
  Serial.print("Input: 00, Output: ");
  Serial.println(digitalRead(pin1Y));

  // Test case 01
  digitalWrite(pin1A, LOW);
  digitalWrite(pin1B, HIGH);
  delay(100); // Small delay for stability
  Serial.print("Input: 01, Output: ");
  Serial.println(digitalRead(pin1Y));

  // Test case 10
  digitalWrite(pin1A, HIGH);
  digitalWrite(pin1B, LOW);
  delay(100); // Small delay for stability
  Serial.print("Input: 10, Output: ");
  Serial.println(digitalRead(pin1Y));

  // Test case 11
  digitalWrite(pin1A, HIGH);
  digitalWrite(pin1B, HIGH);
  delay(100); // Small delay for stability
  Serial.print("Input: 11, Output: ");
  Serial.println(digitalRead(pin1Y));

  // Add a delay before repeating the tests
  delay(1000);
}