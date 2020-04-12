#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"
#include "exercise3_p0.h"

/*----------------------------- Functions Exercise 3 -------------------------*/

/**
* Ex. 3.1
*
* Initializes the values of a given matrix with random integers.
*
* @param matrix The matrix to be initialized with random integers between MIN_RAND_EX3 and MAX_RAND_EX3.
*
*/
void init_matrix_values(Matrix matrix) {

// Implement this function

}

/**
* Ex. 3.2.1
*
* Returns the scalar product of an integer and a matrix.
*
* @param scalar Number to multiply.
* @param matrix A matrix initialized.
* @return A matrix obtained by the scalar product of the number and the matrix.
*
*/
Matrix scalar_prod(int scalar, Matrix matrix_a) {

// Implement this function

}

/**
* Ex. 3.2.2
*
* Returns sum of two matrices.
*
* @param matrix_a Matrix of shape R x C
* @param matrix_b Matrix of shape R x C
* @return A matrix of shape R x C obtained by the sum of the two matrices or a matrix with values=NULL if they are of incompatible shapes.
*
*/
Matrix matrix_sum(Matrix matrix_a, Matrix matrix_b) {

// Implement this function

}

/**
* Ex. 3.2.3
*
* Returns product of two matrices.
*
* @param matrix_a Matrix of shape Ra x Ca
* @param matrix_b Matrix of shape Rb x Cb
* @return A matrix of shape Ra x Cb obtained by the product of the two matrices or a matrix with values=NULL if they are of incompatible shapes.
*
*/
Matrix matrix_prod(Matrix matrix_a, Matrix matrix_b) {

// Implement this function

}

/**
*
* Assigns the number of rows and columns and allocates dynamic memory for a new matrix, which should be released when no longer used.
*
* @param num_rows Number of rows.
* @param num_cols Number of columns.
* @return A matrix of num_rows x num_cols.
*
*/
Matrix new_matrix(int num_rows, int num_cols) {

// Implement this function

}

/**
*
* Prints a matrix.
*
* @param matrix Matrix to print.
*
*/
void print_matrix(Matrix matrix) {

// Implement this function

}

/**
*
* Frees the memory used by a matrix.
*
* @param matrix Matrix to free.
*
*/
void free_matrix(Matrix matrix) {

// Implement this function

}

/**
*
* Checks if a matrix represents an error.
*
* @param matrix Matrix.
*
*/
bool is_error_matrix(Matrix matrix) {
    return (matrix.values == NULL);
}


/*-------------------------------- Execise 3 ----------------------------*/

void exercise_3() {

    printf("\n--- Exercise 3 ---\n");

    int rows_a = read_number("\n>> Enter the number of rows of matrix A (between %d and %d): ", MIN_ROWS_EX3, MAX_ROWS_EX3);
    int cols_a = read_number(">> Enter the number of columns of matrix A (between %d and %d): ", MIN_COLS_EX3, MAX_COLS_EX3);
    int rows_b = read_number(">> Enter the number of rows of matrix B (between %d and %d): ", MIN_ROWS_EX3, MAX_ROWS_EX3);
    int cols_b = read_number(">> Enter the number of columns of matrix B (between %d and %d): ", MIN_COLS_EX3, MAX_COLS_EX3);

    Matrix matrix_a = new_matrix(rows_a, cols_a);
    Matrix matrix_b = new_matrix(rows_b, cols_b);
    init_matrix_values(matrix_a);
    init_matrix_values(matrix_b);

    printf("Matrix A (%d x %d):\n", matrix_a.num_rows, matrix_a.num_cols);
    print_matrix(matrix_a);
    printf("\n");
    printf("Matrix B (%d x %d):\n", matrix_b.num_rows, matrix_b.num_cols);
    print_matrix(matrix_b);
    printf("\n");

    int scalar = read_number(">> Enter an integer between %d and %d: ", MIN_NUMBER_EX3, MAX_NUMBER_EX3);
    Matrix matrix_scalar_a = scalar_prod(scalar, matrix_a);
    printf("%d.A is:\n", scalar);
    print_matrix(matrix_scalar_a);
    printf("\n");
    free_matrix(matrix_scalar_a);

    Matrix matrix_aplusb = matrix_sum(matrix_a, matrix_b);
    if (is_error_matrix(matrix_aplusb)) {
        printf("It is not possible to sum a matrix of shape %dx%d with a matrix of shape %dx%d\n", matrix_a.num_rows, matrix_a.num_cols, matrix_b.num_rows, matrix_b.num_cols);
    } else {
        printf("Matrix A+B (%d x %d):\n", matrix_aplusb.num_rows, matrix_aplusb.num_cols);
        print_matrix(matrix_aplusb);
        printf("\n");
        free_matrix(matrix_aplusb);
    }

    Matrix matrix_axb = matrix_prod(matrix_a, matrix_b);
    if (is_error_matrix(matrix_axb)) {
        printf("It is not possible to multiple a matrix of shape %dx%d with a matrix of shape %dx%d\n", matrix_a.num_rows, matrix_a.num_cols, matrix_b.num_rows, matrix_b.num_cols);
    } else {
        printf("Matrix A.B (%d x %d):\n", matrix_a.num_rows, matrix_b.num_cols);
        print_matrix(matrix_axb);
        free_matrix(matrix_axb);
    }

    free_matrix(matrix_a);
    free_matrix(matrix_b);

}
