#ifndef __VEC2_TESTS_H__
#define __VEC2_TESTS_H__

#include <math.h>
#include "vec2.h"
#include "minunit.h"


static char * test_vec2_init() {
  vec2 * v = vec2_init(2.0, 2.0);

  mu_assert("v->x == 2", v->x == 2);
  mu_assert("v->y == 2", v->y == 2);

  vec2_free(v);

  return 0;
}

static char * test_vec2_add() {
  vec2 * a = vec2_init(2, 2);
  vec2 * b = vec2_init(1, 4);
  vec2_add(a, b);

  mu_assert("a->x == 3", a->x == 3);
  mu_assert("a->x == 6", a->y == 6);

  vec2_free(a);
  vec2_free(b);

  return 0;
}

static char * test_vec2_neg() {
  vec2 * v = vec2_init(2, 4);

  vec2_neg(v);

  mu_assert("v->x == -2", v->x == -2);
  mu_assert("v->x == -4", v->y == -4);

  vec2_free(v);
  return 0;
}

static char * test_vec2_set() {
  vec2 * v = vec2_init(10, 10);

  mu_assert("v->x == 10", v->x == 10);
  mu_assert("v->x == 10", v->y == 10);

  vec2_set(v, 2, 2);

  mu_assert("v->x == 2", v->x == 2);
  mu_assert("v->x == 2", v->y == 2);

  vec2_free(v);
  return 0;
}

static char * test_vec2_assertEq() {
  vec2 * a = vec2_init(3, 4);
  vec2 * b = vec2_init(3, 4);

  vec2_assertEq(a, b);

  mu_assert("a->x == b->x", a->x == b->x);
  mu_assert("a->y == b->y", a->y == b->y);

  vec2_free(a);
  vec2_free(b);

  return 0;
}

static char * test_vec2_equals() {
  vec2 * a = vec2_init(6, 8);
  vec2 * b = vec2_init(6, 8);

  mu_assert("vec2_equals(a, b)", vec2_equals(a, b));

  vec2_free(a);
  vec2_free(b);

  return 0;
}

static char * test_vec2_mul() {
  vec2 * v = vec2_init(2, 4);

  vec2_mul(v, 2);

  mu_assert("v->x == 4", v->x == 4);
  mu_assert("v->y == 8", v->y == 8);

  vec2_free(v);

  return 0;
}

static char * test_vec2_div() {
  vec2 * v = vec2_init(8, 6);

  vec2_div(v, 2);

  mu_assert("v->x == 4", v->x == 4);
  mu_assert("v->y == 3", v->y == 3);

  vec2_free(v);

  return 0;
}

static char * test_vec2_length() {
  vec2 * v = vec2_init(5, 5);

  mu_assert("vec2_length(v) >= 7", vec2_length(v));

  vec2_free(v);

  return 0;
}

static char * test_vec2_unit() {
  vec2 * v = vec2_init(3, 3);

  vec2_unit(v);

  mu_assert("v->x > 1", v->x > 1);
  mu_assert("v->y > 1", v->y > 1);

  vec2_free(v);

  return 0;
}

static char * test_vec2_rotate() {
  vec2 * v = vec2_init(4, 5);

  vec2_rotate(v, 30);

  mu_assert("v->x < 1", v->x < 1);
  mu_assert("v->y > 4", v->y > 4);

  vec2_free(v);

  return 0;
}

static char * test_vec2_dotproduct() {
  vec2 * a = vec2_init(2, 2);
  vec2 * b = vec2_init(6, 6);

  mu_assert("vec2_dotproduct(a, b) == 24", vec2_dotproduct(a, b) == 24);

  return 0;
}

static char * test_vec2_enclosed_angle() {
  vec2 * a = vec2_init(8, 2);
  vec2 * b = vec2_init(-2, 8);

  float angle = vec2_enclosed_angle(a, b);

  mu_assert("angle == 90", angle == 90);

  vec2_free(a);
  vec2_free(b);

  return 0;
}

#endif
