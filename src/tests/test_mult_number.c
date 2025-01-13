#include "test_me.h"

START_TEST(mult_number1) {
  matrix_t a, res;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 0;
  ck_assert_int_eq(0, s21_mult_number(&a, 1, &res));
  ck_assert_float_eq_tol(0, res.matrix[0][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number2) {
  matrix_t a, res;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 5;
  ck_assert_int_eq(0, s21_mult_number(&a, 3, &res));
  ck_assert_float_eq_tol(15, res.matrix[0][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number3) {
  matrix_t a, res;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 5;
  ck_assert_int_eq(0, s21_mult_number(&a, -3, &res));
  ck_assert_float_eq_tol(-15, res.matrix[0][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number4) {
  matrix_t a, res;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 2.5;
  ck_assert_int_eq(0, s21_mult_number(&a, 1, &res));
  ck_assert_float_eq_tol(2.5, res.matrix[0][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number5) {
  matrix_t a, res;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 2.34;
  ck_assert_int_eq(0, s21_mult_number(&a, 4, &res));
  ck_assert_float_eq_tol(2.34 * 4, res.matrix[0][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}

START_TEST(mult_number6) {
  matrix_t a, res;
  s21_create_matrix(1, 2, &a);
  a.matrix[0][0] = 2.34;
  a.matrix[0][1] = 4.69;
  ck_assert_int_eq(0, s21_mult_number(&a, 4, &res));
  ck_assert_float_eq_tol(2.34 * 4, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(4.69 * 4, res.matrix[0][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}

START_TEST(mult_number7) {
  matrix_t a, res;
  s21_create_matrix(2, 1, &a);
  a.matrix[0][0] = 2.34;
  a.matrix[1][0] = 8.9666;
  ck_assert_int_eq(0, s21_mult_number(&a, 4, &res));
  ck_assert_float_eq_tol(2.34 * 4, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(8.9666 * 4, res.matrix[1][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}

START_TEST(mult_number8) {
  matrix_t a, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 2.34;
  a.matrix[0][1] = 122.34;
  a.matrix[1][0] = -42.312124;
  a.matrix[1][1] = 243.31214;
  ck_assert_int_eq(0, s21_mult_number(&a, 4.96, &res));
  ck_assert_float_eq_tol(2.34 * 4.96, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(-42.312124 * 4.96, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(122.34 * 4.96, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(243.31214 * 4.96, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number9) {
  matrix_t a, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 2.34;
  a.matrix[0][1] = 122.34;
  a.matrix[1][0] = -42.312124;
  a.matrix[1][1] = 243.31214;
  ck_assert_int_eq(0, s21_mult_number(&a, -4.96, &res));
  ck_assert_float_eq_tol(2.34 * (-4.96), res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(-42.312124 * (-4.96), res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(122.34 * (-4.96), res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(243.31214 * (-4.96), res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number10) {
  ck_assert_int_eq(1, s21_mult_number(NULL, -4.96, NULL));
}
END_TEST

START_TEST(mult_number11) {
  matrix_t res;
  ck_assert_int_eq(1, s21_mult_number(NULL, -4.96, &res));
}
END_TEST

Suite *test_mult_number(void) {
  Suite *s = suite_create("\033[45m-=S21_mult_number=-\033[0m");
  TCase *tc = tcase_create("mult_numbertc");

  tcase_add_test(tc, mult_number1);
  tcase_add_test(tc, mult_number2);
  tcase_add_test(tc, mult_number3);
  tcase_add_test(tc, mult_number4);
  tcase_add_test(tc, mult_number5);
  tcase_add_test(tc, mult_number6);
  tcase_add_test(tc, mult_number7);
  tcase_add_test(tc, mult_number8);
  tcase_add_test(tc, mult_number9);
  tcase_add_test(tc, mult_number11);
  tcase_add_test(tc, mult_number10);
  suite_add_tcase(s, tc);
  return s;
}
