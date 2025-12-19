#include <stdio.h>
#include <ctype.h>  
#include <string.h> 
#include <stdlib.h> 
#define MAX 100
char stack[MAX];
int top = -1;
void push(char x) {
    stack[++top] = x; }
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--]; }
int precedence(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0; }
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while ((stack[top] != '(') && top != -1) {
                postfix[k++] = pop(); }
            pop(); 
        } else { 
            while (precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = pop(); }
            push(ch); }
    }
    while (top != -1) {
        postfix[k++] = pop(); }
    postfix[k] = '\0';  }
int evalStack[MAX];
int evalTop = -1;
void evalPush(int x) {
    evalStack[++evalTop] = x; }
int evalPop() {
    return evalStack[evalTop--]; } 
int evaluatePostfix(char postfix[]) {
    int i = 0;
    char ch;
    int val1, val2;
    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            evalPush(ch - '0'); } 
            else {
            val2 = evalPop();
            val1 = evalPop();
            switch (ch) {
                case '+': evalPush(val1 + val2); break;
                case '-': evalPush(val1 - val2); break;
                case '*': evalPush(val1 * val2); break;
                case '/': evalPush(val1 / val2); break; }
        }
    }
    return evalPop(); }
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n", evaluatePostfix(postfix));
    return 0; }