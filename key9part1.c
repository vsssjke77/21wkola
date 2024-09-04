/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <math.h>
#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int buffer[NMAX];
    int length;

    input(buffer, &length);

    if (length == -1) {
        printf("n/a");
        return 0;
    }
    int sum = sum_numbers(buffer, length);

    if (sum == 0) {
        printf("n/a");
        return 0;
    }

    int numbers[NMAX];
    int new_length = find_numbers(buffer, length, sum, numbers);

    if (new_length == 0) {
        printf("n/a2");
        return 0;
    } else {
        printf("%d\n", sum);
        output(numbers, new_length);
    }

    return 0;
}

void input(int *buffer, int *length) {
    char c;
    int number;
    if (scanf("%d%c", length, &c) != 2 || *length < 1 || *length > NMAX || c != '\n') {
        *length = -1;
        return;
    }

    for (int i = 0; i < *length; i++) {
        if (scanf("%d%c", &buffer[i], &c) != 2 || (i < *length - 1 && c != ' ' && c != '\n') ||
            (i == *length - 1 && c != '\n')) {
            *length = -1;
            return;
        }
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i < length - 1) {
            printf(" ");
        }
    }
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    int len_buffer = 0;

    for (int i = 1; i < length; i += 2) {
        sum += fabs(buffer[i]);
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (number != 0 && buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count] = buffer[i];
            count++;
        }
    }

    return count;
}
