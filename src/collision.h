#ifndef __COLLISION_H__
#define __COLLISION_H__

#include <math.h>
#include "vec2.h"
#include "circle.h"
#include "line.h"
#include "segment.h"
#include "rect.h"
#include "xrect.h"
#include "utils.h"

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

/* circle-circle collision */
int circle_collides(circle * a, circle * b) {
  float radii = a->radius * b->radius;
  vec2 * dist = vec2_sub(a->center, b->center);
  return vec2_length(dist) < radii;
}

/* point-point collision */
int points_collide(vec2 * a, vec2 * b) {
  return eqfloats(a->x, b->x) && eqfloats(a->y, b->y);
}


#endif
