#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main()
{
    int n, data[NMAX];
    if (input(data, &n) == 0){
	squaring(data, n);
        output(data, n);
    } else{
	printf("n/a");
    }
    return 0;
}

int input(int *a, int *n)
{
    char c;
    if (scanf("%i%c", n, &c)!=2 || c != '\n'){
	return 1;
    } 
    
    for(int *p = a; p - a < *n; p++)
    {
        if(scanf("%i", p) != 1){
	    return 1;
        }
    }
    return 0;
}

void output(int *a, int n)
{
    for (int i = 0; i < n; i++){
	printf("%i", a[i]);
        if (i < n - 1){
	    printf(" ");
	}
    }
}

void squaring(int *a, int n)
{
    for (int i = 0; i < n; i++){
	a[i] *= a[i];
    }
}


