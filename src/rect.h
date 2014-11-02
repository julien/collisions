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

/* rectangle-rectangle collision */
int rect_collides(rect * a, rect * b) {
  float left1  = a->origin->x;
  float right1 = left1 + a->size->x;

  float left2  = b->origin->x;
  float right2 = left2 + b->size->x;

  float bottom1 = a->origin->y;
  float top1 = bottom1 + a->size->y;

  float bottom2 = b->origin->y;
  float top2 = bottom2 + b->size->y;

  return overlap(left1, right1, left2, right2) && overlap(bottom1, top1, bottom2, top2);
}

#endif
