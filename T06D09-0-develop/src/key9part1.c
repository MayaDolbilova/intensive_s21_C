#include <stdio.h>
#define NMAX 10
int input(int *buffer, int length);
void output(int *buffer, int length, int sum);
int sum_numbers(int *buffer, int length);
void find_numbers(int* buffer, int length, int number, int* numbers, int *size);


int main() {
int n, data[NMAX], array_final[NMAX];
int sum;
int check1 = scanf("%d", &n);
if ((int) check1 == 1) {
if (n > 10 || n == 0 || n < 0) {
printf("n/a");
} else {
if (input(data, n) == 0) {
sum = sum_numbers(data, n);
if (sum > 0) {
int size = 0;
find_numbers(data, n, sum, array_final, &size);
output(array_final, size, sum);
} else {
printf("n/a");
}

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

int sum_numbers(int *buffer, int length) {
int sum = 0;
for (int i = 0; i < length; i++) {
if (buffer[i] % 2 == 0) {
sum += buffer[i];
}
}
return sum;
}

void find_numbers(int* buffer, int length, int number, int* numbers, int *size) {
int top = 0;
for (int i = 0; i < length; i++) {
if(buffer[i] != 0) {
if(number % buffer[i] == 0) {
numbers[top] = buffer[i];
top++;
}}}
*size = top;
}

void output(int *buffer, int length, int sum) {
printf("%d\n", sum);
for (int i = 0; i < length; i++) {
printf("%d ", buffer[i]);
}
}
