#include "EDGE.h"
#include "BouncingBallScene.h"

#define I2C_SDA 5
#define I2C_SCL 6
#define SCREEN_WIDTH 72
#define SCREEN_HEIGHT 40

// Examples ESP32-C3 with OLED Display
DisplayConfig config(SSD1306, I2C_SCL, I2C_SDA, U8X8_PIN_NONE, U8G2_R0, SCREEN_WIDTH, SCREEN_HEIGHT, true);

EDGE engine(config);
BouncingBallScene bouncingScene;

unsigned long currentTime = 0;

void printTask(ulong time);

void setup() {
    Serial.begin(115200);
    delay(100);

    engine.init();
    engine.setScene(&bouncingScene);
        
    Serial.println("Setup completed");
}

void loop() {
    currentTime = millis();
    engine.update();
    engine.draw();
    
    printTask(currentTime);
}

void printTask(unsigned long ct) {
  // If serial output is not working set "USB CDC on BOOT" to "Enabled" in tools
  static unsigned long lastTime = 0;
  const int rate = 2000;
  
  if (ct - lastTime < rate) return;
  
  lastTime = ct;
  
  Serial.print(".");
}
