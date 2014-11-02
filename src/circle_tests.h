#ifndef __CIRCLE_TESTS_H__
#define __CIRCLE_TESTS_H__

#include <math.h>
#include "circle.h"
#include "minunit.h"

static char * test_circle_init() {
  circle * c = circle_init(10.0, 20.0, 40.0);

  mu_assert("c->center->x == 10", c->center->x == 10);
  mu_assert("c->center->y == 20", c->center->y == 20);
  mu_assert("c->radius = 40", c->radius == 40);

  circle_free(c);

  return 0;
}

static char * test_circle_collides() {
  circle * a = circle_init(4.0, 4.0, 2.0);
  circle * b = circle_init(7.0, 4.0, 2.0);
  circle * c = circle_init(10.0, 4.0, 2.0);

  mu_assert("1 == circle_collides(a, b)", 1 == circle_collides(a, b));
  mu_assert("1 == circle_collides(b, c)", 1 == circle_collides(b, c));
  mu_assert("0 == circle_collides(a, c)", 0 == circle_collides(a, c));

  circle_free(a);
  circle_free(b);
  circle_free(c);

  return 0;
}

#endif
