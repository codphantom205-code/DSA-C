#include <stdio.h>
int main() {
    int r, c, i, j, k = 1;
    int mat[10][10], sparse[100][3], transpose[100][3];
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
    sparse[0][0] = r;
    sparse[0][1] = c;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
    sparse[0][2] = k - 1;
    printf("\nSparse Matrix:\nRow\tCol\tValue\n");
    for (i = 0; i < k; i++)
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    transpose[0][0] = sparse[0][1];
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];
    int t = 1;
    for (i = 0; i < c; i++)
        for (j = 1; j < k; j++)
            if (sparse[j][1] == i) {
                transpose[t][0] = sparse[j][1];
                transpose[t][1] = sparse[j][0];
                transpose[t][2] = sparse[j][2];
                t++;
            }
    printf("\nTranspose of Sparse Matrix:\nRow\tCol\tValue\n");
    for (i = 0; i < t; i++)
        printf("%d\t%d\t%d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    return 0;
}
