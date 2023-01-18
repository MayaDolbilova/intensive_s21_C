#include "decision.h"
#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_io.h"
int main() {
double *data;
int n;
if (scanf("%d", &n) == 1 && getchar() == '\n') {
if (n == 0 || n < 0) {
printf("ERROR");
} else {
data = (double*)malloc(n * sizeof(double));
if (input(data, n) == 0) {
if (make_decision(data, n)) {
        printf("YES");
        } else {
        printf("NO");  }
} else {
    printf("n/a");
}
free(data);
}} else {
    printf("n/a");
    }

return 0;
}
