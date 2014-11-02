#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "minunit.h"
#include "vec2_tests.h"
#include "rect_tests.h"
#include "circle_tests.h"

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
  mu_run_test(test_rect_collides);

  /* circle tests */
  mu_run_test(test_circle_init);
  mu_run_test(test_circle_collides);

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

