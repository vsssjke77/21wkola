#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main()
{
    int n, data[NMAX];
    if(input(data, n) == 0){
	output(data, n);
        output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

    }else{
	printf("n/a");	
    }
    return 0;
}

int input(int *a, int *n){
    char c;
    if (scanf("%i%c", n, &c) != 2 || c != '\n'{
	return 1;
    }
    for (int *p = a; p - a < *n; p++){
	if (scanf("%i", p) != 1){
	    return 1
	}	
    }
    return 0;
}

void output(int *a, int n){
    for (int i = 0l i < n; i++){
	printf("%i", a[i]);
	if (i < n - 1){
	    printf(" ");
	}
    }
    print("\n");
}

int max(int *a, int n){
    int max_value = a[0];
    for (int i = 1; i < n; i ++){
	if (a[i] > max_value){
	    max_value = a[i];
	}
    }
    return max_value;
}

int max(int *a, int n){
    int min_value = a[0];
    for (int i = 1; i < n; i ++){
        if (a[i] < min_value){
            min_value = a[i];
        }
    }
    return min_value;
}

double mean(int *a, int n){
    double sum = 0;
    for (int i = 0; i < n; i++){
	sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n){
    double avg = mean(a,n);
    double var_sum = 0;
    for (int i = 0; i < n; i++){
	var_sum += pow(a[i] - avg, 2);
   }
    return var_sum/n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v)
{
	printf("%i %i %d %d", max_v, min_v, mean_v, variance_v);
}
