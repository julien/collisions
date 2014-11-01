#ifndef __XRECT_H__
#define __XRECT_H__

#include "vec2.h"

/* oriented rectangle */
typedef struct {
  vec2 * center;
  vec2 * halfExtend;
  float angle;
} xrect;

xrect * xrect_init(float x, float y, float w, float h, float angle) {
  xrect * x = malloc(sizeof(xrect));

  if (x != NULL) {
    x->center = vec2_init(x, y);
    x->halfExtend = vec2_init(w, h);
    x->angle = angle;
  }

  return x;
}

void xrect_free(xrect * x) {
  if (x != NULL) {
    vec2_free(x->center);
    vec2_free(x->halfExtend);
    free(x);
  }
}

#endif
