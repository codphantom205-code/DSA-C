#include <stdio.h>
long long bubbleSteps = 0, insertionSteps = 0, quickSteps = 0, mergeSteps = 0;
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            bubbleSteps++;
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                bubbleSteps++; } } }
void insertionSort(int a[], int n) {
    for (int i = 1; i < n-1; i++) {
        int j=a[i];
        int k=i;
        while(k>0 && a[k-1]>j){
            a[k]=a[k-1];
            k=k-1;
            insertionSteps++ ;}
            a[k]=j; } }
int partition(int a[], int l, int h) {
    int pivot = a[h], i = l - 1, t;
    for (int j = l; j < h; j++) {
        quickSteps++;
        if (a[j] < pivot) {
            i++; t = a[i]; a[i] = a[j]; a[j] = t; } }
    t = a[i + 1]; a[i + 1] = a[h]; a[h] = t;
    return i + 1; }
void quickSort(int a[], int l, int h) {
    if (l < h) {
        int pi = partition(a, l, h);
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, h); } }
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m, L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        mergeSteps++;
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++]; }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++]; }
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r); } }
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n], b[n], c[n], d[n], e[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        b[i] = c[i] = d[i] = e[i] = arr[i]; }
    bubbleSort(b, n);
    insertionSort(c, n);
    quickSort(d, 0, n - 1);
    mergeSort(e, 0, n - 1);
    printf("\n Steps Comparison \n");
    printf("Bubble Sort   : %ld\n", bubbleSteps);
    printf("Insertion Sort: %lld\n", insertionSteps);
    printf("Quick Sort    : %lld\n", quickSteps);
    printf("Merge Sort    : %lld\n", mergeSteps);
    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", e[i]);
    printf("\n");
    return 0; }