#ifndef __LINE_H__
#define __LINE_H__

#include "vec2.h"

typedef struct {
  vec2 * base;
  vec2 * direction;
} line;

line * line_init(x, y, w, h) {
  line * l = malloc(sizeof(line));

  if (l != NULL) {
    l->base = vec2_init(x, y);
    l->direction = vec2_init(w, h);
  }


  return l;
}

void line_free(line * l) {
  if (l != NULL) {
    free(l);
  }
}

#endif
