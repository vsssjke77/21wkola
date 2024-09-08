#include <stdio.h>

#define STR 25
#define COL 80

void input_matrix(int matr[STR][COL]);
void update_matrix(int matr1[STR][COL], int matr2[STR][COL]);
int count_neighbors(int matr[STR][COL], int i, int j);
int decision(int neighbors, int condition);
void replace(int matr2[STR][COL], int matr1[STR][COL]);
int check(int matr1[STR][COL], int matr2[STR][COL]);
int change_speed(char control_button, int *flag, int time_mili_sec);
int count(int matr[STR][COL]);
void clear_screen();
void delay(int milliseconds);

int main() {
    int matr1[STR][COL];
    int matr2[STR][COL];
    int time_mili_sec = 500;
    int stop = 0;

    input_matrix(matr1);
	
    while (stop != 1) {
        char control_button = getchar();

        if (count(matr1) == 0) {
            stop = 1;
        }

        time_mili_sec = change_speed(control_button, &stop, time_mili_sec);

        delay(time_mili_sec); // Задержка
        clear_screen();
        update_matrix(matr1, matr2);

        if (check(matr1, matr2) == 2000) {
            stop = 1;
        }

        replace(matr2, matr1);
    }

    return 0;
}

void input_matrix(int matr[STR][COL]) {
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++) {
            scanf("%d", &matr[i][j]);
        }
    }
}

void update_matrix(int matr1[STR][COL], int matr2[STR][COL]) {
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++) {
            matr2[i][j] = decision(count_neighbors(matr1, i, j), matr1[i][j]);
            if (matr2[i][j] == 1) {
                printf("0");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int matr[STR][COL], int i, int j) {
    int sum = 0;

    int i_minus = i - 1, i_plus = i + 1, j_minus = j - 1, j_plus = j + 1;
    if (i_minus < 0) { i_minus = STR - 1; }
    if (j_minus < 0) { j_minus = COL - 1; }
    if (i_plus > STR - 1) { i_plus = 0; }
    if (j_plus > COL - 1) { j_plus = 0; }

    sum += matr[i_minus][j_minus];
    sum += matr[i_minus][j];
    sum += matr[i_minus][j_plus];
    sum += matr[i][j_minus];
    sum += matr[i][j_plus];
    sum += matr[i_plus][j_minus];
    sum += matr[i_plus][j];
    sum += matr[i_plus][j_plus];

    return sum;
}

int decision(int neighbors, int condition) {
    if ((neighbors == 2 || neighbors == 3) && condition == 1) {
        return 1;
    } else if (neighbors == 3 && condition == 0) {
        return 1;
    }
    return 0;
}

void replace(int matr2[STR][COL], int matr1[STR][COL]) {
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++) {
            matr1[i][j] = matr2[i][j];
        }
    }
}

int check(int matr1[STR][COL], int matr2[STR][COL]) {
    int same = 0;
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++) {
            if (matr1[i][j] == matr2[i][j]) same++;
        }
    }
    return same;
}

int change_speed(char control_button, int *flag, int time_mili_sec) {
    if (control_button == '1') {
        time_mili_sec = 900;
    } else if (control_button == '2') {
        time_mili_sec = 400;
    } else if (control_button == '3') {
        time_mili_sec = 70;
    } else if (control_button == 'q') {
        *flag = 1;
    }
    return time_mili_sec;
}

int count(int matr[STR][COL]) {
    int sum = 0;
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++) {
            sum += matr[i][j];
        }
    }
    return sum;
}

void clear_screen() {
    // Просто напечатаем 100 новых строк, чтобы "очистить" экран
    for (int i = 0; i < 100; i++) {
        printf("\n");
    }
}

void delay(int milliseconds) {
    // Простой цикл ожидания
    volatile int i;
    for (i = 0; i < milliseconds * 100000; i++) {
        // Ничего не делаем, просто ждём
    }
}

