#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int code_err = INCCORECT_MATRIX;
  if (A && result) {
    code_err = FAIL_CALC;
    *result = 0;
    if (_check_sqr_matr(A)) {
      if (A->columns == 1) {
        code_err = OK;
        *result = A->matrix[0][0];
      } else {
        matrix_t new_matrix;
        code_err = s21_create_matrix(A->columns - 1, A->rows - 1, &new_matrix);
        if (code_err == OK) {
          int k = 1;
          for (int i = 0; i < A->columns; ++i) {
            for (int k = 1; k < A->rows; ++k) {
              for (int j = 0; j < A->columns; ++j) {
                if (j < i) {
                  new_matrix.matrix[k - 1][j] = A->matrix[k][j];
                } else if (j > i) {
                  new_matrix.matrix[k - 1][j - 1] = A->matrix[k][j];
                }
              }
            }
            double buf = 0;
            s21_determinant(&new_matrix, &buf);
            *result += buf * A->matrix[0][i] * k;
            k *= -1;
          }
        }
        s21_remove_matrix(&new_matrix);
      }
    }
  }

  return code_err;
}