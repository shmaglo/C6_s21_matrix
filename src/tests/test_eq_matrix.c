#include "test_me.h"

START_TEST(eq_matrix1) {
  matrix_t a, b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 0;
  b.matrix[0][0] = 0;
  ck_assert_int_eq(1, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix2) {
  matrix_t a, b;
  s21_create_matrix(1, 2, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 0;
  a.matrix[0][1] = 0;
  b.matrix[0][0] = 0;
  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix3) {
  matrix_t a, b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 0;
  b.matrix[0][0] = 5;
  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix4) {
  matrix_t a, b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = -43;
  b.matrix[0][0] = 555;
  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix5) {
  matrix_t a, b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  a.matrix[0][0] = 0;
  a.matrix[0][1] = 1;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 4;

  b.matrix[0][0] = 0;
  b.matrix[0][1] = 1;
  b.matrix[1][0] = 4;
  b.matrix[1][1] = 4;
  ck_assert_int_eq(1, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix6) {
  matrix_t a, b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  a.matrix[0][0] = 0;
  a.matrix[0][1] = 1;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 43;

  b.matrix[0][0] = 0;
  b.matrix[0][1] = 1;
  b.matrix[1][0] = 4;
  b.matrix[1][1] = 4;
  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix7) {
  matrix_t a, b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  a.matrix[0][0] = 0;
  a.matrix[0][1] = 11;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 4;

  b.matrix[0][0] = 44;
  b.matrix[0][1] = 1;
  b.matrix[1][0] = 4;
  b.matrix[1][1] = 42;
  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix8) {
  matrix_t a, b;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(2, 2, &b);
  a.matrix[0][0] = 0;
  a.matrix[0][1] = 1;
  a.matrix[0][2] = 123;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 4;

  b.matrix[0][0] = 0;
  b.matrix[0][1] = 1;
  b.matrix[1][0] = 4;
  b.matrix[1][1] = 4;
  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix9) {
  matrix_t a, b;
  s21_create_matrix(0, 0, &a);
  s21_create_matrix(0, 0, &b);

  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix10) {
  matrix_t a, b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 1.56894557;
  b.matrix[0][0] = 1.56894557;
  ck_assert_int_eq(1, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix11) {
  matrix_t a, b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 1.56894557;
  b.matrix[0][0] = 1.56894558;
  ck_assert_int_eq(1, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix12) {
  matrix_t a, b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 4.56894557;
  b.matrix[0][0] = 1.56894557;
  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix13) {
  matrix_t a, b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  a.matrix[0][0] = 1.56894557;
  b.matrix[0][0] = 1.56894558;
  ck_assert_int_eq(1, s21_eq_matrix(&b, &a));
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(eq_matrix14) { ck_assert_int_eq(0, s21_eq_matrix(NULL, NULL)); }
END_TEST

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_eq_matrix=-\033[0m");
  TCase *tc = tcase_create("eq_matrixtc");

  tcase_add_test(tc, eq_matrix1);
  tcase_add_test(tc, eq_matrix2);
  tcase_add_test(tc, eq_matrix3);
  tcase_add_test(tc, eq_matrix4);
  tcase_add_test(tc, eq_matrix5);
  tcase_add_test(tc, eq_matrix6);
  tcase_add_test(tc, eq_matrix7);
  tcase_add_test(tc, eq_matrix8);
  tcase_add_test(tc, eq_matrix9);
  tcase_add_test(tc, eq_matrix10);
  tcase_add_test(tc, eq_matrix11);
  tcase_add_test(tc, eq_matrix12);
  tcase_add_test(tc, eq_matrix13);
  tcase_add_test(tc, eq_matrix14);
  suite_add_tcase(s, tc);
  return s;
}
