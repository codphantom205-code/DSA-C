#include <stdio.h>
#define TABLE_SIZE 10
int hashFunction(int key) 
{
    return key % TABLE_SIZE; 
}
void insert(int hashTable[], int key) 
{
    int index = hashFunction(key);
    int originalIndex = index;
    while (hashTable[index] != -1) 
    {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) 
        {
            printf("Hash table is full! Cannot insert key %d\n", key);
            return; 
        }
    }
    hashTable[index] = key;
    printf("Inserted key %d at index %d\n", key, index); 
}
int main() 
{
    int hashTable[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
        hashTable[i] = -1; 
    }
    int n;
    printf("Enter the number of integers to insert: ");
    scanf("%d", &n);
    if (n > TABLE_SIZE) 
    {
        printf("Warning: Number of integers exceeds hash table size.Some of the key may not be inserted  \n"); }
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        int key;
        scanf("%d", &key);
        insert(hashTable, key); 
    }
    printf("\nFinal hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: Empty\n", i); 
        }
    return 0; 
}