#include <Wire.h>

#define SLAVE_ADDRESS 8
#define LED_PIN 7

struct SensorData {
    float distance;
    int ldr;
    byte closeStatus;
    byte lightStatus;
    byte ledStatus;
};

SensorData data;
bool slaveConnected = false;

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    Wire.begin();
    Serial.println("MASTER ARDUINO STARTED");
}

bool requestSensorData() {
    // Request bytes from slave
    byte bytesReceived = Wire.requestFrom(SLAVE_ADDRESS, (int)sizeof(SensorData));

    if(bytesReceived == sizeof(SensorData)) {
        byte* ptr = (byte*)&data;
        for(unsigned int i = 0; i < sizeof(SensorData); i++) {
            ptr[i] = Wire.read();
        }
        return true;
    }

    // Clear buffer if read failed
    while(Wire.available()) {
        Wire.read();
    }

    return false;
}

void loop() {
    slaveConnected = requestSensorData();

    Serial.print("Status: ");
    if(!slaveConnected) {
        Serial.print("DISCONNECTED");
        digitalWrite(LED_PIN, LOW);
        Serial.println(" | LED: OFF");
    } else {
        Serial.print("CONNECTED");
        Serial.print(" | Dist: ");
        if(data.distance < 0) {
            Serial.print("NO ECHO");
        } else {
            Serial.print(data.distance);
            Serial.print(" cm");
        }

        // Option A: Use the exact decision made by the slave (recommended)
        if(data.ledStatus) {
            digitalWrite(LED_PIN, HIGH);
            Serial.println(" | LED: ON");
        } else {
            digitalWrite(LED_PIN, LOW);
            Serial.println(" | LED: OFF");
        }
    }

    delay(300);
}