// Basic LDR (Light Dependent Resistor) code
// Arduino Uno

#define LDR_PIN A0

void setup() {
    Serial.begin(9600);

    // LDR is connected to an analog input
    pinMode(LDR_PIN, INPUT);
}

void loop() {
    // Read LDR value (0-1023)
    int ldrValue = analogRead(LDR_PIN);

    // Basic error check
    if(ldrValue < 0 || ldrValue > 1023) {
        Serial.println("Error: Invalid LDR reading!");
    } else {
        // Convert reading to approximate percentage
        int lightPercent = map(ldrValue, 0, 1023, 0, 100);

        Serial.print("LDR Value: ");
        Serial.print(ldrValue);

        Serial.print(" | Light: ");
        Serial.print(lightPercent);
        Serial.println("%");
    }

    delay(500);
}
