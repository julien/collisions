#ifndef __UTILS_H__
#define __UTILS_H__

#include <math.h>

/* utility methods */
int eqfloats(float a, float b) {
  float threshold = 1.0f / 8192.0f;
  return fabsf(a - b) < threshold;
}

float radians(float degrees) {
  return degrees * M_PI / 180.0f;
}

float degrees(float radians) {
  return radians * 180 / M_PI;
}

#endif
