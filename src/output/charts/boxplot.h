/* PSPP - a program for statistical analysis.
   Copyright (C) 2004, 2009, 2011 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef OUTPUT_CHARTS_BOXPLOT_H
#define OUTPUT_CHARTS_BOXPLOT_H 1

#include <stddef.h>
#include "output/chart-item.h"

/* Box-whiskers plot. */
struct boxplot
  {
    struct chart_item chart_item;

    /* Data. */
    struct boxplot_box *boxes;
    size_t n_boxes, boxes_allocated;

    /* Derived from data and convenient for plotting. */
    double y_min;               /* Minimum Y coordinate of extremum. */
    double y_max;               /* Maximum Y coordinate of extremum. */
  };

/* One box within a box-whiskers plot. */
struct boxplot_box
  {
    struct box_whisker *bw;
    char *label;                /* Variable name or factor label. */
  };

struct boxplot *boxplot_create (double y_min, double y_max, const char *title);
void boxplot_add_box (struct boxplot *,
                      struct box_whisker *, const char *label);

/* This boilerplate for boxplot, a subclass of chart_item, was
   autogenerated by mk-class-boilerplate. */

#include <assert.h>
#include "libpspp/cast.h"

extern const struct chart_item_class boxplot_class;

/* Returns true if SUPER is a boxplot, otherwise false. */
static inline bool
is_boxplot (const struct chart_item *super)
{
  return super->class == &boxplot_class;
}

/* Returns SUPER converted to boxplot.  SUPER must be a boxplot, as
   reported by is_boxplot. */
static inline struct boxplot *
to_boxplot (const struct chart_item *super)
{
  assert (is_boxplot (super));
  return UP_CAST (super, struct boxplot, chart_item);
}

/* Returns INSTANCE converted to chart_item. */
static inline struct chart_item *
boxplot_super (const struct boxplot *instance)
{
  return CONST_CAST (struct chart_item *, &instance->chart_item);
}

/* Increments INSTANCE's reference count and returns INSTANCE. */
static inline struct boxplot *
boxplot_ref (const struct boxplot *instance)
{
  return to_boxplot (chart_item_ref (&instance->chart_item));
}

/* Decrements INSTANCE's reference count, then destroys INSTANCE if
   the reference count is now zero. */
static inline void
boxplot_unref (struct boxplot *instance)
{
  chart_item_unref (&instance->chart_item);
}

/* Returns true if INSTANCE's reference count is greater than 1,
   false otherwise. */
static inline bool
boxplot_is_shared (const struct boxplot *instance)
{
  return chart_item_is_shared (&instance->chart_item);
}

static inline void
boxplot_submit (struct boxplot *instance)
{
  chart_item_submit (&instance->chart_item);
}

#endif /* output/charts/boxplot.h */
