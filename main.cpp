#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для генерации случайного числа в диапазоне от 0 до 9
int random_number() {
    return rand() % 10;
}

// Функция для создания и заполнения матрицы случайными числами
int** create_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = random_number();
        }
    }
    return matrix;
}

// Функция для вывода матрицы
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция для сложения двух матриц
int** add_matrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Функция для транспонирования матрицы
int** transpose_matrix(int** matrix, int size) {
    int** transposed = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        transposed[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}

// Функция для освобождения памяти
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows, cols;

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Ввод размеров матриц
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    // Создание и заполнение матриц
    int** matrix1 = create_matrix(rows, cols);
    int** matrix2 = create_matrix(rows, cols);

    // Вывод матриц
    printf("Матрица 1:\n");
    print_matrix(matrix1, rows, cols);

    printf("Матрица 2:\n");
    print_matrix(matrix2, rows, cols);

    // Сложение матриц
    int** sum_matrix = add_matrices(matrix1, matrix2, rows, cols);
    printf("Результат сложения матриц:\n");
    print_matrix(sum_matrix, rows, cols);

    // Транспонирование, если матрица квадратная
    if (rows == cols) {
        int** transposed_matrix = transpose_matrix(matrix1, rows);
        printf("Транспонированная Матрица 1:\n");
        print_matrix(transposed_matrix, rows, cols);
        free_matrix(transposed_matrix, rows);
    } else {
        printf("Матрица не является квадратной, транспонирование невозможно.\n");
    }

    // Освобождение памяти
    free_matrix(matrix1, rows);
    free_matrix(matrix2, rows);
    free_matrix(sum_matrix, rows);

    return 0;
}