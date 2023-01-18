#include <stdio.h>
#include <stdlib.h>
#include "data_process.h"
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
    if (normalization(data, n) == 1) {
        output(data, n);} else {
       printf("ERROR");}
} else {
    printf("ERROR");
}
free(data);
}} else {
    printf("ERROR");
    }

return 0;
}
