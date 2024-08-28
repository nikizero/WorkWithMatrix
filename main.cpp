#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_Y 4
#define SIZE_X 4

// Функция для вывода массива
static void PrintArray(int array_a[SIZE_Y][SIZE_X])
{
    printf("Массив:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", array_a[i][j]);
        }
        printf("\n");
    }
}

// Функция для транспонирования массива
static void TransposeArray(int array_a[SIZE_Y][SIZE_X], int res[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            res[j][i] = array_a[i][j];
        }
    }
}

static void FillArray(int array_a[SIZE_Y][SIZE_X])
{
// Заполнение массива случайными числами
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            array_a[i][j] = rand() % 100; // Генерация случайного числа от 0 до 99
        }
    }
}

static void SumOfMatrix(int array_a[SIZE_Y][SIZE_X], int array_b[SIZE][SIZE], int array_res[SIZE][SIZE])
{
    for (int i = 0; i < SIZE_Y; i++)
    {
        for (int j = 0; j < SIZE_X; j++)
        {
            transposed[j][i] = array_a[i][j];
        }
    }
}

int main()
{
    int array_a[SIZE_Y][SIZE_X];
    int array_b[a][SIZE_X];
    int res[SIZE][SIZE];

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    FillArray(array_a);

    printf("\nИсходный массив:\n");
    PrintArray(array_a);

    TransposeArray(array_a, transposed);

    printf("\nТранспонированный массив:\n");
    PrintArray(transposed);

    return 0;
}
