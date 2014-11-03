#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "minunit.h"
#include "tests.h"

int tests_run = 0;

static char * all_tests() {
  /* vec2 tests */
  mu_run_test(test_vec2_init);
  mu_run_test(test_vec2_add);
  mu_run_test(test_vec2_neg);
  mu_run_test(test_vec2_set);
  mu_run_test(test_vec2_assertEq);
  mu_run_test(test_vec2_equals);
  mu_run_test(test_vec2_mul);
  mu_run_test(test_vec2_div);
  mu_run_test(test_vec2_length);
  mu_run_test(test_vec2_unit);
  mu_run_test(test_vec2_rotate);
  mu_run_test(test_vec2_dotproduct);
  mu_run_test(test_vec2_enclosed_angle);

  /* rect tests */
  mu_run_test(test_rect_init);

  /* circle tests */
  mu_run_test(test_circle_init);

  /* collision tests */
  mu_run_test(test_rect_collides);
  mu_run_test(test_circle_collides);
  mu_run_test(test_points_collide);

  return 0;
}

int main(int agrc, char ** argv) {

  char *result = all_tests();

  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("all tests passed\n");
  }

  return result != 0;
}

