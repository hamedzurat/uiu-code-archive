#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
    Serial.begin(9600);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    digitalWrite(TRIG_PIN, LOW);
}

void loop() {
    // Send a 10-microsecond trigger pulse
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure the echo pulse
    unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);

    if(duration == 0) {
        Serial.println("Out of range");
    } else {
        // Speed of sound ≈ 0.0343 cm/us
        float distance = duration * 0.0343 / 2.0;

        Serial.print("Distance: ");
        Serial.print(distance, 1);
        Serial.println(" cm");
    }

    delay(100);
}
