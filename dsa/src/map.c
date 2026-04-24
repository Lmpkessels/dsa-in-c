#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 // Max size to store keys and values

int size = 0; // The number of elements in the map
char keys[MAX_SIZE][100]; // Total amount of keys with maximum capacity to store
int values[MAX_SIZE]; // Total amount of values with maximum capacity to store

// Count size of the array to test get_index()
int count(char k[MAX_SIZE][100]) {
    int count = 0;

    while (count < MAX_SIZE && k[count][0] != '\0') {
        count++;
        size++;
    }

    return size;
}

// Get the index of a key within keys
int get_index(char key[]) {
    char keys[MAX_SIZE][100] = {"Type", "Data", "Data-structure"};
    size = count(keys);

    for (int i = 0; i < size; i++) {
        if (strcmp(keys[i], key) == 0) {
            return i; // Return when key is found
        }
    }

    return -1; // Return when key is not found
}

int main(void) {
    char *key = "Data";

    char get_index_key = get_index(key);

    printf("%d\n", get_index_key);

    int c = count(keys);

    printf("%d\n", c);
}