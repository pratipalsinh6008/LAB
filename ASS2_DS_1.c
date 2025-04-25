/*Write a C program to multiply two matrices using dynamic memory allocation. Each two-dimensional array should be processed as array of pointers
to a set of 1-dimensional integer arrays. Read, access and display the matrix elements using pointers instead of subscript notation. Use three
functions i) To read input matrix ii) To compute the product and iii) To display the resultant matrix.*/

#include <stdio.h>
#include <stdlib.h>

// Function to read a matrix
void readMatrix(int ***matrix, int rows, int cols)
{
    *matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        (*matrix)[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}

// Function to compute the product of two matrices
void multiplyMatrices(int **matrix1, int **matrix2, int ***result, int rows1, int cols1, int cols2)
{
    *result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++)
    {
        (*result)[i] = (int *)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++)
        {
            (*result)[i][j] = 0;
            for (int k = 0; k < cols1; k++)
            {
                (*result)[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", ((matrix + i) + j));
        }
        printf("\n");
    }
}

int main()
{
    int **matrix1, **matrix2, **result;
    int rows1, cols1, rows2, cols2;

    // Reading dimensions of the first matrix
    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d", &rows1, &cols1);

    // Reading the first matrix
    printf("Enter elements of the first matrix:\n");
    readMatrix(&matrix1, rows1, cols1);

    // Reading dimensions of the second matrix
    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d", &rows2, &cols2);

    if (cols1 != rows2)
    {
        printf("The matrices can't be multiplied with each other.\n");
        return 0;
    }

    // Reading the second matrix
    printf("Enter elements of the second matrix:\n");
    readMatrix(&matrix2, rows2, cols2);

    // Multiplying the matrices
    multiplyMatrices(matrix1, matrix2, &result, rows1, cols1, cols2);

    // Displaying the result
    printf("Resultant matrix:\n");
    displayMatrix(result, rows1, cols2);

    // Freeing dynamically allocated memory
    for (int i = 0; i < rows1; i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rows2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);

    for (int i = 0; i < rows1; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}