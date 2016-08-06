#include <Arduino.h>
#include <Adafruit_LEDBackpack.h>
#include <Adafruit_GFX.h>
#include <inttypes.h>

Adafruit_7segment matrix = Adafruit_7segment();

void setup()
{
      matrix.begin(0x70);
}

void loop ()
{
  static uint16_t initialTime = 10 * 60;
  matrix.writeDigitNum(0,initialTime/60/10,false);
  matrix.writeDigitNum(1, (initialTime/60)%10, false);
  matrix.drawColon(true);
  matrix.writeDigitNum(3, (initialTime%60)/10, false);
  matrix.writeDigitNum(4, (initialTime%60)%10, false);
  matrix.writeDisplay();
  delay(1000);
  initialTime--;
}
