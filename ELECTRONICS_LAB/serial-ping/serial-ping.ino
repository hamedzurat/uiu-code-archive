// ESP32 Serial + Blink sanity test
#define LED_PIN 2

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
    delay(1000);
    Serial.println("Hello from ESP32!");
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
    Serial.println("Blink...");
}
