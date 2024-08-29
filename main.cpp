#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
                                                                    
// Функция для вывода массива     

static void PrintArray(int array_a[SIZE_Y][SIZE_X])                                     
{
    printf("Массив:\n");
    for (int i = 0; i < SIZE_Y; i++)
    {
        for (int j = 0; j < SIZE_X; j++)
        {
            printf("%d ", array_a[i][j]);
        }
        printf("\n");
    }
}

// Функция для транспонирования массива
static int TransposeArray(int array_a[SIZE_Y][SIZE_X], int res[SIZE_Y][SIZE_X])
{
    if (SIZE_Y != SIZE_X)
    {
        printf ("\nImposible operation\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < SIZE_Y; i++)
        {
            for (int j = 0; j < SIZE_X; j++)
            {
                res[j][i] = array_a[i][j];
            }
        }
    }
    return 0;
}

static void FillArray(int array_a[SIZE_Y][SIZE_X])
{
// Заполнение массива случайными числами
    for (int i = 0; i < SIZE_Y; i++)
    {
        for (int j = 0; j < SIZE_X; j++)
        {
            array_a[i][j] = rand() % 100; // Генерация случайного числа от 0 до 99
        }
    }
}

static void SumOfMatrix(int array_a[SIZE_Y][SIZE_X], int array_b[SIZE_Y][SIZE_X], int res[SIZE_Y][SIZE_X])
{
    for (int i = 0; i < SIZE_Y; i++)
    {
        for (int j = 0; j < SIZE_X; j++)
        {
            res[i][j] = array_a[i][j] + array_b[i][j];
        }
    }
}

int main()
{
    int* size_xy = int* calloc(2, sizeof(int));
    
    int array_a[SIZE_Y][SIZE_X] = {};
    int array_b[SIZE_Y][SIZE_X] = {};
    int res[SIZE_Y][SIZE_X] = {};

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    FillArray(array_a);
    FillArray(array_b);
    FillArray(res);

    printf("\nИсходный массив a:\n");
    PrintArray(array_a);

    printf("\nИсходный массив b:\n");
    PrintArray(array_b);

    TransposeArray(array_a, res);

    printf("\nТранспонированный массив:\n");
    PrintArray(res);

    SumOfMatrix(array_a, array_b, res);

    printf("\nСумма массивов:\n");        
    PrintArray(res);

    return 0;
}
