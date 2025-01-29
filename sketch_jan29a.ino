#define ledpin 13
char state = 0;
unsigned long previousMillis = 0;
unsigned long byteCount = 0;
float byteSpeed = 0;

void setup() {
  Serial.begin(2400);
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, LOW);  // Ensure LED is OFF initially
}

void loop() {
  unsigned long currentMillis = millis(); // It will give current time

  // Check if data is available from Serial
  while (Serial.available() > 0) {
    state = Serial.read(); // Read data
    byteCount++;  // Count received bytes

    // LED control based on received data
    if (state == 'A') {
      digitalWrite(ledpin, HIGH);
    } 
    else if (state == 'B') {
      digitalWrite(ledpin, LOW);
    }
  }

  if (currentMillis - previousMillis >= 1000) {  
    byteSpeed = byteCount / ((currentMillis - previousMillis) / 1000.0);
    
    Serial.println("----");
    Serial.print("Byte Speed: ");
    Serial.print(byteSpeed);
    Serial.println(" Bps");  // Bytes per second

    //Sending data from mc to pc by telling the led status
    Serial.print("LED Status(sending data from mcu to pc ): ");
    int key=digitalRead(ledpin); //This will read mcu status 
    if (key == HIGH) {
      Serial.println("ON");
    } else {
      Serial.println("OFF");
    }
    Serial.println("----");

    // Now we will reset the counter
    previousMillis = currentMillis;
    byteCount = 0;
  }

  delay(100);
}
