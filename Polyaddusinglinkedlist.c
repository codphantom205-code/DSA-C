#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next; };
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode; }
void insertTerm(struct Node** poly, int coeff, int exp) {
    if (coeff == 0) return; 
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL || exp > (*poly)->exp) {
        newNode->next = *poly;
        *poly = newNode;}
        else{
        struct Node* temp = *poly;
        struct Node* prev = NULL;
        while (temp != NULL && temp->exp > exp) {
            prev = temp;
            temp = temp->next; }
        if (temp != NULL && temp->exp == exp) {
            temp->coeff += coeff;
            free(newNode); } 
        else {
            newNode->next = temp;
            if (prev != NULL)
                prev->next = newNode;
            else
                *poly = newNode; }
    }
}
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next; } 
        else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next; } 
        else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next; }
    } while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next; }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next; }
    return result; }
void printPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return; }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL)
            printf(" + "); }
    printf("\n"); }
void readPolynomial(struct Node** poly)  {
    int n, coeff, exp;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)  {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coeff, &exp);
        insertTerm(poly, coeff, exp); }
}
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    printf("Enter first polynomial.\n");
    readPolynomial(&poly1);
    printf("Enter second polynomial.\n");
    readPolynomial(&poly2);
    printf("\nPolynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);
    sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    printPolynomial(sum);
    return 0; }