#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *buff_matr) {
  int code_err = INCCORECT_MATRIX;
  if (A) {
    code_err = FAIL_CALC;
    double det = 0;
    s21_determinant(A, &det);
    if (det != 0 && A->columns == A->rows) {
      matrix_t new_matrix, new_matrix2;
      code_err = s21_calc_complements(A, &new_matrix);
      code_err = s21_transpose(&new_matrix, &new_matrix2);
      code_err = s21_mult_number(&new_matrix2, 1 / det, buff_matr);

      s21_remove_matrix(&new_matrix2);
      s21_remove_matrix(&new_matrix);
    }
  }

  return code_err;
}