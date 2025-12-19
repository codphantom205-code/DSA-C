#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_EXPR_SIZE 100 
typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
typedef struct StackNode {
    TreeNode *treeNode;
    struct StackNode *next;
} StackNode;
StackNode *top = NULL;
void push(TreeNode *node) {
    StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        perror("Stack overflow");
        exit(EXIT_FAILURE); }
    newNode->treeNode = node;
    newNode->next = top;
    top = newNode; }
TreeNode* pop() {
    if (top == NULL) {
        return NULL; }
    StackNode *temp = top;
    TreeNode *node = temp->treeNode;
    top = top->next;
    free(temp);
    return node; }
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/'); }
TreeNode* buildExpressionTree(char *postfix) {
    int i = 0;
    top = NULL; 
    while (postfix[i] != '\0') {
        char c = postfix[i];
        TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
        if (newNode == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE); }
        newNode->data = c;
        newNode->left = NULL;
        newNode->right = NULL;
        if (!isOperator(c)) {
            push(newNode);
        } else {
            TreeNode *rightChild = pop();
            TreeNode *leftChild = pop();
            if (leftChild == NULL || rightChild == NULL) {
                printf("\nError: Invalid postfix expression (missing operands).\n");
                free(newNode); 
                if (leftChild) free(leftChild);
                if (rightChild) free(rightChild);
                return NULL; }
            newNode->right = rightChild;
            newNode->left = leftChild;
            push(newNode); }
        i++;
    } return pop(); }
void printPrefix(TreeNode* root) {
    if (root != NULL) {
        printf("%c", root->data);
        printPrefix(root->left);
        printPrefix(root->right); } }
void printPostfix(TreeNode* root) {
    if (root != NULL) {
        printPostfix(root->left);
        printPostfix(root->right);
        printf("%c", root->data); } }
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root); }
int main() {
    char postfixExpr[MAX_EXPR_SIZE];
    TreeNode *root = NULL;
        printf("\nEnter a simple POSTFIX arithmetic expression (e.g., abc*+ or 12+3*): \n> ");
    if (fgets(postfixExpr, MAX_EXPR_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1; }
    postfixExpr[strcspn(postfixExpr, "\n")] = 0;
    root = buildExpressionTree(postfixExpr);
    if (root != NULL) {
        printf("\n Results : \n");
        printf("Input Postfix: %s\n", postfixExpr);
        printf("Prefix exp : ");
        printPrefix(root);
        printf("\n");
        printf("Postfix exp : ");
        printPostfix(root);
        printf("\n");
        printf("---- ---- ----\n");
        freeTree(root); } 
    else { printf("Tree construction failed.\n"); }
    return 0; }