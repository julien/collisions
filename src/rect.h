#ifndef __RECT_H__
#define __RECT_H__

#include "vec2.h"

typedef struct {
  vec2 * origin;
  vec2 * size;
} rect;

rect * rect_init(x, y, w, h) {
  rect * r = malloc(sizeof(rect));

  if (r != NULL) {
    r->origin = vec2_init(x, y);
    r->size = vec2_init(w, h);
  }
  return r;
}

void rect_free(rect * r) {
  if (r != NULL) {
    vec2_free(r->origin);
    vec2_free(r->size);
    free(r);
  }
}

#endif
