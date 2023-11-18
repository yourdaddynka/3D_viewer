#include "../header/modules.h"

void move_X(model_data *data, const double k) {
  for (size_t i = 0; i < data->vertices_v_count * 3; i += 3) {
    data->vertices_v_arr[i] += k;
  }
}

void move_Y(model_data *data, const double k) {
  for (size_t i = 1; i < data->vertices_v_count * 3; i += 3) {
    data->vertices_v_arr[i] += k;
  }
}

void move_Z(model_data *data, const double k) {
  for (size_t i = 2; i < data->vertices_v_count * 3; i += 3) {
    data->vertices_v_arr[i] += k;
  }
}

void scale(model_data *data, const double k) {
  if (k != 0) {
    for (size_t i = 0; i < data->vertices_v_count * 3; i++) {
      data->vertices_v_arr[i] *= k;
    }
  }
}

void rotate_X(model_data *data, double angle) {
  angle = angle * PI / 180;
  for (size_t i = 0; i < data->vertices_v_count * 3; i += 3) {
    double Y = data->vertices_v_arr[i + 1];
    double Z = data->vertices_v_arr[i + 2];
    data->vertices_v_arr[i + 1] = Y * cos(angle) + Z * sin(angle);
    data->vertices_v_arr[i + 2] = -Y * sin(angle) + Z * cos(angle);
  }
}

void rotate_Y(model_data *data, double angle) {
  angle = angle * PI / 180;
  for (size_t i = 0; i < data->vertices_v_count * 3; i += 3) {
    double X = data->vertices_v_arr[i];
    double Z = data->vertices_v_arr[i + 2];
    data->vertices_v_arr[i] = X * cos(angle) + Z * sin(angle);
    data->vertices_v_arr[i + 2] = -X * sin(angle) + Z * cos(angle);
  }
}

void rotate_Z(model_data *data, double angle) {
  angle = angle * PI / 180;
  for (size_t i = 0; i < data->vertices_v_count * 3; i += 3) {
    double X = data->vertices_v_arr[i];
    double Y = data->vertices_v_arr[i + 1];
    data->vertices_v_arr[i] = X * cos(angle) + Y * sin(angle);
    data->vertices_v_arr[i + 1] = -X * sin(angle) + Y * cos(angle);
  }
}
