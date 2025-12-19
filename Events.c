#include <stdio.h>
#include <stdlib.h>
int cmp_desc(const void *a, const void *b) {
    return (*(int*)b) - (*(int*)a); }
int main() {
    int n, k;
    printf("Enter number of events: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter activity points for each event:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]); }
    printf("Enter maximum number of events you can participate : ");
    scanf("%d", &k);
    qsort(A, n , sizeof(int), cmp_desc);
    int max_points = 0;
    for (int i = 0; i < k && i < n; i++) {
        max_points += A[i]; }
    printf("Maximum activity points you can earn = %d\n", max_points);
    return 0; }