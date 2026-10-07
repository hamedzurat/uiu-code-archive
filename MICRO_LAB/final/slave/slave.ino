#include <Wire.h>

#define SLAVE_ADDRESS 8
#define TRIG_PIN 9
#define ECHO_PIN 10
#define LDR_PIN A0
#define LED_PIN 13

#define CLOSE_DISTANCE_CM 5.0
#define LOW_LIGHT_THRESHOLD 20

float distanceCM = 0.0;
int ldrValue     = 0;

bool closeObject   = false;
bool lowLight      = false;
bool ledShouldBeOn = false;

struct SensorData {
    float distance;
    int ldr;
    byte closeStatus;
    byte lightStatus;
    byte ledStatus;
};

SensorData data;

void setup() {
    Serial.begin(9600);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LDR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    Wire.begin(SLAVE_ADDRESS);
    Wire.onRequest(sendData);

    Serial.println("SLAVE ARDUINO STARTED");
}

float readDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH, 30000);
    if(duration == 0) return -1;

    return duration * 0.0343 / 2.0;
}

void sendData() {
    // Send the struct safely as a byte stream
    Wire.write((uint8_t*)&data, sizeof(data));
}

void loop() {
    distanceCM = readDistance();
    ldrValue   = analogRead(LDR_PIN);

    closeObject = (distanceCM > 0 && distanceCM <= CLOSE_DISTANCE_CM);
    lowLight    = (ldrValue < LOW_LIGHT_THRESHOLD);

    // OR Logic
    ledShouldBeOn = closeObject || lowLight;
    digitalWrite(LED_PIN, ledShouldBeOn ? HIGH : LOW);

    // Update struct
    data.distance    = distanceCM;
    data.ldr         = ldrValue;
    data.closeStatus = closeObject;
    data.lightStatus = lowLight;
    data.ledStatus   = ledShouldBeOn;

    // Single line log output
    Serial.println("Dist: " + String(distanceCM) + "cm | LDR: " + String(ldrValue) + " | Close: " + String(closeObject) + " | LowLight: " + String(lowLight) + " | LED: " + String(ledShouldBeOn));

    delay(300);
}