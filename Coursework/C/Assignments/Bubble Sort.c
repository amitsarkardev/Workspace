#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) {
    for (int i=0;i<n-1;i++) {
        bool swapped = false;
        // Last i elements are already in place
        for (int j=0; j<n-i-1;j++){
            if (arr[j]> arr[j+1]){
                // Swap adjacent elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped, then the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of elements for bubble sort: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d elements: \n", n);
    for (int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}