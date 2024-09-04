#include <stdio.h>

#define LEN 100

void remove_leading_zeros(int *buff, int *len);
void input(int *buff, int *len);
void output(int *buff, int len);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int buff1[LEN], buff2[LEN], result[LEN + 1];
    int len1 = 0, len2 = 0, result_length = 0;

    // Ввод данных
    input(buff1, &len1);
    if (len1 == -1) {
        printf("n/a");
        return 0;
    }
    input(buff2, &len2);
    if (len2 == -1) {
        printf("n/a");
        return 0;
    }
    
    remove_leading_zeros(buff1, &len1);
    remove_leading_zeros(buff2, &len2); 
	


    // Сложение
    sum(buff1, len1, buff2, len2, result, &result_length);
    output(result, result_length);
	printf("\n");
    // Вычитание
    sub(buff1, len1, buff2, len2, result, &result_length);
    if (result_length == -1) {
        printf("n/a");
    } else {
        output(result, result_length);
    }

    return 0;
}

void input(int *buff, int *len) {
    int n = 0;
    char c;

    while (1) {
        if (scanf("%d%c", &buff[n], &c) != 2 || buff[n] < 0 || buff[n] > 9 || (c != ' ' && c != '\n')) {
            *len = -1;
            return;
        }
	n++;    
	if (c == '\n'){
            break;
	}
	
    }
    *len = n;
}

void output(int *buff, int len) {
    int leading_zero = 1;
    for (int i = 0; i < len; i++) {
        if (buff[i] != 0 || !leading_zero) {
        	printf("%d", buff[i]);
            leading_zero = 0;
		if (i < len - 1){
			printf(" ");
		}
        }
    }
    if (leading_zero) {
        printf("0");
    }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int carry = 0;
    int i = len1 - 1, j = len2 - 1;
    int k = (len1 > len2 ? len1 : len2);

    *result_length = k + 1; // Устанавливаем длину результата
    result[k] = 0; // Инициализируем последний элемент как 0, он может быть заменен на carry позже

    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) sum += buff1[i--];
        if (j >= 0) sum += buff2[j--];
        result[k--] = sum % 10;
        carry = sum / 10;

    }

    if (carry > 0) {
        result[0] = carry;  // Добавляем перенос в старший разряд
    } else {
        // Смещаем элементы влево, если перенос не привел к увеличению разряда
        for (int m = 0; m < *result_length - 1; m++) {
            result[m] = result[m + 1];
        }
        (*result_length)--;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int borrow = 0;
    int i = len1 - 1, j = len2 - 1, k = len1 - 1;

    // Проверка, что уменьшаемое >= вычитаемого
    if (len1 < len2 ) {
        *result_length = -1;
        return;
    }
    if (len1 == len2){
	for (int i = 0; i < len1; i++){
		if (buff1[i] > buff2[i]){
			break;
		}
		else if (buff1[i] < buff2[i]){
			*result_length = -1;
			return;

		}

	}

    }

    while (i >= 0 || j >= 0) {
        int diff = buff1[i] - (j >= 0 ? buff2[j] : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[k--] = diff;
        i--;
        j--;
    }

    // Удаление ведущих нулей
    k = 0;
    while (k < len1 - 1 && result[k] == 0) {
        k++;
    }

    *result_length = len1 - k;
    for (int m = 0; m < *result_length; m++) {
        result[m] = result[m + k];
    }

    // Если после вычитания все цифры нули, результат - 0
    if (*result_length == 0) {
        result[0] = 0;
        *result_length = 1;
    }
}

void remove_leading_zeros(int *buff, int *len) {
    
    if (buff[0] != 0) return;
    int i = 0;

    // Найти первый ненулевой элемент
    while (i < *len && buff[i] == 0) {
        i++;
    }

    // Если все элементы нули
    if (i == *len) {
        *len = 1;
        buff[0] = 0;
        return;
    }
	int length = *len;	
    // Смещение элементов влево
    for (int j = 0; j < i; j++) {
	    for ( int k = 0; k < length;k++){
		buff[k] = buff[k + 1];

	}
	length;
    }
	*len -= i;
}
