    #include <stdlib.h>
    #include <stdio.h>
    #include "s21_string.h"


#ifdef PSTRLEN
#define hey s21_strlen_test();
#endif

#ifdef PCOMPARE
#define hey s21_strcmp_test();
#endif

#ifdef PCOPY
#define hey s21_strcry_test();
#endif

#ifdef PCAT
#define hey s21_strcat_test();
#endif


void s21_strlen_test();
void strlen_test(char* str, int n);
void s21_strcmp_test();
void compare_test(char* str1, char* str2);
void s21_strcry_test();
void copy_test(char* str1, char* str2, int n);
void s21_strcat_test();
void cat_test(char* str1, char* str2, char* str3, int n);

int main() {
    hey;
    return 0;
    }


void s21_strlen_test() {
    char* string_test_1 = "Hello!";
    char* string_test_2 = "?!!!!:(?;!";
    char* string_test_3 = "";
    char* string_test_4 = "Hell\0o!";
    int length_arr[4] = {6, 10, 0, 8};
    strlen_test(string_test_1, length_arr[0]);
    strlen_test(string_test_2, length_arr[1]);
    strlen_test(string_test_3, length_arr[2]);
    strlen_test(string_test_4, length_arr[3]);
    }


void strlen_test(char* str, int n) {
int length = s21_strlen(str);
  for (int i = 0; i < length; i++) {
        printf("%c", str[i]);
    }
    printf(" %d ", length);
    if (length == n) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcmp_test() {
    char* string_test_1 = "Hello!";
    char* string_test_2 = "?!!!!:(?;!";
    char* string_test_3 = "";
    char* string_test_4 = "Hell\0o!";
    char* string_test_5 = "Hello!";
compare_test(string_test_1, string_test_2);
compare_test(string_test_1, string_test_5);
compare_test(string_test_2, string_test_3);
compare_test(string_test_2, string_test_4);
}

void compare_test(char* str1, char* str2) {
int length1 = s21_strlen(str1);
int length2 = s21_strlen(str2);
for (int i = 0; i < length1; i++) {
        printf("%c", str1[i]);
    }
    printf("\n");
    for (int i = 0; i < length2; i++) {
        printf("%c", str2[i]);
    }
    int compare = s21_strcmp(str1, str2);
    printf("\n%d\n", compare);
    if ((int) compare == compare) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcry_test() {
char* string_test_1 = "Hello!";
char* string_test_2 = "?!!!!:(?;!";
char* string_test_3 = "";
char* string_test_4 = "Hell\0o!";
char string_test_5[50];
int length_arr[4] = {6, 10, 0, 8};
copy_test(string_test_1, string_test_5, length_arr[0]);
copy_test(string_test_2, string_test_5, length_arr[1]);
copy_test(string_test_3, string_test_5, length_arr[2]);
copy_test(string_test_4, string_test_5, length_arr[3]);
}

void copy_test(char* str1, char* str2, int n) {
int length = s21_strlen(str1);
for (int i = 0; i < length; i++) {
    printf("%c", str1[i]);
}
printf("\n");
s21_strcry(str1, str2, length);
for (int i = 0; i <= length; i++) {
    printf("%c", str2[i]);
}
printf("\n");
if(s21_strcmp(str1, str2) == 0 && s21_strlen(str2) == n) {
    printf("SUCCES\n");
} else {
    printf("FAIL\n");
}
}

void s21_strcat_test() {
char* string_test_1 = "Hello!";
char* string_test_2 = "?!!!!:(?;!";
char* string_test_3 = "";
char* string_test_4 = "Hell\0o!";
char* string_test_5 = "6543322";
int length_arr[5] = {21, 13, 8, 15};
char string_test_6[50];
char string_test_7[50];
char string_test_8[50];
char string_test_9[50];
cat_test(string_test_1, string_test_2, string_test_6, length_arr[0]);
cat_test(string_test_2, string_test_3, string_test_7, length_arr[1]);
cat_test(string_test_3, string_test_4, string_test_8, length_arr[2]);
cat_test(string_test_4, string_test_5, string_test_9, length_arr[3]);
}

void cat_test(char* str1, char* str2, char* str3, int n) {
int length1 = s21_strlen(str1);
int length2 = s21_strlen(str2);
for (int i = 0; i < length1; i++) {
    printf("%c", str1[i]);
}
printf("\n");
for (int i = 0; i < length2; i++) {
    printf("%c", str2[i]);
}
printf("\n");
int size3;
s21_strcat(str1, str2, str3, length1, length2, &size3);
for (int i = 0; i < size3 ; i++) {
    printf("%c", str3[i]);
}
printf("\n");
if (size3 == n) {
    printf("SUCCES\n");
} else {
    printf("FAIL\n");
}
}
