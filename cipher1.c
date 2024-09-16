#include <stdio.h>

int main() {
  printf("Menu\n");
  int flag = 1;
  while (flag == 1) {
    int choose;
    printf("Choose number");
    char c;
    if (scanf("%i%c", &choose, &c) != 2 || c != '\n') {
      printf("n/a\n");
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    } else {
      switch (choose) {
      case 1:
        char filename[256];
        char buffer[256];
        scanf("%255s", filename);
        FILE *fp = fopen(filename, "r");
        if (fp) {
          while ((fgets(buffer, 256, fp)) != NULL) {
            printf("%s", buffer);
          }

          fclose(fp);
          printf("\n");
        } else {
          printf("n/a\n");
        }
        break;
      case -1:
        flag = 0;
        break;
      default:
        printf("n/a\n");
        break;
      }
    }
  }
  return 0;
}
