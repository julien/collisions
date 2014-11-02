#ifndef __RECT_TESTS_H__
#define __RECT_TESTS_H__

#include <math.h>
#include "rect.h"
#include "minunit.h"

static char * test_rect_init() {
  rect * r = rect_init(2.0, 2.0, 10.0, 10.0);

  mu_assert("r->origin->x == 2", r->origin->x == 2);
  mu_assert("r->origin->y == 2", r->origin->y == 2);
  mu_assert("r->size->x == 10", r->size->x == 10);
  mu_assert("r->size->y == 10", r->size->y == 10);

  rect_free(r);

  return 0;
}

static char * test_rect_collides() {
  rect * a = rect_init(1.0, 1.0, 4.0, 4.0);
  rect * b = rect_init(2.0, 2.0, 5.0, 5.0);
  rect * c = rect_init(6.0, 4.0, 4.0, 2.0);

  mu_assert("1 == rect_collides(a, b)", 1 == rect_collides(a, b));
  mu_assert("1 == rect_collides(b, c)", 1 == rect_collides(b, c));
  mu_assert("0 == rect_collides(a, c)", 0 == rect_collides(a, c));

  rect_free(a);
  rect_free(b);
  rect_free(c);

  return 0;
}

#endif
