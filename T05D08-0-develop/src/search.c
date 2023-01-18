#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int n);
int output(int *a, int n, double x, double y);
double mean(int *a, int n);
double three_sigm(double z, double x);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    double x, y, z;
    int check1 = scanf("%d", &n);
    if ((int) check1 == 1) {
    if (n > 30 || n == 0 || n < 0) {
        printf("n/a");
        } else {
    if (input(data, n) == 0) {
       x = mean(data, n);
        z = variance(data, n);
        y = three_sigm(z, x);
        printf("%d", output(data, n, x , y));
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


double three_sigm(double z, double x) {
double mean = x;
double res = 0;
double var = z;
res = mean + 3 * sqrt(var);
return res;
}


int output(int *a, int n, double x, double y) {
    int count = 0;
    int number = 0;
for (int i = 0; i < n; i++) {
    if (a[i]%2 == 0 && a[i]>= x && a[i] <= y && a[i] != 0) {
        count++;
        number = a[i];
        break;
    }
    }
if (count > 0) {return number;} else {
    return 0;}
}




