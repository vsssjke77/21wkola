#include <stdio.h>
#include <stdlib.h>

int main() {
    int flag = 1;
    char filename[256] = ""; // Хранение пути к файлу
    FILE *fp = NULL;

    while (flag == 1) {
        int choose;
        char c;

        printf("Enter your choice (1: Read file, 2: Write to file, -1: Exit): ");
        if (scanf("%i%c", &choose, &c) != 2 || c != '\n') {
            printf("n/a\n");
            while ((c = getchar()) != '\n' && c != EOF); // Очистка буфера
        } else {
            switch (choose) {
                case 1: // Открытие и чтение файла
                    printf("Enter file path: ");
                    scanf("%255s", filename);  // Считывание пути к файлу
                    fp = fopen(filename, "r");
                    if (fp) {
                        char buffer[256];
                        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                            printf("%s", buffer);
                        }
                        fclose(fp);
                        fp = NULL;
                        printf("\n");
                    } else {
                        printf("n/a\n");
                    }
                    break;

                case 2: // Запись в файл
                    if (filename[0] == '\0') { // Проверка, загружен ли файл
                        printf("n/a\n");
                        break;
                    }

                    fp = fopen(filename, "a"); // Открытие файла для добавлени
                    if (fp) {
                        char buffer2[256];
                        printf("Enter text to append: ");
                        scanf(" %[^\n]s", buffer2); // Чтение строки с пробелами
                        fputs(buffer2, fp);
                        fputs("\n", fp); // Добавляем перенос строки
                        fclose(fp);
                        fp = NULL;
                    } else {
                        printf("n/a\n");
                    }
                    break;

                case -1: // Выход
                    flag = 0;
                    break;

                default: // Некорректный ввод
                    printf("n/a\n");
                    break;
            }
        }
    }

    return 0;
}

