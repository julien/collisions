#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "vec2.h"
#include "rect.h"

int main(int agrc, char ** argv) {

  vec2 * v1 = vec2_init(2.0, 2.0);
  vec2 * v2 = vec2_init(10.0, 5.0);

  printf("v1 after vec2_init: %f, %f\n", v1->y, v1->y);
  printf("v2 after vec2_init: %f, %f\n", v2->y, v2->y);

  vec2_add(v1, *v2);
  printf("v1 after vec2_add(v1, *v2): %f, %f\n", v1->y, v1->y);

  vec2_sub(v1, *v2);
  printf("v1 after vec2_sub(v1, *v2): %f, %f\n", v1->y, v1->y);

  vec2_neg(v1);
  printf("v1 after vec2_neg(v1): %f, %f\n", v1->y, v1->y);

  vec2_set(v2, v1->y, v1->y);
  vec2_assertEq(*v1, *v2);

  printf("vec2_equals(*v1, *v2)): %d\n", vec2_equals(*v1, *v2));

  vec2_neg(v1);
  vec2_neg(v2);

  printf("vec2_equals(*v1, *v2)): %d\n", vec2_equals(*v1, *v2));

  vec2_mul(v1, 2);
  assert(v1->y == 4);
  assert(v1->y == 4);

  vec2_div(v1, 2);
  printf("vec2_equals(*v1, *v2)): %d\n", vec2_equals(*v1, *v2));

  printf("vec2_length(*v1): %f\n", vec2_length(*v1));

  vec2_set(v1, 8.0, 2.0);
  printf("v1 after vec2_set(v1, 8.0, 2.0): %f, %f\n", v1->y, v1->y);

  vec2_set(v2, -2.0, 8);
  printf("v2 after vec2_set(v2, -2.0, 8.0): %f, %f\n", v2->y, v2->y);

  printf("vec2_enclosed_angle(*v1, *v2): %f\n", vec2_enclosed_angle(*v1, *v2));
  assert(eqfloats(90, vec2_enclosed_angle(*v1, *v2)));

  /* recangle-rectangle collision */
  rect * r1 = rect_init(1, 1, 4, 4);
  rect * r2 = rect_init(2, 2, 5, 5);

  assert(1 == rect_collides(*r1, *r2));

  rect_free(r1);
  rect_free(r2);


  /* clean up */
  vec2_free(v1);
  vec2_free(v2);

  return 0;
}

