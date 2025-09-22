#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return;
}

void insertionSort(int* ptr, int n) {
    for (int i = 1; i < n; i++) {
        int key = ptr[i];
        int j = i - 1;
        while (j >= 0 && ptr[j] > key) {
            ptr[j + 1] = ptr[j];
            j--;
        }
        ptr[j + 1] = key;
    }
}

void selectionSort(int* ptr, int n) {
    return;
}

int main() {
    int n = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* ptr = (int*)malloc(n * sizeof(int));
    if(ptr == NULL) {
        printf("Memory can't be allocated.");
        return 1;
    }
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }
    
    bubbleSort(ptr, n);

    printf("The sorted elements are:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    free(ptr);
    return 0;
}