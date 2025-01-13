#include "test_me.h"

START_TEST(determinant1) {
  matrix_t a;
  double ans = 0;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 0;
  ck_assert_int_eq(0, s21_determinant(&a, &ans));
  ck_assert_float_eq_tol(0, ans, 1e-7);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant2) {
  matrix_t a;
  double ans = 0;
  s21_create_matrix(2, 1, &a);
  a.matrix[0][0] = 0;
  a.matrix[1][0] = 0;
  ck_assert_int_eq(2, s21_determinant(&a, &ans));
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant3) {
  matrix_t a;
  double ans = 0;
  s21_create_matrix(2, 4, &a);
  ck_assert_int_eq(2, s21_determinant(&a, &ans));
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant4) {
  matrix_t a;
  double ans = 0;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 1;
  a.matrix[1][0] = 1;
  a.matrix[0][1] = 1;
  a.matrix[1][1] = 1;

  ck_assert_int_eq(0, s21_determinant(&a, &ans));
  ck_assert_float_eq_tol(0, ans, 1e-7);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant5) {
  matrix_t a;
  double ans = 0;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 1.56;
  a.matrix[1][0] = 0.56;
  a.matrix[0][1] = 1.86;
  a.matrix[1][1] = 2.04;

  ck_assert_int_eq(0, s21_determinant(&a, &ans));
  ck_assert_float_eq_tol(2.1408, ans, 1e-7);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant6) {
  matrix_t a;
  double ans = 0;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 1.5636;
  a.matrix[0][1] = 8.6523;
  a.matrix[1][0] = 0.005;
  a.matrix[1][1] = -1.265;

  ck_assert_int_eq(0, s21_determinant(&a, &ans));
  ck_assert_float_eq_tol(-2.0212155, ans, 1e-7);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant7) {
  matrix_t a;
  double ans = 0;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 1;
  a.matrix[1][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[1][1] = 1;

  ck_assert_int_eq(0, s21_determinant(&a, &ans));
  ck_assert_float_eq_tol(-1, ans, 1e-7);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant8) {
  matrix_t a;
  double ans = 0;
  s21_create_matrix(3, 3, &a);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 9;
  ck_assert_int_eq(0, s21_determinant(&a, &ans));
  ck_assert_float_eq_tol(0, ans, 1e-7);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant9) {
  matrix_t a;
  double ans = 0;
  s21_create_matrix(3, 3, &a);
  a.matrix[0][0] = 10;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 6;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 9;
  ck_assert_int_eq(0, s21_determinant(&a, &ans));
  ck_assert_float_eq_tol(-234, ans, 1e-7);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant10) { ck_assert_int_eq(1, s21_determinant(NULL, NULL)); }
END_TEST

Suite *test_determinant(void) {
  Suite *s = suite_create("\033[45m-=S21_determinant=-\033[0m");
  TCase *tc = tcase_create("determinanttc");

  tcase_add_test(tc, determinant1);
  tcase_add_test(tc, determinant2);
  tcase_add_test(tc, determinant3);
  tcase_add_test(tc, determinant4);
  tcase_add_test(tc, determinant5);
  tcase_add_test(tc, determinant6);
  tcase_add_test(tc, determinant7);
  tcase_add_test(tc, determinant8);
  tcase_add_test(tc, determinant9);
  tcase_add_test(tc, determinant10);

  suite_add_tcase(s, tc);
  return s;
}
