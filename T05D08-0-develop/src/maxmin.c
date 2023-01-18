#include <stdio.h>

void maxmin(int  prob1, int prob2, int  prob3, int* max, int* min);
/* Find a max & min probabilities */
int main() {
    int x, y, z;
    int max = 0, min = 0;
    int check1 = scanf("%d", &x);
    int check2 = scanf("%d", &y);
    int check3 = scanf("%d", &z);
    if (getchar() != '\n') {
       printf("n/a");
    } else {
    if ((int)check1 == 1 && (int)check2 == 1 && (int)check3 == 1) {
      if ((x == y&&x != z) || (x == z&&x != y) || (z == y&&z != x)) {
            maxmin(x, y, z, &max, &min);
            printf("%d %d", max, min);} else if (x == y && x == z&&y == z) {
            printf("%d %d", x, y);
            } else {
        maxmin(x, y, z, &max, &min);
        printf("%d %d", max, min);}
      } else {
        printf("n/a");
    }}
    return 0;
}



/* This function should be kept !!! (Your AI) */
/* But errors & bugs should be fixed         */
void maxmin(int prob1, int prob2, int prob3, int* max, int* min) {
    if (prob2 <= prob1 && prob3 <= prob1) {
        *max = prob1;
    } else if (prob1 <= prob2 && prob3 <= prob2) {
        *max = prob2;
    } else {*max = prob3;}

    if (prob1 <= prob2&&prob1 <= prob3) {
        *min = prob1;
    } else if (prob2 <= prob1&&prob2 <= prob3) {
        *min = prob2;
    } else {
        *min = prob3;
    }
}
