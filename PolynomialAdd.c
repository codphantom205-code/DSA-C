#include<stdio.h>
struct poly {
  int p[10][10]; };
int main() {
    int i, j, m = 0;
    int a[2];
    int result[20][20];
    struct poly s[2];
    for (i = 0; i < 2; i++) {
        printf("Enter the number of terms in polynomial %d: ", i + 1);
        scanf("%d", &a[i]); }
    for (i = 0; i < 2; i++) {
        printf("Enter the coefficient and exponent for polynomial %d:\n", i + 1);
        for (j = 0; j < a[i]; j++) {
            scanf("%d %d", &s[i].p[j][0], &s[i].p[j][1]); } }
    for (i = 0; i < 2; i++) {
        printf("Polynomial %d: ", i + 1);
        for (j = 0; j < a[i]; j++) {
            printf("%d x^%d", s[i].p[j][1], s[i].p[j][0]);
            if (j < a[i] - 1)
                printf(" + "); }
        printf("\n"); }
    for (i = 0; i < a[0]; i++) {
        result[m][0] = s[0].p[i][0];
        result[m][1] = s[0].p[i][1];
        m++; }
    for (i = 0; i < a[1]; i++) {
        int f = 0;
        for (j = 0; j < m; j++) {
            if (result[j][0] == s[1].p[i][0]) {
                result[j][1] += s[1].p[i][1];
                f = 1;
                break; } 
            } if (f==0) {
            result[m][1] = s[1].p[i][1];
            result[m][0] = s[1].p[i][0];
            m++; } }
    printf("Result: ");
    for (i = 0; i < m; i++) {
        printf("%d x^%d", result[i][1], result[i][0]);
        if (i < m - 1)
            printf(" + "); }
    return 0; }