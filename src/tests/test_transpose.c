#include "test_me.h"

START_TEST(transpose1) {
  matrix_t a, res;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 0;
  ck_assert_int_eq(0, s21_transpose(&a, &res));
  ck_assert_float_eq_tol(0, res.matrix[0][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose2) {
  matrix_t a, res;
  s21_create_matrix(1, 2, &a);
  a.matrix[0][0] = 0;
  a.matrix[0][1] = 1.56;
  ck_assert_int_eq(0, s21_transpose(&a, &res));
  ck_assert_float_eq_tol(0, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(1.56, res.matrix[1][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose3) {
  matrix_t a, res;
  s21_create_matrix(2, 1, &a);
  a.matrix[0][0] = 8.95;
  a.matrix[1][0] = 45.69;
  ck_assert_int_eq(0, s21_transpose(&a, &res));
  ck_assert_float_eq_tol(45.69, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(8.95, res.matrix[0][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose4) {
  matrix_t a, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 486.5;
  a.matrix[0][1] = -4.59;
  a.matrix[1][0] = 5.69;
  a.matrix[1][1] = 78.6;
  ck_assert_int_eq(0, s21_transpose(&a, &res));
  ck_assert_float_eq_tol(486.5, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(-4.59, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(5.69, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(78.6, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose5) { ck_assert_int_eq(1, s21_transpose(NULL, NULL)); }
END_TEST

Suite *test_transpose(void) {
  Suite *s = suite_create("\033[45m-=S21_transpose=-\033[0m");
  TCase *tc = tcase_create("transposetc");

  tcase_add_test(tc, transpose1);
  tcase_add_test(tc, transpose2);
  tcase_add_test(tc, transpose4);
  tcase_add_test(tc, transpose3);
  tcase_add_test(tc, transpose5);
  suite_add_tcase(s, tc);
  return s;
}
