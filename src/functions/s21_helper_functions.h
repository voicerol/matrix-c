#ifndef S21_HELPER_FUNCTIONS
#define S21_HELPER_FUNCTIONS

#include "../s21_matrix.h"

/**
 * @brief Функция проверяет указатели на матрицы и указатели на расположение
 * самих матриц в памяти
 * @param matrix_amount
 * @param A указатель на первую матрицу
 * @param ... указатели на другие матрицы
 * @return КОД ОШИБКИ :
 * 0 - все матрицы были успешно проверены
 * 1 - произошла ошибка.
 */
int s21_validate_matrix(int matrix_amount, matrix_t *A, ...);

/**
 * @brief Функция проверяет, имеют ли все переданные матрицы одинаковые размеры
 * @param matrix_amount
 * @param A указатель на первую матрицу
 * @param ... указатели на другие матрицы
 * @return ПРОВЕРКА СТАТУСА :
 * 0 - матрицы не совпадают по размеру
 * 1 - все матрицы одинаковы по размеру
 */
int s21_is_matrix_same_size(int matrix_amount, matrix_t *A, ...);

/**
 * @brief Подсчет умножения двух матриц с помощью формулы. Данная функция не
 * проверяет указатели на матрицы.
 * @param i сдвиг на i элементов
 * @param j сдвиг на j элементов
 * @param A указатель на первую матрицу
 * @param B указатель на вторую матрицу
 * @return результат в double
 */
double s21_mult_matrix_res(int i, int j, matrix_t *A, matrix_t *B);

/**
 * @brief Создает вспомогательную матрицу для элемента A[i][j]. Будьте осторожны
 * с этой функцией. Она может возвращать значение NULL!
 * @param excluded_row номер исключенной строки
 * @param excluded_column номер исключенного столбца
 * @param A указатель на исходную матрицу
 * @return Указатель на результирующую второстепенную матрицу
 */
matrix_t *s21_create_minor(int excluded_row, int excluded_column, matrix_t *A);

/**
 * @brief The function checks the matrix for squareness
 * @param A pointer to the input matrix
 * @return 1 - SUCCESS; 0 - ERROR
 */
int s21_is_matrix_square(matrix_t *A);

/**
 * @brief Функция инициализирует всю матрицу значениями
 * начиная с заданного значения и каждый раз увеличивая его на шаг итерации
 * @param A Указатель на матрицу, которая должна быть инициализирована
 * @param start_value - первое значение для инициализации
 * @param iteration_step шаг итерации
 */
void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step);

/**
 * @brief Функция выводит всю матрицу целиком на консоль
 * @param A Указатель на матрицу
 */
void s21_print_matrix(matrix_t *A);

#endif  // S21_HELPER_FUNCTIONS
