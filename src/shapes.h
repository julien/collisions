#ifndef __SHAPES_H__
#define __SHAPES_H__

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
  vec2 * center;
  float radius;
} circle;

typedef struct {
  vec2 * origin;
  vec2 * size;
} rect;

typedef struct {
  vec2 * center;
  vec2 * halfExtend;
  float angle;
}


#endif
