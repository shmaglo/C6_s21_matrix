#include "s21_matrix.h"

int _check_sqr_matr(matrix_t *A) {
  int res = FAILURE;
  if (A->rows == A->columns) {
    res = SUCCESS;
  } else {
    res = FAILURE;
  }
  return res;
}

int _matr_cross(matrix_t *A, int n, int m, matrix_t *res_matr) {
  int code_err = 0;
  if (n > A->rows || m > A->columns) {
    code_err = 1;
  }
  if (code_err == 0) {
    n--;
    m--;
    int a = -1, b = 0;
    for (int i = 0; i < A->rows; i++) {
      if (i != n) {
        a++;
      }
      b = 0;

      for (int j = 0; j < A->rows; j++) {
        if (i != n && j != m) {
          res_matr->matrix[a][b] = A->matrix[i][j];
          b++;
        }
      }
    }
  }
  return code_err;
}