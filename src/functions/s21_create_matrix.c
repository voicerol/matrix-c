#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || result == NULL) {
    return INCORRECT_MATRIX;
  }

  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)malloc(rows * sizeof(double *));
  if (result->matrix == NULL) {
    return CALCULATION_ERROR;
  }

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)malloc(columns * sizeof(double));
    //      if (result->matrix[i] == NULL) {
    //     for (int j = 0; j < i; j++) {
    //         free(result->matrix[j]);
    //     }
    //     free(result->matrix);
    //     result->matrix = NULL;
    //     result->rows = 0;
    //     result->columns = 0;
    //     return CALCULATION_ERROR;
    // }
    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = 0.0;
    }
  }

  return OK;
}
