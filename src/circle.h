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

int circle_collides(circle * a, circle * b) {
  float radii = a->radius * b->radius;
  vec2 * dist = vec2_sub(a->center, *b->cebter);
  return vec2_length(*dist) < radii;

}
#endif

