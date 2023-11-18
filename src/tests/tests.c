#include <check.h>

#include "../modules/header/modules.h"

#define EPS 1e-07

START_TEST(parser_1) {
  model_data d = {0};
  char filename[] = "obj_files/xxx.obj";
  int res = file_parser_obj(filename, &d);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(parser_2) {
  model_data d = {0};
  char *filename = NULL;
  int res = file_parser_obj(filename, &d);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(affine_transformation_1) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, 0.0000000, 0.0000000,  0.0000000, 1.0000000, 1.7320508,
      0.0000000, 1.7320508, -1.0000000, 0.0000000, 2.7320508, 0.7320508,
      2.0000000, 0.0000000, 0.0000000,  2.0000000, 1.0000000, 1.7320508,
      2.0000000, 1.7320508, -1.0000000, 2.0000000, 2.7320508, 0.7320508};
  file_parser_obj(filename, &d);
  rotate_X(&d, 30);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_2) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, 0.0000000, 0.0000000, 0.0000000, -1.0000000, 1.7320508,
      0.0000000, 1.7320508, 1.0000000, 0.0000000, 0.7320508,  2.7320508,
      2.0000000, 0.0000000, 0.0000000, 2.0000000, -1.0000000, 1.7320508,
      2.0000000, 1.7320508, 1.0000000, 2.0000000, 0.7320508,  2.7320508};
  file_parser_obj(filename, &d);
  rotate_X(&d, -30);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);
  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_3) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, -0.0000000, 0.0000000, 0.0000000, -0.6840403, -1.8793852,
      0.0000000, -1.8793852, 0.6840403, 0.0000000, -2.5634255, -1.1953450,
      2.0000000, -0.0000000, 0.0000000, 2.0000000, -0.6840403, -1.8793852,
      2.0000000, -1.8793852, 0.6840403, 2.0000000, -2.5634255, -1.1953450};
  file_parser_obj(filename, &d);
  rotate_X(&d, 2000000);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);
  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_4) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, 0.0000000, 0.0000000,  1.0000000, 0.0000000, 1.7320508,
      0.0000000, 2.0000000, 0.0000000,  1.0000000, 2.0000000, 1.7320508,
      1.7320508, 0.0000000, -1.0000000, 2.7320508, 0.0000000, 0.7320508,
      1.7320508, 2.0000000, -1.0000000, 2.7320508, 2.0000000, 0.7320508};
  file_parser_obj(filename, &d);
  rotate_Y(&d, 30);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_5) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, 0.0000000, 0.0000000, -1.0000000, 0.0000000, 1.7320508,
      0.0000000, 2.0000000, 0.0000000, -1.0000000, 2.0000000, 1.7320508,
      1.7320508, 0.0000000, 1.0000000, 0.7320508,  0.0000000, 2.7320508,
      1.7320508, 2.0000000, 1.0000000, 0.7320508,  2.0000000, 2.7320508};
  file_parser_obj(filename, &d);
  rotate_Y(&d, -30);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_6) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      -0.0000000, 0.0000000, 0.0000000, -0.6840403, 0.0000000, -1.8793852,
      -0.0000000, 2.0000000, 0.0000000, -0.6840403, 2.0000000, -1.8793852,
      -1.8793852, 0.0000000, 0.6840403, -2.5634255, 0.0000000, -1.1953450,
      -1.8793852, 2.0000000, 0.6840403, -2.5634255, 2.0000000, -1.1953450};
  file_parser_obj(filename, &d);
  rotate_Y(&d, 2000000);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_7) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, 0.0000000,  0.0000000, 0.0000000, 0.0000000,  2.0000000,
      1.0000000, 1.7320508,  0.0000000, 1.0000000, 1.7320508,  2.0000000,
      1.7320508, -1.0000000, 0.0000000, 1.7320508, -1.0000000, 2.0000000,
      2.7320508, 0.7320508,  0.0000000, 2.7320508, 0.7320508,  2.0000000};
  file_parser_obj(filename, &d);
  rotate_Z(&d, 30);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_8) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000,  0.0000000, 0.0000000, 0.0000000,  0.0000000, 2.0000000,
      -1.0000000, 1.7320508, 0.0000000, -1.0000000, 1.7320508, 2.0000000,
      1.7320508,  1.0000000, 0.0000000, 1.7320508,  1.0000000, 2.0000000,
      0.7320508,  2.7320508, 0.0000000, 0.7320508,  2.7320508, 2.0000000};
  file_parser_obj(filename, &d);
  rotate_Z(&d, -30);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_9) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      -0.0000000, 0.0000000,  0.0000000, -0.0000000, 0.0000000,  2.0000000,
      -0.6840403, -1.8793852, 0.0000000, -0.6840403, -1.8793852, 2.0000000,
      -1.8793852, 0.6840403,  0.0000000, -1.8793852, 0.6840403,  2.0000000,
      -2.5634255, -1.1953450, 0.0000000, -2.5634255, -1.1953450, 2.0000000};
  file_parser_obj(filename, &d);
  rotate_Z(&d, 2000000);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_10) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 6.0000000,
      0.0000000, 6.0000000, 0.0000000, 0.0000000, 6.0000000, 6.0000000,
      6.0000000, 0.0000000, 0.0000000, 6.0000000, 0.0000000, 6.0000000,
      6.0000000, 6.0000000, 0.0000000, 6.0000000, 6.0000000, 6.0000000};
  file_parser_obj(filename, &d);
  scale(&d, 3);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_11) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.0000000, 0.6000000,
      0.0000000, 0.6000000, 0.0000000, 0.0000000, 0.6000000, 0.6000000,
      0.6000000, 0.0000000, 0.0000000, 0.6000000, 0.0000000, 0.6000000,
      0.6000000, 0.6000000, 0.0000000, 0.6000000, 0.6000000, 0.6000000};
  file_parser_obj(filename, &d);
  scale(&d, 0.3);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_12) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000,      0.0000000,      0.0000000,      0.0000000,
      0.0000000,      666666.0000000, 0.0000000,      666666.0000000,
      0.0000000,      0.0000000,      666666.0000000, 666666.0000000,
      666666.0000000, 0.0000000,      0.0000000,      666666.0000000,
      0.0000000,      666666.0000000, 666666.0000000, 666666.0000000,
      0.0000000,      666666.0000000, 666666.0000000, 666666.0000000};
  file_parser_obj(filename, &d);
  scale(&d, 333333);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_13) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      3.0000000, 0.0000000, 0.0000000, 3.0000000, 0.0000000, 2.0000000,
      3.0000000, 2.0000000, 0.0000000, 3.0000000, 2.0000000, 2.0000000,
      5.0000000, 0.0000000, 0.0000000, 5.0000000, 0.0000000, 2.0000000,
      5.0000000, 2.0000000, 0.0000000, 5.0000000, 2.0000000, 2.0000000};
  file_parser_obj(filename, &d);
  move_X(&d, 3);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_14) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      -3.0000000, 0.0000000, 0.0000000, -3.0000000, 0.0000000, 2.0000000,
      -3.0000000, 2.0000000, 0.0000000, -3.0000000, 2.0000000, 2.0000000,
      -1.0000000, 0.0000000, 0.0000000, -1.0000000, 0.0000000, 2.0000000,
      -1.0000000, 2.0000000, 0.0000000, -1.0000000, 2.0000000, 2.0000000};
  file_parser_obj(filename, &d);
  move_X(&d, -3);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_15) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      -0.5000000, 0.0000000, 0.0000000, -0.5000000, 0.0000000, 2.0000000,
      -0.5000000, 2.0000000, 0.0000000, -0.5000000, 2.0000000, 2.0000000,
      1.5000000,  0.0000000, 0.0000000, 1.5000000,  0.0000000, 2.0000000,
      1.5000000,  2.0000000, 0.0000000, 1.5000000,  2.0000000, 2.0000000};
  file_parser_obj(filename, &d);
  move_X(&d, -0.5);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_16) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, 3.0000000, 0.0000000, 0.0000000, 3.0000000, 2.0000000,
      0.0000000, 5.0000000, 0.0000000, 0.0000000, 5.0000000, 2.0000000,
      2.0000000, 3.0000000, 0.0000000, 2.0000000, 3.0000000, 2.0000000,
      2.0000000, 5.0000000, 0.0000000, 2.0000000, 5.0000000, 2.0000000};
  file_parser_obj(filename, &d);
  move_Y(&d, 3);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_17) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, -0.5000000, 0.0000000, 0.0000000, -0.5000000, 2.0000000,
      0.0000000, 1.5000000,  0.0000000, 0.0000000, 1.5000000,  2.0000000,
      2.0000000, -0.5000000, 0.0000000, 2.0000000, -0.5000000, 2.0000000,
      2.0000000, 1.5000000,  0.0000000, 2.0000000, 1.5000000,  2.0000000};
  file_parser_obj(filename, &d);
  move_Y(&d, -0.5);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_18) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, 0.0000000, 3.0000000, 0.0000000, 0.0000000, 5.0000000,
      0.0000000, 2.0000000, 3.0000000, 0.0000000, 2.0000000, 5.0000000,
      2.0000000, 0.0000000, 3.0000000, 2.0000000, 0.0000000, 5.0000000,
      2.0000000, 2.0000000, 3.0000000, 2.0000000, 2.0000000, 5.0000000};
  file_parser_obj(filename, &d);
  move_Z(&d, 3);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_19) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, 0.0000000, -3.0000000, 0.0000000, 0.0000000, -1.0000000,
      0.0000000, 2.0000000, -3.0000000, 0.0000000, 2.0000000, -1.0000000,
      2.0000000, 0.0000000, -3.0000000, 2.0000000, 0.0000000, -1.0000000,
      2.0000000, 2.0000000, -3.0000000, 2.0000000, 2.0000000, -1.0000000};
  file_parser_obj(filename, &d);
  move_Z(&d, -3);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_20) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, 0.0000000, -0.5000000, 0.0000000, 0.0000000, 1.5000000,
      0.0000000, 2.0000000, -0.5000000, 0.0000000, 2.0000000, 1.5000000,
      2.0000000, 0.0000000, -0.5000000, 2.0000000, 0.0000000, 1.5000000,
      2.0000000, 2.0000000, -0.5000000, 2.0000000, 2.0000000, 1.5000000};
  file_parser_obj(filename, &d);
  move_Z(&d, -0.5);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

