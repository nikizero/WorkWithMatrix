#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_Y 5
#define SIZE_X 4

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
        return 0;
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
    return 1;
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
            res[j][i] = array_a[j][i] + array_b[j][i];
        }
    }
}

int main()
{
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

    printf("\nСумма массивов:\n");              //!!!!!!
    PrintArray(res);

    return 0;
}
