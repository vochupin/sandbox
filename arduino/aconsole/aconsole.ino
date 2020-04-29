int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
    drawMenu();
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available() > 0) {
    blinkLed();
    incomingByte = Serial.read();

    drawMenu();

    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);  
  }
}

void drawMenu() {
  clearScreen();

  Serial.println("Press A,D to move right-left");
  Serial.println("Press W,S to move forward-backward");
}

void clearScreen() {
  Serial.write(27);       // ESC command
  Serial.print("[2J");    // clear screen command
  Serial.write(27);
  Serial.print("[H");     // cursor to home command
}

void blinkLed() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}
