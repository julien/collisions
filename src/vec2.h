#ifndef __VEC2_H__
#define __VEC2_H__

#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "utils.h"

/* vec2 */
typedef struct {
  float x;
  float y;
} vec2;

vec2 * vec2_init(double x, double y) {
  vec2 * v = malloc(sizeof(vec2));
  if (v != NULL) {
    v->x = x;
    v->y = y;
  }
  return v;
}

void vec2_free(vec2 * v) {
  if (v != NULL) {
    free(v);
  }
}

vec2 * vec2_set(vec2 * v, float x, float y) {
  v->x = x;
  v->y = y;
  return v;
}

vec2 * vec2_add(vec2 * a, vec2  * b) {
  a->x += b->x;
  a->y += b->y;
  return a;
}

vec2 * vec2_sub(vec2 * a, vec2 * b) {
  a->x -= b->x;
  a->y -= b->y;
  return a;
}

vec2 * vec2_neg(vec2 * v) {
  v->x = v->x * -1;
  v->y = v->y * -1;
  return v;
}

vec2 * vec2_mul(vec2 * v, float scalar) {
  v->x *= scalar;
  v->y *= scalar;
  return v;
}

vec2 * vec2_div(vec2 * v, float divisor) {
  v->x /= 2;
  v->y /= 2;
  return v;
}

void vec2_assertEq(vec2 * a, vec2 * b) {
  assert(eqfloats(a->x, b->x));
  assert(eqfloats(a->y, b->y));
}

int vec2_equals(vec2 * a, vec2 * b) {
  int x = eqfloats(a->x, b->x);
  int y = eqfloats(a->y, b->y);
  return x && y;
}

float vec2_length(vec2 * v) {
  return sqrtf(v->x * v->x + v->y * v->y);
}

vec2 * vec2_unit(vec2 *v) {

  if (v->x > 0 && v->y > 0) {

    float length = vec2_length(v);
    if (0 < length) {
      return vec2_div(v, length);
    }
  }

  return v;
}

vec2 * vec2_rotate(vec2 * v, float degrees) {
  // radians, cosine and sine
  float r = radians(degrees);
  float c = cosf(r);
  float s = sinf(r);

  v->x = v->x * c - v->y * s;
  v->y = v->x * s + v->y * c;

  return v;
}

float vec2_dotproduct(vec2 * a, vec2 * b) {
  return a->x * b->x + a->y * b->y;
}

float vec2_enclosed_angle(vec2 * a, vec2 * b) {
  vec2 * ua = vec2_unit(a);
  vec2 * ub = vec2_unit(b);
  float dp = vec2_dotproduct(ua, ub);
  return degrees(acosf(dp));
}

vec2 * vec2_project(vec2 * project, vec2 * onto) {

  float d = vec2_dotproduct(onto, onto);

  if (0 < d) {
    float dp = vec2_dotproduct(project, onto);
    return vec2_mul(onto, dp / d);
  }

  return onto;
}


vec2 * vec2_rotate90(vec2 * v) {
  float x = v->x;
  v->x = -v->y;
  v->y = x;
  return v;
}

int vec2_parallel(vec2 * a, vec2 * b) {
  vec2 * na = vec2_rotate90(a);
  return eqfloats(0, vec2_dotproduct(na, b));
}

#endif
