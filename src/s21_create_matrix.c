#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int code_err = INCCORECT_MATRIX;
  result->rows = -1;
  result->columns = -1;
  result->matrix = NULL;

  if (rows > 0 && columns > 0 && result != NULL) {
    result->columns = columns;
    result->rows = rows;

    result->matrix = malloc(sizeof(double *) * rows);
    code_err = FAIL_CALC;
    int flag = 0;

    if (result->matrix) {
      for (int i = 0; i < rows; ++i) {
        result->matrix[i] = malloc(sizeof(double) * columns);
        if (!result->matrix[i]) {
          flag = 1;
          break;
        }
      }
      if (!flag) {
        code_err = OK;
      }
    }
  }

  return code_err;
}