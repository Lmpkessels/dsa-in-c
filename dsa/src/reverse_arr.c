#include <stdio.h>

int reverse_arr(int arr[], int n) {
    int temp[n];

    for (int i = 0; i < n; i++) {
        temp[i] = arr[n - i - 1];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i]; 
    }
}

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    printf("a: %d, b: %d\n", *a, *b);
}

int reverse_arr_w_swap(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        swap(&arr[left], &arr[right]);

        left++;

        right --;
    }
}

int main() {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[10]);

    reverse(arr, n);
    
    // Should be 10, 9, 8, ...
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    
    reverse_arr_w_swap(arr, n);
    
    // Should be 1, 2, 3, ...
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}