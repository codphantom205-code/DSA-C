#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Page {
    char url[100];
    struct Page* prev;
    struct Page* next;
} Page;
Page* createPage(const char* url) {
    Page* newPage = (Page*)malloc(sizeof(Page));
    strcpy(newPage->url, url);
    newPage->prev = NULL;
    newPage->next = NULL;
    return newPage; }
void visitPage(Page** current, const char* url) {
    Page* newPage = createPage(url);
    Page* temp = (*current)->next;
    while (temp) {
        Page* next = temp->next;
        free(temp);
        temp = next; }
    (*current)->next = newPage;
    newPage->prev = *current;
    *current = newPage;
    printf("Visited: %s\n", (*current)->url); }
void goBack(Page** current) {
    if ((*current)->prev) {
        *current = (*current)->prev;
        printf("Back to: %s\n", (*current)->url);
    } else { printf("No previous page to go back to.\n"); } }
void goForward(Page** current) {
    if ((*current)->next) {
        *current = (*current)->next;
        printf("Forwarded to: %s\n", (*current)->url);
    } else { printf("No forward page to go to.\n"); } }
void showCurrent(Page* current) { printf("Current page: %s\n", current->url); }
void freeHistory(Page* head) {
    while (head) {
        Page* temp = head;
        head = head->next;
        free(temp); } }
int main() {
    char input[100];
    int choice;
    Page* home = createPage("home");
    Page* current = home;
    while (1) {
        printf("\n1. Visit new page\n2. Go back\n3. Go forward\n4. Show current page\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; 
                visitPage(&current, input);
                break;
            case 2:
                goBack(&current);
                break;
            case 3:
                goForward(&current);
                break;
            case 4:
                showCurrent(current);
                break;
            case 5:
                while (current->prev) {
                    current = current->prev; }
                freeHistory(current);
                printf(" Exit. \n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n"); }
    }
    return 0; }
     