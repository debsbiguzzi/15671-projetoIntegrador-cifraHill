# include <stdio.h>
# include <locale.h>

# define MAX 10

void multDiv(int A[MAX][MAX], int M[MAX][MAX], int C[MAX][MAX], int linA, int colA, int linM, int colM)
{
    for (int i = 0; i < linA; i++) 
    {
        for (int j = 0; j < colM; j++) 
        {
            C[i][j] = 0;
            
            for (int k = 0; k < colA; k++) 
            {
                C[i][j] += A[i][k] * M[k][j];  
            }
            C[i][j] = C[i][j] % 26;
        }
    }    
}

void printMatrix(int matrix[MAX][MAX], int lin, int col)
{
    for (int i = 0; i < lin; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int A[MAX][MAX] = 
    {
        {5, 6}, 
        {2, 3}
    };

    int M[MAX][MAX] = 
    {
        {2, 1, 15, 20},
        {15, 14, 9, 5}
    };

    int C[MAX][MAX];
    int linA = 2, linM = 2, colA = 2, colM = 4;

    multDiv(A, M, C, linA, colA, linM, colM);

    printf("A Matriz que deseja ser criptografada é M = {2, 15, 1, 14}{15, 9, 20, 5} que no alfabeto significa BOA NOITE. \n");
    printf("A matriz M criptografada será: %i \n");
    printMatrix(C, linA, colM);

    return 0;
}
