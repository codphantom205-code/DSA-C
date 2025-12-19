#include <stdio.h>
#define MAX 10
int queue[MAX], front = -1 , rear = -1;
void enqueue(int v) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = v; } }
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    else
        return queue[front++]; }
void bfs(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int v;
    enqueue(start);
    visited[start] = 1;
    printf("\nBFS Traversal: ");
    while ((v = dequeue()) != -1) {
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1; } } }
    printf("\n"); }
int main() {
    int n, start, adj[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    bfs(adj, n, start);
    return 0; }