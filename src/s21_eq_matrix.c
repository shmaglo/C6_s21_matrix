#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code_err = FAILURE;

  if (A && B && A->matrix && B->matrix) {
    if (A->columns != B->columns || A->rows != B->rows) {
      code_err = FAILURE;
    } else {
      code_err = SUCCESS;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7)
            code_err = FAILURE;
        }
      }
    }
  }
  return code_err;
}