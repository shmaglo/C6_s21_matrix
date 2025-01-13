#include "test_me.h"

START_TEST(calc_complements1) {
  matrix_t a, res;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 0;
  ck_assert_int_eq(0, s21_calc_complements(&a, &res));
  ck_assert_float_eq_tol(0, res.matrix[0][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements2) {
  matrix_t a, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 2;
  a.matrix[0][1] = 1;
  a.matrix[1][0] = 5;
  a.matrix[1][1] = 0;
  ck_assert_int_eq(0, s21_calc_complements(&a, &res));
  ck_assert_float_eq_tol(0, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(-5, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(-1, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(2, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements3) {
  matrix_t a, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 1.54;
  a.matrix[0][1] = 5.6;
  a.matrix[1][0] = -1.23;
  a.matrix[1][1] = 2.65;
  ck_assert_int_eq(0, s21_calc_complements(&a, &res));
  ck_assert_float_eq_tol(2.65, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(1.23, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(-5.6, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(1.54, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements4) {
  matrix_t a, res;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 2;
  a.matrix[0][1] = -2;
  a.matrix[1][0] = 5;
  a.matrix[1][1] = -4;
  ck_assert_int_eq(0, s21_calc_complements(&a, &res));
  ck_assert_float_eq_tol(-4, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(-5, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(2, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(2, res.matrix[1][1], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements5) {
  matrix_t a, res;
  s21_create_matrix(3, 2, &a);
  ck_assert_int_eq(2, s21_calc_complements(&a, &res));
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(calc_complements6) {
  matrix_t a, res;
  s21_create_matrix(3, 10, &a);
  ck_assert_int_eq(2, s21_calc_complements(&a, &res));
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(calc_complements7) {
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
  ck_assert_int_eq(0, s21_calc_complements(&a, &res));
  ck_assert_float_eq_tol(-20, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(-44, res.matrix[0][1], 1e-7);
  ck_assert_float_eq_tol(-12, res.matrix[0][2], 1e-7);
  ck_assert_float_eq_tol(-12, res.matrix[1][0], 1e-7);
  ck_assert_float_eq_tol(0, res.matrix[1][1], 1e-7);
  ck_assert_float_eq_tol(6, res.matrix[1][2], 1e-7);
  ck_assert_float_eq_tol(2, res.matrix[2][0], 1e-7);
  ck_assert_float_eq_tol(44, res.matrix[2][1], 1e-7);
  ck_assert_float_eq_tol(-12, res.matrix[2][2], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements10) {
  ck_assert_int_eq(1, s21_calc_complements(NULL, NULL));
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *s = suite_create("\033[45m-=S21_calc_complements=-\033[0m");
  TCase *tc = tcase_create("calc_complementstc");

  tcase_add_test(tc, calc_complements1);
  tcase_add_test(tc, calc_complements2);
  tcase_add_test(tc, calc_complements3);
  tcase_add_test(tc, calc_complements4);
  tcase_add_test(tc, calc_complements5);
  tcase_add_test(tc, calc_complements6);
  tcase_add_test(tc, calc_complements7);
  tcase_add_test(tc, calc_complements10);
  suite_add_tcase(s, tc);
  return s;
}
