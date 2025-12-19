#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;
typedef struct Stack {
    Node* data[MAX];
    int top;
} Stack;
void initStack(Stack* s) {
    s->top = -1;
}
void push(Stack* s, Node* node) {
    s->data[++(s->top)] = node;
}
Node* pop(Stack* s) {
    return s->data[(s->top)--];
}
int isOperand(char c) {
    return isdigit(c);  
}
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isOperand(c)) {
            postfix[k++] = c; 
        } else if (c == '(') {
            push(&s, createNode(c)); 
        } else if (c == ')') {
            while (s.top != -1 && s.data[s.top]->data != '(') {
                postfix[k++] = pop(&s)->data; 
            }
            pop(&s); 
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (s.top != -1 && precedence(s.data[s.top]->data) >= precedence(c)) {
                postfix[k++] = pop(&s)->data;  
            }
            push(&s, createNode(c));  
        }
    }
    while (s.top != -1) {
        postfix[k++] = pop(&s)->data;
    }
    postfix[k] = '\0'; 
}
Node* constructExpressionTree(char* postfix) {
    Stack s;
    initStack(&s);
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isOperand(c)) {
            push(&s, createNode(c));  
        } else {
            Node* node = createNode(c);  
            node->right = pop(&s);  
            node->left = pop(&s);   
            push(&s, node); 
        }
    }
    return pop(&s);  
}
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%c ", root->data); 
    preorder(root->left);     
    preorder(root->right); 
}
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);      
    postorder(root->right);    
    printf("%c ", root->data);  
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    Node* root = constructExpressionTree(postfix);
    printf("Prefix Expression: ");
    preorder(root);
    printf("\n");
    printf("Postfix Expression (from tree): ");
    postorder(root);  
    printf("\n");
    return 0;
}