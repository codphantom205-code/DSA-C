#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right; };
struct Node* newNode(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n; }
struct Node* insert(struct Node* r, int x) {
    if (!r) return newNode(x);
    if (x < r->data) r->left = insert(r->left, x);
    else if (x > r->data) r->right = insert(r->right, x);
    return r; }
struct Node* minValue(struct Node* n) {
    while (n->left) n = n->left;
    return n; }
struct Node* delete(struct Node* r, int x) {
    if (!r) return r;
    if (x < r->data) r->left = delete(r->left, x);
    else if (x > r->data) r->right = delete(r->right, x);
    else {
        if (!r->left) {
            struct Node* t = r->right; free(r); return t;
        } else if (!r->right) {
            struct Node* t = r->left; free(r); return t; }
        struct Node* t = minValue(r->right);
        r->data = t->data;
        r->right = delete(r->right, t->data); }
    return r; }
void inorder(struct Node* r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right); } }
int search(struct Node* r, int x) {
    if (!r) return 0;
    if (r->data == x) return 1;
    else if (x < r->data) return search(r->left, x);
    else return search(r->right, x); }
int main() {
    struct Node* root = NULL;
    int n, val, s, d;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val); }
    printf("Inorder traversal: ");
    inorder(root);
    printf("\nEnter value to search: ");
    scanf("%d", &s);
    if (search(root, s)) printf("Found\n"); else printf("Not found\n");
    printf("Enter value to delete: ");
    scanf("%d", &d);
    root = delete(root, d);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n"); }