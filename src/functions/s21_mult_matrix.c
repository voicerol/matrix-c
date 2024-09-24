#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_validate_matrix(2, A, B) || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }

  int error_code = OK;
  error_code = s21_create_matrix(A->rows, B->columns, result);
  if (error_code == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = 0.0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
        if (!isfinite(result->matrix[i][j])) {
          error_code = CALCULATION_ERROR;
          break;
        }
      }
    }
  }

  if (error_code != OK) {
    s21_remove_matrix(result);
  }

  return error_code;
}
