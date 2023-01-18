#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    int check1 = scanf("%d", &n);
    if ((int) check1 == 1) {
    if (n > 10 || n == 0 || n < 0) {
        printf("n/a");
        } else {
    if (input(data, n) == 0) {
    output(data, n);
    printf("\n");
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));
    } else {
        printf("n/a");
    }}} else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int n) {
    int check2;
for (int i = 0; i < n; i++) {
    check2 = scanf("%d", &a[i]);
    if ((int)check2 != 1) {
            return 10;
            break;
        }
        }
    if (getchar() != '\n') {
        return 10;
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", a[i], " ");
    }
}
int max(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
    }

int min(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < min) {
        min = a[i];
    }
}
return min;
}

double mean(int *a, int n) {
     double sum = 0;
    for (int i = 0; i < n; i++) {
    sum += a[i]*1.0/n;}
    return sum;
}

double variance(int *a, int n) {
double res = 0;
double sum = 0;
double average_sum = 0;
for (int i = 0; i < n; i++) {
sum += a[i];
}
average_sum = sum/n;
for(int i = 0; i < n; i++) {
    res += (a[i] - average_sum) * (a[i] - average_sum);
}
return res * 1/n;
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
                    printf("%d ", max_v);
                    printf("%d ", min_v);
                    printf("%.6f ", mean_v);
                    printf("%.6f ", variance_v);
                   }
