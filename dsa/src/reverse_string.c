#include <stdio.h>

int strlenc(char *s) {
    int count = 0;

    while (*s != '\0') {
        count++;
        s++;
    }

    return count;
}

char reverse_string(char *s) {
    int left = 0;
    int right = strlenc(s) - 1;
    char temp;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main(void) {
    char string[20] = "Hello, World!";
    
    reverse_string(string);

    printf("%s\n", string);
    return 0;
}