#include "test_me.h"

START_TEST(sum_matrix1) {
  matrix_t a, b, res;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 0;
  b.matrix[0][0] = 0;
  ck_assert_int_eq(0, s21_sum_matrix(&a, &b, &res));
  ck_assert_int_eq(0, res.matrix[0][0]);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_matrix2) {
  matrix_t a, b, res;
  s21_create_matrix(1, 2, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 0;
  a.matrix[0][1] = 0;
  b.matrix[0][0] = 0;
  ck_assert_int_eq(2, s21_sum_matrix(&a, &b, &res));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sum_matrix3) {
  matrix_t a, b, res;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 0;
  b.matrix[0][0] = 5;
  ck_assert_int_eq(0, s21_sum_matrix(&a, &b, &res));
  ck_assert_int_eq(5, res.matrix[0][0]);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sum_matrix4) {
  matrix_t a, b, res;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 0;
  b.matrix[0][0] = 5;
  ck_assert_int_eq(0, s21_sum_matrix(&b, &a, &res));
  ck_assert_int_eq(5, res.matrix[0][0]);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sum_matrix5) {
  matrix_t a, b, res;
  s21_create_matrix(2, 1, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 0;
  a.matrix[1][0] = 4.56;
  b.matrix[0][0] = 5;
  ck_assert_int_eq(2, s21_sum_matrix(&b, &a, &res));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sum_matrix6) {
  matrix_t a, b, res;
  s21_create_matrix(2, 1, &a);
  s21_create_matrix(2, 1, &b);
  a.matrix[0][0] = 0;
  a.matrix[1][0] = 1.45;
  b.matrix[0][0] = 5;
  b.matrix[1][0] = 1.45;
  ck_assert_int_eq(0, s21_sum_matrix(&b, &a, &res));
  ck_assert_float_eq_tol(5, res.matrix[0][0], 1e-7);
  ck_assert_float_eq_tol(2.9, res.matrix[1][0], 1e-7);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sum_matrix7) {
  ck_assert_int_eq(1, s21_sum_matrix(NULL, NULL, NULL));
}
END_TEST

Suite *test_sum_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_sum_matrix=-\033[0m");
  TCase *tc = tcase_create("sum_matrixtc");

  tcase_add_test(tc, sum_matrix1);
  tcase_add_test(tc, sum_matrix2);
  tcase_add_test(tc, sum_matrix3);
  tcase_add_test(tc, sum_matrix4);
  tcase_add_test(tc, sum_matrix5);
  tcase_add_test(tc, sum_matrix6);
  tcase_add_test(tc, sum_matrix7);

  suite_add_tcase(s, tc);
  return s;
}
