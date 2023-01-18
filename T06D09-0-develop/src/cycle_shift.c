#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void shift(int *a, int n, int size_shift);

int main() {
    int n, c, data[NMAX];
    int check1 = scanf("%d", &n);
     int check_number;
    if ((int) check1 == 1) {
    if (n > 10 || n == 0 || n < 0) {
        printf("n/a");
        } else {
    if (input(data, n) == 0) {
        int check2 = scanf("%d", &c);
        if (getchar() == '\n') {
        if ((int)check2 == 1 && c != 0 && c <= n) {
        if (c < 0) {check_number = -1 * c;}
        if (check_number > n) {printf("n/a");} else {
        shift(data, n, c);
        output(data, n);
        }} else {
            printf("n/a");
        }
        } else {
        printf("n/a");}
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
    printf("%d ", a[i]);
}
}

void shift(int *a, int n, int size_shift) {
if (size_shift > 0) {
    int arr[NMAX];
    int shifting = size_shift;
    for (int i = 0; i < size_shift; i++) {
        arr[i] = a[i];
        shifting--;
    }
    for (int i = 0; i < n-1; ++i) {
        a[i] = a[i + size_shift];
    }
    int sh = size_shift;
for (int i = 0; i < size_shift; i++) {
        a[n-sh] = arr[i];
        sh--;
}

} else {
    int arr[NMAX];
    int shifting = size_shift;
    for (int i = 0; i < -(size_shift); i++) {
        arr[i] = a[n+(shifting)];
        shifting++;
    }
    for (int i = n-1; i > 0; --i) {
        a[i] = a[i + size_shift];
    }
    for (int i = 0; i < -(size_shift); i++) {
        a[i] = arr[i];
        }}}
