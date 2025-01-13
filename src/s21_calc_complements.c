#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code_err = INCCORECT_MATRIX;
  if (A && A->rows > 0 && A->columns > 0) {
    code_err = FAIL_CALC;
    if (A->columns == A->rows) {
      code_err = s21_create_matrix(A->rows, A->columns, result);
      if (code_err == OK && A->columns == 1) {
        code_err = OK;
        result->matrix[0][0] = A->matrix[0][0];
      } else if (code_err == OK) {
        matrix_t new_matrix;
        code_err = s21_create_matrix(A->rows - 1, A->columns - 1, &new_matrix);
        // printf("qwer\n");

        if (code_err == OK) {
          for (int i = 0; i < A->rows; ++i) {
            for (int j = 0; j < A->columns; ++j) {
              _matr_cross(A, i + 1, j + 1, &new_matrix);

              double det = 0;
              s21_determinant(&new_matrix, &det);
              int k1 = 1;
              if ((i + j) % 2 == 1) {
                k1 = -1;
              }
              result->matrix[i][j] = k1 * det;
            }
          }
        }
        s21_remove_matrix(&new_matrix);
      }
    }
  }
  return code_err;
}