/*
  ESP32 Minimal Web Server (plain text)
  - Starts WiFi Access Point (SSID: ESP32-AP, pass: esp32pass)
  - Serves plain text at http://192.168.4.1/
  - Shows hit count + basic system info
  - Optional endpoints:
      /json   -> JSON with same info
      /reset  -> reset the hit counter to 0
*/

#include <WebServer.h>
#include <WiFi.h>

const char* AP_SSID = "ESP32-AP";
const char* AP_PASS = "esp32pass";

WebServer server(80);
volatile unsigned long hitCount = 0;

String humanBytes(uint32_t b) {
    // simple bytes->KB/MB helper
    char buf[32];
    if(b >= (1024UL * 1024UL)) {
        float mb = b / 1024.0 / 1024.0;
        snprintf(buf, sizeof(buf), "%.2f MB", mb);
    } else if(b >= 1024UL) {
        float kb = b / 1024.0;
        snprintf(buf, sizeof(buf), "%.2f KB", kb);
    } else {
        snprintf(buf, sizeof(buf), "%lu B", (unsigned long)b);
    }
    return String(buf);
}

String buildPlainTextReport() {
    hitCount++;
    unsigned long up_ms = millis();
    unsigned long up_s  = up_ms / 1000UL;

    String s;
    s.reserve(512);
    s = "ESP32 Minimal Server\n";
    s += "====================\n";
    s += "Hits: " + String(hitCount) + "\n";
    s += "Uptime: " + String(up_s) + " s\n";
    s += "AP IP: " + WiFi.softAPIP().toString() + "\n";
    s += "AP MAC: " + WiFi.softAPmacAddress() + "\n";
    s += "\n";
    s += "Chip: " + String(ESP.getChipModel()) + "\n";
    s += "Cores: " + String(ESP.getChipCores()) + "\n";
    s += "CPU Freq: " + String(getCpuFrequencyMhz()) + " MHz\n";
    s += "Flash Size: " + humanBytes(ESP.getFlashChipSize()) + "\n";
    s += "Heap Free: " + humanBytes(ESP.getFreeHeap()) + "\n";
    s += "Sketch Size: " + humanBytes(ESP.getSketchSize()) + "\n";
    s += "Sketch Free Space: " + humanBytes(ESP.getFreeSketchSpace()) + "\n";
    s += "\n";
    s += "Endpoints:\n";
    s += "  /       -> this text\n";
    s += "  /json   -> JSON with same info\n";
    s += "  /reset  -> reset hit counter\n";
    return s;
}

String buildJson() {
    unsigned long up_ms = millis();
    unsigned long up_s  = up_ms / 1000UL;
    // manual JSON (no ArduinoJson needed)
    String j = "{";
    j += "\"hits\":" + String(hitCount + 1) + ",";
    j += "\"uptime_s\":" + String(up_s) + ",";
    j += "\"ap_ip\":\"" + WiFi.softAPIP().toString() + "\",";
    j += "\"ap_mac\":\"" + WiFi.softAPmacAddress() + "\",";
    j += "\"chip_model\":\"" + String(ESP.getChipModel()) + "\",";
    j += "\"cores\":" + String(ESP.getChipCores()) + ",";
    j += "\"cpu_mhz\":" + String(getCpuFrequencyMhz()) + ",";
    j += "\"flash_bytes\":" + String(ESP.getFlashChipSize()) + ",";
    j += "\"heap_free\":" + String(ESP.getFreeHeap()) + ",";
    j += "\"sketch_size\":" + String(ESP.getSketchSize()) + ",";
    j += "\"sketch_free\":" + String(ESP.getFreeSketchSpace());
    j += "}";
    return j;
}

void handleRoot() {
    server.send(200, "text/plain; charset=utf-8", buildPlainTextReport());
}

void handleJson() {
    server.send(200, "application/json", buildJson());
}

void handleReset() {
    hitCount = 0;
    server.send(200, "text/plain", "Hit counter reset to 0.\n");
}

void startAP() {
    WiFi.mode(WIFI_AP);
    WiFi.softAP(AP_SSID, AP_PASS);
    delay(100);
    Serial.print("AP SSID: ");
    Serial.println(AP_SSID);
    Serial.print("AP PASS: ");
    Serial.println(AP_PASS);
    Serial.print("AP IP:   ");
    Serial.println(WiFi.softAPIP());
}

void setup() {
    Serial.begin(115200);
    delay(200);

    startAP();

    server.on("/", handleRoot);
    server.on("/json", handleJson);
    server.on("/reset", handleReset);
    server.begin();

    Serial.println("Server started. Open http://192.168.4.1/");
}

void loop() {
    server.handleClient();
}
