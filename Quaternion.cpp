#include "Quaternion.h"
#include "Math.h"
#include "Arduino.h"

Quaternion::Quaternion() {
  x = y = z = w = 0.0f;
}

Quaternion::Quaternion(float a, float b, float c, float d) {
  x = a;
  y = b;
  z = c;
  w = d;
}

Quaternion Quaternion::conjugate() {
  Quaternion answer (-x, -y, -z, w);
  return answer;
}

Quaternion Quaternion::multiple( Quaternion p) {
  //  Quaternion answer (
  //    p.w * w - p.x * x - p.y * y - p.z * z,
  //    p.w * x + p.x * w + p.y * z - p.z * y,
  //    p.w * y - p.x * z + p.y * w + p.z * x,
  //    p.w * z + p.x * y - p.y * x + p.z * w
  //  );

  //  Quaternion answer (
  //    p.w * w - p.x * x - p.y * y - p.z * z,
  //    p.x * w + p.w * x - p.z * y + p.y * z,
  //    p.y * w + p.z * x + p.w * y - p.x * z,
  //    p.z * w - p.y * x + p.x * y + p.w * z
  //  );

  Quaternion answer (
    w * p.x + x * p.w + y * p.z - z * p.y,
    w * p.y - x * p.z + y * p.w + z * p.x,
    w * p.z + x * p.y - y * p.x + z * p.w,
    w * p.w - x * p.x - y * p.y - z * p.z
  );
  return answer;
}
float Quaternion::norm() {
  float answer = sqrt(x * x + y * y + z * z + w * w);
  return answer;
}


Quaternion Quaternion::inverse() {
  float norm_1 = norm();
  float norm_2 = norm_1 * norm_1;

  Quaternion answer (
    -x / norm_2,
    -y / norm_2,
    -z / norm_2,
    w / norm_2
  );
  return answer;
}


String Quaternion::toString() {
  String delimiter = ",";
  String s = "";
  char c[15];
  dtostrf(x, 11, 10, c);
  s += String(c) + delimiter;
  dtostrf(y, 11, 10, c);
  s += String(c) + delimiter;
  dtostrf(z, 11, 10, c);
  s += String(c) + delimiter;
  dtostrf(w, 11, 10, c);
  s += String(c);
  return s;
}



Quaternion Quaternion::Angular_difference(Quaternion p) {
  return inverse().multiple(p);
}
