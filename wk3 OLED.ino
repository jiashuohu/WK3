#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
SSD1306Wire  display(0x3c, 21, 22);
int rd;
void setup() {
  Serial.begin(115200);
  // Initialising the UI will init the display too.
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_24);
}

void loop() {
  display.clear();
  rd=analogRead(A0);
  Serial.println(rd);
  display.drawString(0, 0, String(analogRead(A0)/16));
  // write the buffer to the display
  display.display();

  delay(50);
}
