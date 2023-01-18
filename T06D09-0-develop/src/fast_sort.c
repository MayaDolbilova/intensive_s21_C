#include <stdio.h>
#define NMAX 10
int input(int *a, int n);
void output(int *a, int n);
void quicksort(int *a, int left, int right);
// void sliyanie_sort(int *a, int n);

int main() {
int n = 10, array[NMAX];
if (input(array, n) == 0) {
quicksort(array, 0, n-1);
output(array, n);
// sliyanie_sort(array, n);
// output(array, n);
} else {
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

void quicksort(int *a, int left, int right) {
int opornyi_elem = a[left];
int l_side = left;
int r_side = right;
  while (left < right) {
    while ((a[right] >= opornyi_elem) && (left < right))
      right--;
      if (left != right) {
      a[left] = a[right];
      left++;
    }
    while ((a[left] <= opornyi_elem) && (left < right))
      left++;
    if (left != right) {
      a[right] = a[left];
      right--;
    }
  }
  a[left] = opornyi_elem;
  opornyi_elem = left;
  left = l_side;
  right = r_side;
  if (left < opornyi_elem)
    quicksort(a, left, opornyi_elem - 1);
  if (right > opornyi_elem)
    quicksort(a, opornyi_elem + 1, right);
}

// void sliyanie_sort(int *a, int n) {
// }

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", a[i], " ");
    }
}
