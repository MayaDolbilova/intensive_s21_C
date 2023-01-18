#include <stdlib.h>
#include <stdio.h>
#include "s21_string.h"

int s21_strlen(char* str) {
size_t length = 0;
for (; *(str + length); length++) {
    continue;
}
return length;
}

int s21_strcmp(char* str1, char* str2) {
for (; *str1 && *str1 == *str2; str1++, str2++) {
}
return *str1 - *str2;
}

void s21_strcry(char* str1, char* str2, int size1) {
for (int i = 0; i <= size1; i++) {
    str2[i] = str1[i];
}
}

void s21_strcat(char* str1, char* str2, char* str3, int size1, int size2, int* k) {
    int in = 0;
for (int i = 0; i < size1; i++) {
    str3[in] = str1[i];
    in++;
}
for (int i = 0; i < size2; i++) {
    str3[in] = str2[i];
    in++;
}
*k = in;
}
