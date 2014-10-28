#ifndef __DETECT_SHAPES_H__
#define __DETECT_SHAPES_H__

#include "vec2.h"

typedef struct {
  vec2 * base;
  vec2 * direction;
} line;

typedef struct {
  vec2 * point1;
  vec2 * point2;
} segment;

typedef struct {
  vec2 center;
  float radius;
} circle;

#endif
