#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void   Print_matrix(int** node_s, int size);
static int    random_number();
static int ** Create(int size);
static void   FillMatrix(int** node_s, int size);
static void   Transpose(int** node_s, int size);

// Функция для генерации случайного числа в диапазоне от 0 до 9
static int random_number() {
    return rand() % 10;
}

int main()
{
    srand(time(NULL));
    int size = 0;

    printf("Введите размер квадратной матрицы: ");
    scanf("%d", &size);

    int ** node_a = Create(size);

    printf("Исходная матрица:\n");
    Print_matrix(node_a, size);

    Transpose(node_a, size);

    printf("Транспонированная матрица:\n");
    Print_matrix(node_a, size);

    // Освобождение памяти
    for (int i = 0; i < size; i++) {
        free(*(node_a + i));
    }
    free(node_a);

    return 0;
}

static int ** Create(int size)
{
    int ** node_s = (int **) calloc(size, sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        *(node_s + i) = (int*) calloc(size, sizeof(int));
    }
    FillMatrix(node_s, size);
    return node_s;
}

static void FillMatrix(int** node_s, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            *(*(node_s + i) + j) = random_number();
        }
    }
}

static void Print_matrix(int** node_s, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", *(*(node_s + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

static void Transpose(int** node_s, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int temp = *(*(node_s + i) + j);
            *(*(node_s + i) + j) = *(*(node_s + j) + i);
            *(*(node_s + j) + i) = temp;
        }
    }
}