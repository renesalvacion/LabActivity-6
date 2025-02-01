
const int buttonPin = 12;       // Pin connected to the button
int lastButtonState = HIGH;     // Previous button state (HIGH because of pull-up)
int currentButtonState = HIGH;  // Current button state
unsigned long lastDebounceTime = 0; // Last time button state was checked
unsigned long debounceDelay = 50;   // Debounce delay in milliseconds

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Enable internal pull-up resistor
  Serial.begin(9600);                // Initialize serial communication
}

void loop() {
  // Read the current state of the button
  currentButtonState = digitalRead(buttonPin);

  // Check if the button state has changed (taking debounce into account)
  if (currentButtonState != lastButtonState) {
    lastDebounceTime = millis();  // Reset debounce timer
  }

  // If the debounce delay has passed, consider the new state
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the button is pressed, send '1'
    if (currentButtonState == LOW) { // LOW because of pull-up resistor
      Serial.println("1");  // Button pressed
    } else {
      Serial.println("0");  // Button not pressed
    }
  }

  // Update lastButtonState for the next loop iteration
  lastButtonState = currentButtonState;
}
