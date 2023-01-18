#include <stdio.h>
#include <stdlib.h>
#define MAXHEIGHT 100
#define MAXWIDTH 100

int input_matrix_stat(int matrix[][MAXWIDTH], int h, int w);
void output_matrix_stat(int matrix[][MAXWIDTH], int h, int w);
int input_matrix_dynamic1(int** matrix, int h, int w, int* pointer);
void output_matrix_dynamic(int** matrix, int h, int w);
int input_matrix_dynamic2(int** matrix, int h, int w);
int input_matrix_dynamic3(int** point_arr, int* array, int h, int w);



int main() {
int user_choice;
printf("Choose a way to make matrix:\n1. Static\n");
printf("2. Dynamic. Array of pointers to array segments within one buffer\n");
printf("3. Dynamic. Array of pointers to arrays\n");
printf("4. Array of pointers to segments of second array");
scanf("%d", &user_choice);
if (user_choice == 1 || user_choice == 2 || user_choice == 3|| user_choice == 4) {
int h, w, check1, check2;
check1 = scanf("%d", &h);
check2 = scanf("%d", &w);
if ((int)check1 == 1 && (int)check2 == 1) {
switch (user_choice) {
    case 1: {
     int matrix[MAXHEIGHT][MAXWIDTH];
     if (h < MAXHEIGHT && w < MAXWIDTH) {
     if (input_matrix_stat(matrix, h, w) == 0) {
     output_matrix_stat(matrix, h, w);
     } else {printf("n/a");}
     } else {
        printf("n/a");
     }
     break;
       }
    case 2: {
    int** matrix = malloc(h * w * sizeof(int) + h * sizeof(int*));
    int* pointer = (int*)(matrix + h);
    if (input_matrix_dynamic1(matrix, h, w, pointer) == 0) {
    output_matrix_dynamic(matrix, h, w);
    } else {printf("n/a");}
    free(matrix);
    break;}
    case 3: {
        int** arr_point = malloc(h * sizeof(int*));
        if (input_matrix_dynamic2(arr_point, h, w) == 0) {
            output_matrix_dynamic(arr_point, h, w);
            for (int i = 0; i < h; i++) {
            free(arr_point[i]);
        }
        } else {
            for (int i = 0; i < h; i++) {
                free(arr_point[i]);
            }
            printf("n/a");
        }
        free(arr_point);
        break;}
    case 4: {
        int** arr_point = malloc(h*sizeof(int*));
        int* just_arr = malloc(h * w * sizeof(int));
        if (input_matrix_dynamic3(arr_point, just_arr, h, w) == 0) {
         output_matrix_dynamic(arr_point, h, w);
        } else {
            printf("n/a");
        }
        free(arr_point);
        free(just_arr);
        break;}
    default: {printf("n/a"); break;}
}} else {
    printf("n/a");
}} else {printf("n/a");}

    return 0;
}

int input_matrix_stat(int matrix[][MAXWIDTH], int h, int w) {
    int n, flag = 0;
for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (scanf("%d", &n) == 1) {
            matrix[i][j] = n;} else {flag = 1; break;}
        }
     }
return flag;
}
int input_matrix_dynamic1(int** matrix, int h, int w, int* pointer) {
int n, flag = 0;
for (int i = 0; i < h; i++) {
    matrix[i] = pointer + w * i;
}
for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (scanf("%d", &n) == 1) {
            matrix[i][j] = n;} else {flag = 1; break;}
        }
     }
return flag;
}
int input_matrix_dynamic2(int** matrix, int h, int w) {
int n, flag = 0;
for (int i = 0; i < h; i++) {
    matrix[i] = malloc(w *sizeof(int));
}
for(int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (scanf("%d", &n) == 1) {
            matrix[i][j] = n;} else {
                flag = 1; break;}
        }
     }
return flag;
}
int input_matrix_dynamic3(int** point_arr, int* array, int h, int w) {
int n, flag = 0;
for(int i = 0; i < h; i++) {
    point_arr[i] = array + w * i;
}
for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (scanf("%d", &n) == 1) {
            point_arr[i][j] = n;} else {
            flag = 1; break;}
        }
     }
return flag;
}
void output_matrix_stat(int matrix[][MAXWIDTH], int h, int w) {
    int max = 0;
    int min = 9999;
    int max_arr[MAXWIDTH], len = 0;
for(int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int n = matrix[i][j];
            if (j < w-1) {
            printf("%d ", n);} else {
            printf("%d", n);}
            }
            printf("\n");}

for(int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
              if (matrix[i][j] > max) {
                max = matrix[i][j];
              }
        }
        max_arr[len] = max;
        len++;
        max = 0;
        }
int count = 0;
int min_arr[MAXWIDTH];

for(int i = 0; i < h; i++) {
        min = 9999;
        for (int j = 0; j < w; j++) {
          if (matrix[j][i] < min) {
          min = matrix[j][i];
}}
min_arr[count] = min;
count++;
}
for (int i = 0; i < len; i++) {
            if (i < len - 1) {
            printf("%d ", max_arr[i]);} else {
            printf("%d\n", max_arr[i]);
            }
        }

        for (int i = 0; i < count; i++) {
            if (i < count - 1) {
            printf("%d ", min_arr[i]);} else {
            printf("%d", min_arr[i]);
            }
        }
        }


void output_matrix_dynamic(int** matrix, int h, int w) {
    int max = 0;
    int min = 9999;
    int max_arr[MAXWIDTH], len = 0;
for(int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int n = matrix[i][j];
            if (j < w-1) {
            printf("%d ", n);} else {
            printf("%d", n);}
            }
            printf("\n");
            }

for(int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
              if (matrix[i][j] > max) {
                max = matrix[i][j];
              }
        }
        max_arr[len] = max;
        len++;
        max = 0;
        }
int count = 0;
int min_arr[MAXWIDTH];

for(int i = 0; i < h; i++) {
        min = 9999;
        for (int j = 0; j < w; j++) {
          if (matrix[j][i] < min) {
          min = matrix[j][i];
}}
min_arr[count] = min;
count++;
}
for (int i = 0; i < len; i++) {
            if (i < len - 1) {
            printf("%d ", max_arr[i]);} else {
            printf("%d\n", max_arr[i]);
            }
        }

        for (int i = 0; i < count; i++) {
            if (i < count - 1) {
            printf("%d ", min_arr[i]);} else {
            printf("%d", min_arr[i]);
            }
        }
}

