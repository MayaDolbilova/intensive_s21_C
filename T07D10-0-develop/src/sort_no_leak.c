#include <stdio.h>
#include <stdlib.h>

int input(int *a, int n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
int n;
int *data;
int check1 = scanf("%d", &n);
if ((int) check1 == 1) {
if (n == 0 || n < 0) {
printf("n/a");
} else {
data = (int*)malloc(n * sizeof(int));
if (input(data, n) == 0) {
sort(data, n);
output(data, n);
free(data);
} else {printf("n/a");
}}} else {printf("n/a");}
return 0;}



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

void sort(int *a, int n) {
for (int i = 1; i < n; ++i) {
    int k = i;
    while (k > 0 && a[k-1] > a[k]) {
        int tmp = a[k-1];
        a[k-1] = a[k];
        a[k] = tmp;
        k -= 1;
    }
}
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", a[i], " ");
    }
}
