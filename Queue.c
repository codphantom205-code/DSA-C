#include<stdio.h>
#define MAX_SIZE 10
int front = 0;
int rear = -1;
int q[MAX_SIZE];
void de () {
    if (rear < front) {
        printf("The Queue is empty"); }
    else {
        int n = q[front];
        printf("The deleted element is= %d",n);
        front++;
        if (front > rear) {
            front = 0;
            rear = -1; }
    }
}
void en () {
    if (rear == MAX_SIZE - 1) {
        printf("The Queue is full."); }
    else {
        int n1;
        printf("Enter the number: ");
        scanf("%d", &n1);
        rear++;
        q[rear] = n1; }
    printf("\n"); }
void display() {  
if (rear < front) {
        printf("The Queue is empty.\n"); } 
    else {
        printf("Elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", q[i]); }
        printf("\n"); }
}
void pe() {
if (rear < front) {
        printf("The Queue is empty.\n"); } 
else {
        printf("Element at the peek = %d\n", q[front]); }
}
int main() {
int w,n = 1;
printf(" Enqueue=1 \n Dequeue=2 \n Display=3 \n Peek = 4 \n Exit=5 \n");
while (n) {
printf("\nEnter the process num = ");
scanf("%d", &w);
switch (w) {
case 1:
    en();
    break;
case 2:
    de();
    break;
case 3:
    display();
    break;
case 4:
    pe();
    break;
case 5:
    n = 0;
    break;
default:
    printf ("Invalid");
    break; }
}
return 0; }