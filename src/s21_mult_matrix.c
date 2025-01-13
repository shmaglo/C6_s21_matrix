#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code_err = INCCORECT_MATRIX;
  if (result && A) {
    code_err = FAIL_CALC;
    if (A->columns == B->rows) {
      code_err = s21_create_matrix(A->rows, B->columns, result);
      if (code_err == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; k++)
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    }
  }

  return code_err;
}