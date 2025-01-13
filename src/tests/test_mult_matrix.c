#include "test_me.h"

START_TEST(mult_matrix1) {
  matrix_t a, b, res;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 0;

  s21_create_matrix(1, 1, &b);
  b.matrix[0][0] = 0;
  ck_assert_int_eq(0, s21_mult_matrix(&a, &b, &res));
  ck_assert_float_eq_tol(0, res.matrix[0][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix2) {
  matrix_t a, b, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[1][0] = 5;
  a.matrix[1][1] = 43;
  s21_create_matrix(2, 2, &b);
  b.matrix[0][0] = -1;
  b.matrix[0][1] = -9;
  b.matrix[1][0] = 2;
  b.matrix[1][1] = 1;
  ck_assert_int_eq(0, s21_mult_matrix(&a, &b, &res));
  ck_assert_float_eq_tol(3, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(-7, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(81, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(-2, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix3) {
  matrix_t a, b, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = -2;
  a.matrix[1][0] = -5;
  a.matrix[1][1] = 8;
  s21_create_matrix(2, 2, &b);
  b.matrix[0][0] = -1;
  b.matrix[0][1] = -9;
  b.matrix[1][0] = 2;
  b.matrix[1][1] = 1;
  ck_assert_int_eq(0, s21_mult_matrix(&a, &b, &res));
  ck_assert_float_eq_tol(-5, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(-11, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(21, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(53, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix4) {
  matrix_t a, b, res;
  s21_create_matrix(2, 1, &a);
  a.matrix[0][0] = 4;
  a.matrix[1][0] = -5;
  s21_create_matrix(1, 2, &b);
  b.matrix[0][0] = 2;
  b.matrix[0][1] = 7;

  ck_assert_int_eq(0, s21_mult_matrix(&a, &b, &res));
  ck_assert_float_eq_tol(8, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(28, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(-10, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(-35, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix5) {
  matrix_t a, b, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 0;
  a.matrix[0][1] = 4.69;
  a.matrix[1][0] = -7.59;
  a.matrix[1][1] = 1.596;
  s21_create_matrix(2, 2, &b);
  b.matrix[0][0] = 0.459;
  b.matrix[0][1] = 9.3;
  b.matrix[1][0] = -12.3;
  b.matrix[1][1] = 1.003;
  ck_assert_int_eq(0, s21_mult_matrix(&a, &b, &res));
  ck_assert_float_eq_tol(-57.687, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(4.70407, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(-23.11461, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(-68.986212, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix6) {
  matrix_t a, b, res;
  s21_create_matrix(1, 2, &a);
  a.matrix[0][0] = 7.5698;
  a.matrix[0][1] = 4.69;
  s21_create_matrix(2, 1, &b);
  b.matrix[0][0] = 0.459;
  b.matrix[1][0] = -12.3789;
  ck_assert_int_eq(0, s21_mult_matrix(&a, &b, &res));
  ck_assert_float_eq_tol(-54.5825028, res.matrix[0][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix7) {
  matrix_t a, b, res;
  s21_create_matrix(1, 2, &a);
  a.matrix[0][0] = 7.5698;
  a.matrix[0][1] = 4.69;
  s21_create_matrix(1, 1, &b);
  b.matrix[0][0] = 0.459;
  ck_assert_int_eq(2, s21_mult_matrix(&a, &b, &res));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(mult_matrix8) {
  ck_assert_int_eq(1, s21_mult_matrix(NULL, NULL, NULL));
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_mult_matrix=-\033[0m");
  TCase *tc = tcase_create("mult_matrixtc");

  tcase_add_test(tc, mult_matrix1);
  tcase_add_test(tc, mult_matrix2);
  tcase_add_test(tc, mult_matrix3);
  tcase_add_test(tc, mult_matrix4);
  tcase_add_test(tc, mult_matrix5);
  tcase_add_test(tc, mult_matrix6);
  tcase_add_test(tc, mult_matrix7);
  tcase_add_test(tc, mult_matrix8);
  suite_add_tcase(s, tc);
  return s;
}
