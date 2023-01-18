#include <stdio.h>
#include <stdlib.h>
void switch_case(FILE* stream, int user_choice, int check_choice, char* path_to_file);
void case_1(FILE* stream);
void case_2(FILE* stream, char* path_to_file);
void caesar_shift(char c, int n, int eng, FILE* file1, int count);
void changing_files(FILE* file1, int shift, int eng);
int main() {
    FILE* stream = NULL;
    int user_choice = 0, check_choice = 0;
    char path_to_file[500];
    printf("1. Enter the path to the file you'd like to open\n");
    printf("2. Print a string you'd like to add to opened file\n");
    printf("3. Caesars code\n");
    printf("If you'd like to exit the program, please press -1\n");
    switch_case(stream, user_choice, check_choice, path_to_file);
return 0;
}


void switch_case(FILE* stream, int user_choice, int check_choice, char* path_to_file) {
    while (check_choice == 0) {
        scanf("%d", &user_choice);
        if (getchar() == '\n') {
            switch (user_choice) {
                case 1: {
                scanf("%s", path_to_file);
                stream = fopen(path_to_file, "r");
                case_1(stream);
                break;
                }
                case 2: {
                case_2(stream, path_to_file);
                break;
                }
                case 3: {
                char path_to_file3[] = "ai_modules/m1.h";
                char path_to_file4[] = "ai_modules/m2.h";
                FILE* file_h1 = NULL;
                file_h1 = fopen(path_to_file3, "w+");
                fclose(file_h1);
                FILE* file_h2 = NULL;
                file_h2 = fopen(path_to_file4, "w+");
                fclose(file_h2);
                FILE* file1 = NULL;
                FILE* file2 = NULL;
                int shift = 0;
                int eng = 26;
                scanf("%d", &shift);
                char path_to_file1[] = "ai_modules/m1.c";
                char path_to_file2[] = "ai_modules/m2.c";
                file1 = fopen(path_to_file1, "r+");
                file2 = fopen(path_to_file2, "r+");
                changing_files(file1, shift, eng);
                changing_files(file2, shift, eng);
                fclose(file1);
                break;
                }
                case -1: {
                check_choice = 1;
                break;
                }
                default: {
                printf("n/a\n");
                break;
                }
            }
        } else {
        printf("n/a\n");
        }
    }
}


void case_1(FILE* stream) {
int c;
    if (stream != NULL) {
    int empty = ((c = getc(stream)) == EOF? 0 : 1);
        if (empty == 1) {
        printf("%c", c);
            while (1) {
            c = fgetc(stream);
                if (feof(stream)) {
                break;
                }
            printf("%c", c);
            }
        printf("\n");
        fclose(stream);
        } else {
        printf("n/a\n");
        }
    } else {
    printf("n/a\n");
    }
}

void case_2(FILE* stream, char* path_to_file) {
    char string[500];
    int i = 0;
    char p;
    while ((p = getchar()) != '\n') {
        string[i] = p;
        i++;
    }
    if (stream != NULL) {
            stream = fopen(path_to_file, "a");
            fprintf(stream, string);
            fclose(stream);
            stream = fopen(path_to_file, "r");
            int c;
                while (1) {
                            c = fgetc(stream);
                            if (feof(stream)) {
                                break;
                            }
                            printf("%c", c);
                        }
                printf("\n");
                fclose(stream);
    } else {
                printf("n/a\n");
        }
}

void caesar_shift(char c, int n, int eng, FILE* file1, int count) {
if (c >= 'A' && c <= 'Z') {
            c = c + (n % eng);
            if (c > 'Z') c = 'A' + (c - 'Z') - 1;
            char* k = &c;
            fseek(file1, count, SEEK_SET);
            fputs(k, file1);
        } else if (c >= 'a' && c <= 'z') {
            c = c + (n % eng);
            if (c > 'z') c = 'a' + (c - 'z') - 1;
            char* k = &c;
            fseek(file1, count, SEEK_SET);
            fputs(k, file1);
        } else {
            char* k = &c;
            fseek(file1, count, SEEK_SET);
            fputs(k, file1);
        }
}

void changing_files(FILE* file1, int shift, int eng) {
char c;
int count  = 0;
    if (file1 != NULL) {
        while (1) {
        c = fgetc(file1);
            if (feof(file1)) {
            break;
            }
        caesar_shift(c, shift, eng, file1, count);
        count++;
        }
    } else {
    printf("n/a");
    }
}