START_TEST(affine_transformation_21) {
  model_data d = {0};
  char filename[] = "tests/cube.obj";
  double vertices_v_arr[] = {
      0.0000000, -3.0000000, 0.0000000, 0.0000000, -3.0000000, 2.0000000,
      0.0000000, -1.0000000, 0.0000000, 0.0000000, -1.0000000, 2.0000000,
      2.0000000, -3.0000000, 0.0000000, 2.0000000, -3.0000000, 2.0000000,
      2.0000000, -1.0000000, 0.0000000, 2.0000000, -1.0000000, 2.0000000};
  file_parser_obj(filename, &d);
  move_Y(&d, -3);
  ck_assert_int_eq(d.polygonals_f_count, 30);
  ck_assert_int_eq(d.vertices_v_count, 8);

  int i = 0;
  while (i < (int)d.vertices_v_count * 3) {
    ck_assert_double_eq_tol(d.vertices_v_arr[i], vertices_v_arr[i], EPS);
    i++;
  }
  memory_free(&d);
}
END_TEST

Suite *

three_d_viever(void) {
  Suite *suite = suite_create("3DViewerV1.0");
  TCase *parsing = tcase_create("parsing");
  TCase *affine = tcase_create("affine");

  tcase_add_test(parsing, parser_1);
  tcase_add_test(parsing, parser_2);
  tcase_add_test(affine, affine_transformation_1);
  tcase_add_test(affine, affine_transformation_2);
  tcase_add_test(affine, affine_transformation_3);
  tcase_add_test(affine, affine_transformation_4);
  tcase_add_test(affine, affine_transformation_5);
  tcase_add_test(affine, affine_transformation_6);
  tcase_add_test(affine, affine_transformation_7);
  tcase_add_test(affine, affine_transformation_8);
  tcase_add_test(affine, affine_transformation_9);
  tcase_add_test(affine, affine_transformation_10);
  tcase_add_test(affine, affine_transformation_11);
  tcase_add_test(affine, affine_transformation_12);
  tcase_add_test(affine, affine_transformation_13);
  tcase_add_test(affine, affine_transformation_14);
  tcase_add_test(affine, affine_transformation_15);
  tcase_add_test(affine, affine_transformation_16);
  tcase_add_test(affine, affine_transformation_17);
  tcase_add_test(affine, affine_transformation_18);
  tcase_add_test(affine, affine_transformation_19);
  tcase_add_test(affine, affine_transformation_20);
  tcase_add_test(affine, affine_transformation_21);

  suite_add_tcase(suite, parsing);
  suite_add_tcase(suite, affine);

  return suite;
}

int main(void) {
  int count_failed;
  Suite *s = three_d_viever();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);
  count_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (count_failed == 0) ? 0 : 1;
}
