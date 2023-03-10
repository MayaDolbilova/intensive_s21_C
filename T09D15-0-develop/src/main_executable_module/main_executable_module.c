#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_stat.h"
#include "../data_libs/data_io.h"
#include "../yet_another_decision_module/decision.h"
#include "../data_module/data_process.h"
int main() {
    double *data;
    int n;
if (scanf("%d", &n) == 1 && getchar() == '\n') {
if (n == 0 || n < 0) {
printf("n/a");
} else {
data = malloc(n * sizeof(double));
printf("LOAD DATA...\n");
if (input(data, n) == 0) {
printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);
printf("\nSORTED NORMALIZED DATA:\n\t");
sort(data, n);
output(data, n);
printf("\nFINAL DECISION:\n\t");
if (make_decision(data, n)) {
    printf("YES");
    } else {
    printf("NO");  }
} else {
    printf("n/a");
}
free(data);
}
}
return 0;}
