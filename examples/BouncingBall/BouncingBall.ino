#include <Arduino.h>
#include "EDGE.h"
#include "BouncingBallScene.h"

#define I2C_SDA 5
#define I2C_SCL 6
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Examples ESP32-C3 with OLED Display
DisplayConfig config(SSD1306, I2C_SCL, I2C_SDA, U8X8_PIN_NONE, U8G2_R0, SCREEN_WIDTH, SCREEN_HEIGHT, true);

EDGE engine(config);
BouncingBallScene bouncingScene;

Renderer& renderer = engine.getRenderer();

unsigned long currentTime = 0;

void printTask(ulong time);

void setup() {
    Serial.begin(115200);
    engine.init();
    engine.setScene(&bouncingScene);

    Serial.println("Setup completed");
}

void loop() {
    currentTime = millis();
    engine.update();
    engine.draw();
}
