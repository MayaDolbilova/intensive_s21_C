#include <stdio.h>

#define LEN 100

void sum(int number1, int number2, int *result, int *result_length);
void sub(int number1, int number2, int *result, int *result_length);
void converting_to_oneint(int *a, int n, int *number);
int input(int *a, int *length);
void output(int *a, int n);

int main() {
  int length1 = 0, length2 = 0;
int data[LEN], array[LEN];
int first = 0, second = 0;
int result_arr1[LEN], resut_arr2[LEN];
int res_len1 = 0, res_len2 = 0;
if (input(data, &length1) == 0) {
if (input(array, &length2) == 0) {
converting_to_oneint(data, length1, &first);
converting_to_oneint(array, length2, &second);
sum(first, second, result_arr1, &res_len1);
output(result_arr1, res_len1);
if (second > first) {
  printf("n/a");
} else {
sub(first, second, resut_arr2, &res_len2);
output(resut_arr2, res_len2);
}
} else {
  printf("n/a");
}
} else {
  printf("n/a");
}
}


int input(int *a, int *length) {
char space;
int symbol;
int i = 0;
while (scanf("%d%c", &symbol, &space) && i < LEN) {
  if (symbol < 10 && 0 <= symbol) {
  if (space == ' ') {
    a[i] = symbol;
    i++;
  } else {
    a[i] = symbol;
    i++;
break;}
} else {return 10;}
}

*length = i;
return 0;
}

void converting_to_oneint(int *a, int n, int *number) {
int res = 0;
for (int i = 0; i < n; i++) {
  res = res * 10 + a[i];
}
*number = res;
}

void sum(int number1, int number2, int *result, int *result_length) {
int sum = number1 + number2;
int i = 0;
while (sum != 0) {
  result[i] = sum % 10;
  i++;
  sum /= 10;
}
*result_length = i;
}

void sub(int number1, int number2, int *result, int *result_length) {
int sub = number1 - number2;
int i = 0;
while (sub != 0) {
  result[i] = sub % 10;
  i++;
  sub /= 10;
}
*result_length = i;
}

void output(int *a, int n) {
for (int i = n-1; i >= 0; i--) {
  printf("%d ", a[i]);}
  printf("\n");
}
