#ifndef MODULES_H
#define MODULES_H

#define _GNU_SOURCE

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846264338327950288

typedef struct data {
  unsigned int vertices_v_count;
  double *vertices_v_arr;
  unsigned int polygonals_f_count;
  int *polygonals_f_arr;
} model_data;

enum exit_status { OK, ERROR };

/*PARSER*/

int file_parser_obj(char *file_name, model_data *data);
void memory_free(model_data *data);

/*AFFINE TRANSFORMATIONS*/

void move_X(model_data *data, const double k);
void move_Y(model_data *data, const double k);
void move_Z(model_data *data, const double k);
void scale(model_data *data, const double k);
void rotate_X(model_data *data, double angle);
void rotate_Y(model_data *data, double angle);
void rotate_Z(model_data *data, double angle);

#endif  // MODULES_H
