#include "test_me.h"

START_TEST(inverse_matrix1) {
  matrix_t a, res;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 0;
  ck_assert_int_eq(2, s21_inverse_matrix(&a, &res));
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(inverse_matrix2) {
  matrix_t a, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 2;
  a.matrix[0][1] = 1;
  a.matrix[1][0] = 5;
  a.matrix[1][1] = 0;
  ck_assert_int_eq(0, s21_inverse_matrix(&a, &res));
  ck_assert_float_eq_tol(0, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(0.2, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(1, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(-0.4, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix3) {
  matrix_t a, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 1.54;
  a.matrix[0][1] = 5.6;
  a.matrix[1][0] = -1.23;
  a.matrix[1][1] = 2.65;
  ck_assert_int_eq(0, s21_inverse_matrix(&a, &res));
  ck_assert_float_eq_tol(0.24158994, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(-0.51052967, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(0.1121342, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(0.14039566, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix4) {
  matrix_t a, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 2;
  a.matrix[0][1] = -2;
  a.matrix[1][0] = 5;
  a.matrix[1][1] = -4;
  ck_assert_int_eq(0, s21_inverse_matrix(&a, &res));
  ck_assert_float_eq_tol(-2, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(1, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(-2.5, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(1, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix5) {
  matrix_t a, res;
  s21_create_matrix(3, 2, &a);
  ck_assert_int_eq(2, s21_inverse_matrix(&a, &res));
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(inverse_matrix6) {
  matrix_t a, res;
  s21_create_matrix(3, 10, &a);
  ck_assert_int_eq(2, s21_inverse_matrix(&a, &res));
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(inverse_matrix7) {
  matrix_t a, res;
  s21_create_matrix(3, 3, &a);
  a.matrix[0][0] = 2;
  a.matrix[0][1] = 1;
  a.matrix[0][2] = 4;
  a.matrix[1][0] = 8;
  a.matrix[1][1] = -2;
  a.matrix[1][2] = -6;
  a.matrix[2][0] = 2;
  a.matrix[2][1] = -2;
  a.matrix[2][2] = 4;
  ck_assert_int_eq(0, s21_inverse_matrix(&a, &res));
  ck_assert_float_eq_tol(0.15151515, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(0.09090909, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(-0.015151515, res.matrix[0][2], 1e-7);
  ck_assert_float_eq_tol(0.33333333, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(0, res.matrix[1][1], 1e-7);
  ck_assert_float_eq_tol(-0.33333333, res.matrix[1][2], 1e-7);
  ck_assert_float_eq_tol(0.0909090909, res.matrix[2][0], 1e-7);
  ck_assert_float_eq_tol(-0.045454545, res.matrix[2][1], 1e-7);
  ck_assert_float_eq_tol(0.0909090909, res.matrix[2][2], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix10) {
  ck_assert_int_eq(1, s21_inverse_matrix(NULL, NULL));
}
END_TEST

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_inverse_matrix=-\033[0m");
  TCase *tc = tcase_create("inverse_matrixtc");

  tcase_add_test(tc, inverse_matrix1);
  tcase_add_test(tc, inverse_matrix2);
  tcase_add_test(tc, inverse_matrix3);
  tcase_add_test(tc, inverse_matrix4);
  tcase_add_test(tc, inverse_matrix5);
  tcase_add_test(tc, inverse_matrix6);
  tcase_add_test(tc, inverse_matrix7);
  tcase_add_test(tc, inverse_matrix10);
  suite_add_tcase(s, tc);
  return s;
}
