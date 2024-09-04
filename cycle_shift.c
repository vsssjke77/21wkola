#include <stdio.h>

#define NMAX 10

int input(int *n, int *c, int *array);
void output(int *array, int n);
void cycle_shift(int *array, int n, int c);

int main() {
    int n, c, array[NMAX];

    if (input(&n, &c, array) == 1) {
        printf("n/a");
        return 0;
    }

    cycle_shift(array, n, c);

    output(array, n);

    return 0;
}

int input(int *n, int *c, int *array) {
    char end_check;

    if (scanf("%d", n) != 1 || *n < 1 || *n > NMAX) {
        return 1;
    }

    for (int i = 0; i < *n; i++) {
        if (scanf("%d%c", &array[i], &end_check) != 2 || (end_check != ' ' && end_check != '\n')) {
            return 1;
        }
    }

    if (scanf("%d%c", c, &end_check) != 2 || end_check != '\n') {
        return 1;
    }

    return 0;
}

void output(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}

void cycle_shift(int *array, int n, int c) {
    int temp[NMAX];

    // Приведение c в диапазон [0, n)
    c = (c % n + n) % n;

    // Сдвиг массива
    for (int i = 0; i < n; i++) {
        temp[i] = array[(i + c) % n];
    }

    // Копирование временного массива обратно в исходный
    for (int i = 0; i < n; i++) {
        array[i] = temp[i];
    }
}
