#include "test_me.h"

START_TEST(create_matrix1) {
  matrix_t test;
  int res = s21_create_matrix(1, 1, &test);
  ck_assert_int_eq(res, 0);
  ck_assert_ptr_nonnull(test.matrix);
  ck_assert_ptr_nonnull(test.matrix[0]);
  ck_assert_int_eq(test.columns, 1);
  ck_assert_int_eq(test.rows, 1);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(create_matrix2) {
  matrix_t test;
  int res = s21_create_matrix(2, 2, &test);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(test.columns, 2);
  ck_assert_int_eq(test.rows, 2);
  ck_assert_ptr_nonnull(test.matrix);
  for (int i = 0; i < 2; ++i) {
    ck_assert_ptr_nonnull(test.matrix[i]);
  }
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(create_matrix3) {
  matrix_t test;
  int res = s21_create_matrix(5, 3, &test);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(test.columns, 3);
  ck_assert_int_eq(test.rows, 5);
  ck_assert_ptr_nonnull(test.matrix);
  for (int i = 0; i < 5; ++i) {
    ck_assert_ptr_nonnull(test.matrix[i]);
  }
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(create_matrix4) {
  matrix_t test;
  int res = s21_create_matrix(0, 0, &test);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(create_matrix5) {
  matrix_t test;
  int res = s21_create_matrix(-8, 8, &test);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(create_matrix6) {
  matrix_t test;
  int res = s21_create_matrix(0, 8, &test);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(create_matrix7) {
  matrix_t test;
  int res = s21_create_matrix(8, 0, &test);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(remove_matrix1) {
  matrix_t test;
  test.matrix = NULL;
  test.rows = 0;
  test.columns = 0;
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(remove_matrix2) { s21_remove_matrix(NULL); }
END_TEST

START_TEST(remove_matrix3) {
  matrix_t test;
  test.rows = 0;
  test.columns = 0;
  test.matrix = NULL;
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(remove_matrix4) {
  matrix_t test;
  test.rows = 0;
  test.columns = 1;
  test.matrix = NULL;
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(remove_matrix5) {
  matrix_t test;
  test.rows = 1;
  test.columns = 0;
  test.matrix = NULL;
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(remove_matrix6) {
  matrix_t test;
  test.rows = 1;
  test.columns = 1;
  test.matrix = NULL;
  s21_remove_matrix(&test);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_create_matrix=-\033[0m");
  TCase *tc = tcase_create("create_matrixtc");

  tcase_add_test(tc, create_matrix1);
  tcase_add_test(tc, create_matrix2);
  tcase_add_test(tc, create_matrix3);
  tcase_add_test(tc, create_matrix4);
  tcase_add_test(tc, create_matrix5);
  tcase_add_test(tc, create_matrix6);
  tcase_add_test(tc, create_matrix7);
  tcase_add_test(tc, remove_matrix1);
  tcase_add_test(tc, remove_matrix2);
  tcase_add_test(tc, remove_matrix3);
  tcase_add_test(tc, remove_matrix4);
  tcase_add_test(tc, remove_matrix5);
  tcase_add_test(tc, remove_matrix6);
  suite_add_tcase(s, tc);
  return s;
}
