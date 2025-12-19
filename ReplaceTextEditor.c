#include <stdio.h>
#include <string.h>
void findAndReplace(char text[], char find[], char replace[]) {
    char result[1000];
    int i = 0;
    result[0] = '\0';
    while (text[i] != '\0') {
        if (strncmp(&text[i], find, strlen(find)) == 0) {
            strcat(result, replace);
            i += strlen(find);
        } else {
            int len = strlen(result);
            result[len] = text[i];
            result[len + 1] = '\0';
            i++;  } }
    strcpy(text, result); }
int main() {
    char text[1000], find[100], replace[100];
    printf("Enter the text: ");
    gets(text); 
    printf("Enter word to find: ");
    gets(find);
    printf("Enter word to replace: ");
    gets(replace);
    findAndReplace(text, find, replace);
    printf("\nModified text: %s\n", text);
    return 0; }