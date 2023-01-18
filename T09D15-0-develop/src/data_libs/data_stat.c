#include "../data_libs/data_stat.h"
#include <stdio.h>
#include <stdlib.h>

double max(double *data, int n) {
    double max = -9999;
for (int i = 0; i < n; i++) {
if (data[i] > max) {
max = data[i];
}
}
return max;
}

double min(double* data, int n) {
double min = 9999;
for(int i = 0; i < n; i++) {
if (data[i] < min) {
min = data[i];
}
}
return min;
}

double mean(double *data, int n) {
     double sum = 0;
    for (int i = 0; i < n; i++) {
    sum += data[i]*1.0/n;}
    return sum;
}

double variance(double *data, int n) {
double res = 0;
double sum = 0;
double average_sum = 0;
for (int i = 0; i < n; i++) {
sum += data[i];
}
average_sum = sum/n;
for(int i = 0; i < n; i++) {
    res += (data[i] - average_sum) * (data[i] - average_sum);
}
return res * 1/n;
}

void sort(double* data, int n) {
for (int i = 1; i < n; ++i) {
    int k = i;
    while (k > 0 && data[k-1] > data[k]) {
        double tmp = data[k-1];
        data[k-1] = data[k];
        data[k] = tmp;
        k -= 1;
    }
}
}
