#include "../data_libs/data_io.h"
#include <stdio.h>
#include <stdlib.h>

int input(double *a, int n) {
int check2;
for (int i = 0; i < n; i++) {
check2 = scanf("%lf", &a[i]);
if ((double)check2 != 1.0) {
return 10;
break;
}
}
if (getchar() != '\n') {
return 10;
}
return 0;
}

void output(double *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n-1) {
        printf("%.2lf%s", a[i], " ");
        } else {
           printf("%.2lf", a[i]);
        }
    }
}

