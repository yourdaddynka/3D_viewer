#include "../header/modules.h"

void count_vertices_and_polygonals(FILE *file, model_data *data) {
  char *buff_str = NULL;
  size_t ln = 0;
  while (getline(&buff_str, &ln, file) != EOF) {
    if (strncmp(buff_str, "v ", 2) == 0) {
      data->vertices_v_count++;
    } else if (strncmp(buff_str, "f ", 2) == 0) {
      char *polygonals_indx = strtok(buff_str + 2, " ");
      while (polygonals_indx) {
        if (atoi(polygonals_indx)) data->polygonals_f_count++;
        polygonals_indx = strtok(NULL, " ");
      }
    }
  }
  if (buff_str) free(buff_str);
}

int memory_allocation(model_data *data) {
  int exit_status = OK;
  if (data->vertices_v_count)
    data->vertices_v_arr = calloc(data->vertices_v_count * 3, sizeof(double));
  if (data->polygonals_f_count)
    data->polygonals_f_arr = calloc(data->polygonals_f_count * 2, sizeof(int));
  if (!data->polygonals_f_arr || !data->vertices_v_arr) exit_status = ERROR;
  return exit_status;
}

void memory_free(model_data *data) {
  if (data != NULL) {
    if (data->vertices_v_arr != NULL) {
      free(data->vertices_v_arr);
      data->vertices_v_arr = NULL;
    }
    if (data->polygonals_f_arr != NULL) {
      free(data->polygonals_f_arr);
      data->polygonals_f_arr = NULL;
    }
  }
}

void parse_polygons(char *buff_str, size_t polygonals_count, model_data *data,
                    size_t *f_j) {
  int first_indx = 0;
  bool is_first_indx = true;
  char *polygonals_indx = strtok(buff_str + 2, " ");
  while (polygonals_indx) {
    int indx_value = atoi(polygonals_indx);
    if (indx_value) {
      if (indx_value < 0) {
        indx_value += polygonals_count;
      } else
        indx_value -= 1;
      if (is_first_indx) {
        data->polygonals_f_arr[*f_j] = indx_value;
        *f_j += 1;
        first_indx = indx_value;
        is_first_indx = false;
      } else {
        data->polygonals_f_arr[*f_j] = indx_value;
        *f_j += 1;
        data->polygonals_f_arr[*f_j] = indx_value;
        *f_j += 1;
      }
    }
    polygonals_indx = strtok(NULL, " ");
  }
  data->polygonals_f_arr[*f_j] = first_indx;
  *f_j += 1;
}

int parse_vertices_and_polygonals(FILE *file, model_data *data) {
  int exit_status = OK;
  char *buff_str = NULL;
  size_t ln = 0, v_i = 0, f_j = 0, polygonals_count = 0;
  while (getline(&buff_str, &ln, file) != EOF) {
    if (strncmp(buff_str, "v ", 2) == 0) {
      double x = 0, y = 0, z = 0;
      if (sscanf(buff_str, "v %lf %lf %lf", &x, &y, &z) != 0) {
        data->vertices_v_arr[v_i++] = x;
        data->vertices_v_arr[v_i++] = y;
        data->vertices_v_arr[v_i++] = z;
        polygonals_count++;
      } else {
        exit_status = ERROR;
        break;
      }
    } else if (strncmp(buff_str, "f ", 2) == 0) {
      parse_polygons(buff_str, polygonals_count, data, &f_j);
    }
  }
  if (buff_str) free(buff_str);
  return exit_status;
}

int file_parser_obj(char *file_name, model_data *data) {
  if (file_name == NULL) return ERROR;
  int exit_status = OK;
  FILE *obj_file = fopen(file_name, "r");
  if (data != NULL && obj_file) {
    count_vertices_and_polygonals(obj_file, data);
    if (memory_allocation(data) == OK) {
      fseek(obj_file, 0, SEEK_SET);
      exit_status = parse_vertices_and_polygonals(obj_file, data);
    } else
      exit_status = ERROR;
    fclose(obj_file);
  } else
    exit_status = ERROR;
  return exit_status;
}
