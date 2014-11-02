#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "minunit.h"
#include "vec2_tests.h"
#include "rect_tests.h"

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

  // /* recangle-rectangle collision */
  // rect * r1 = rect_init(1, 1, 4, 4);
  // rect * r2 = rect_init(2, 2, 5, 5);

  // assert(1 == rect_collides(*r1, *r2));

  // rect_free(r1);
  // rect_free(r2);

}

