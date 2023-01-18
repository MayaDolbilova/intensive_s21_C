#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int check1 = scanf("%d", &n);
    if ((int)check1 == 1) {
    if (n > NMAX || n == 0 || n < 0) {
        printf("n/a");
        } else {
    if (input(data, n) == 0) {
    squaring(data, n);
    output(data, n);
    } else {
        printf("n/a");
    }
    }} else {
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

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i]*a[i];
    }
}


