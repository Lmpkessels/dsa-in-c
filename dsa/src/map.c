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
    for (int i = 0; i < size; i++) {
        if (strcmp(keys[i], key) == 0) {
            return i; // Return when key is found
        }
    }

    return -1; // Return when key is not found
}

// Insert a key value pair
void insert(char key[], int value) {
    int index = get_index(key);

    // If key does not exist insert key and value
    if (index == -1) {
        strcpy(keys[size], key);
        values[size] = value;
        size++;
    } else { // Key already exists update value if needed
        values[size] = value;
    }
}

// Get the value that is assigned to the key
int get_value(char key[]) {
    int index = get_index(key);

    if (index == -1) { // If key does not exist
        return -1;
    } else {
        return values[index]; // If key does exist
    }
}

// Print the entire map
int print_map() {
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", keys[i], values[i]);
    }
}

int main(void) {
    insert("Age_Peter", 18);
    insert("Age_Karel", 19);
    insert("Age_Luke", 26);

    print_map();

    printf("%d\n", get_value("Age_Peter"));
}