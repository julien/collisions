#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "vec2.h"

typedef struct {
  vec2 * point1;
  vec2 * point2;
} segment;

segment * segment_init(x1, y1, x2, y2) {
  segment * s = malloc(sizeof(segment));

  if (s != NULL) {
    s->point1 = vec2_init(x1, y1);
    s->point2 = vec2_init(x2, y2);
  }

  return s;
}

void segment_free(segment * s) {
  if (s != NULL) {
    vec2_free(s->point1);
    vec2_free(s->point2);
    free(s);
  }
}

#endif
