#include <stdio.h>
#include <stdlib.h>

int **create_matrix(size_t m, size_t n)
{
    int **matrix = malloc(sizeof(int*) * m);

    if (!matrix)
    {
        return NULL;
    }

    for (int i = 0; i < m; ++i)
    {
        matrix[i] = malloc(sizeof(int) * n);
        if (!matrix[i])
        {
            for (int j = 0; j < i; ++i)
                free(matrix[j]);
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void print_matrix(int **matrix, size_t m, size_t n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%4d", matrix[i][j]);
        putchar('\n');
    }
}

void diag_matrix(int **matrix, size_t m, size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
        matrix[i][i] = 1;
    }
}

void up_triangle_matrix(int **matrix, size_t m, size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {

            if (j >= i)
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
        matrix[i][i] = 1;
    }
}

int diagonalSum(int** mat, int matSize, int* matColSize) {
    int diagonalSum = 0;

    for (int i = 0; i < matSize; i++)
    {
        diagonalSum += mat[i][i];
        diagonalSum += mat[i][matSize - 1 - i];
    }

    if (matSize % 2 != 0)
    {
        int c = matSize / 2;
        diagonalSum -= mat[c][c];
    }

    return diagonalSum;
}



int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) 
{
    (*returnColumnSizes) = malloc(sizeof(int) * matrixColSize[0]);
    *returnSize = matrixColSize[0];
    int **mat = create_matrix(matrixColSize[0], matrixSize);

    for (int i = 0; i < matrixSize; i++)
    {
        (*returnColumnSizes)[i] = matrixSize;
        for (int j = 0; j < matrixColSize[0]; j++)
        {
            mat[j][i] = matrix[i][j];
        }
    }
     return mat;
}

//https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=problem-list-v2&envId=matrix
int numSpecial(int** mat, int matSize, int* matColSize) {
    int num = 0;

    int *strin = malloc(sizeof(int) * matSize);
    int *col = malloc(sizeof(int) * matColSize[0]);

    for (int j = 0; j < matColSize[0]; ++j) {
        col[j] = 0;
    }

    for (int i = 0; i < matSize; ++i) {
        strin[i] = 0;
        for (int j = 0; j < matColSize[0]; ++j) {
            strin[i] += mat[i][j];
            col[j] += mat[i][j];
        }
    }

    for (int i = 0; i < matSize; ++i) {
        for (int j = 0; j < matColSize[0]; ++j) {
            if (mat[i][j] == 1 && strin[i] == 1 && col[j] == 1) {
                num++;
            }
        }
    }

    return num;
}

//https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/
bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    for (int k = 0; k < 4; ++k) {

        bool dec = true;

        int **matrx = malloc(sizeof(int*) * targetSize);

        for (int c = 0; c < matSize; ++c) {
            matrx[c] = malloc(sizeof(int) * targetColSize[0]);
        }

        for (int i = 0; i < matSize; ++i) {
            for (int j = 0; j < matColSize[0]; ++j)
            {
                matrx[i][j] = mat[j][matSize - i - 1];
                if (matrx[i][j] != target[i][j])
                {
                    dec = false;
                }
            }
        }
        if (dec)
        {
            return true;
        }
        mat = matrx;     
    }
    return false;
}

int* spiral(int *size, int *colsize)
{
    int count = 0;
    int k = 0;

    int **mat = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; ++i)
    {
        mat[i] = malloc(sizeof(int) * colsize);
        for (int j = 0; j < colsize; ++j)
        {
            mat[i][j] = 0;
        }
    }
    while (count != colsize * size)
    {
        if (k % 4 == 0)
        {
            while (mat[i][j] == 0)
            {
                mat[i][j] = count;
                j++;
            }
            count++;
        }
        else if (k % 4 == 1)
        {
            while (mat[i][j] == 0)
            {
                mat[i][j] = count;
                i++;
            }
            count++;
        }
        else if (k % 4 == 2)
        {
            while (mat[i][j] == 0)
            {
                mat[i][j] = count;
                j--;
            }
            count++;
        }
        else if (k % 4 == 3)
        {
            while (mat[i][j] == 0)
            {
                mat[i][j] = count;
                i--;
            }
            count++;
        }
        k++;
    }
}

//  0  1  2  3  4
// 13 14 15 16  5
// 12 19 18 17  6
// 11 10  9  8  7