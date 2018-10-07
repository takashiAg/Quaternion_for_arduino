#ifndef QUATERNION_H_INCLUDE
#define QUATERNION_H_INCLUDE
#include "Arduino.h"

class Quaternion {
  public:
    Quaternion();
    Quaternion(float a, float b, float c, float d);
    Quaternion conjugate();
    Quaternion multiple(Quaternion a);
    float norm();
    Quaternion inverse();
    void euler(float& roll, float& pitch, float& yaw);
    Quaternion Angular_difference(Quaternion p);

    String toString();
    float x, y, z, w;
  private:
};

#endif
