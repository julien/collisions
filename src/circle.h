#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "vec2.h"

typedef struct {
  vec2 * center;
  float radius;
} circle;

circle * circle_init(float x, float y, float radius) {
  circle * c = malloc(sizeof(circle));

  if (c != NULL) {
    c->center = vec2_init(x, y);
    c->radius = radius;
  }

  return c;
}

void circle_free(circle * c) {
  if (c != NULL) {
    vec2_free(c->center);
    free(c);
  }
}

#endif

