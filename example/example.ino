#include "Quaternion.h"

Quaternion random_q() {
  float x = float(random(1000)) / 1000.0f;
  float y = float(random(1000)) / 1000.0f;
  float z = float(random(1000)) / 1000.0f;
  float w = float(random(1000)) / 1000.0f;
  Quaternion a(x, y, z, w);
  return a;
}

void setup() {
  Serial.begin(115200);
  randomSeed(1000);


  for (int i = 0; i < 100; i++) {
    Quaternion a = random_q();
    Quaternion b = random_q();

    Quaternion c = a.inverse();
    Quaternion d = c.multiple(b);

    Serial.print(a.toString());
    Serial.print(',');
    Serial.print(b.toString());
    Serial.print(',');
    Serial.print(d.toString());
    Serial.print('\n');

    delay(1000);

  }
}

void loop() {


}
