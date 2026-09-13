#include<stdio.h>

//Utility function to swap two elements
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Lomuto partition scheme: uses the last element as pivot
int partition(int arr[],int low,int high){
    int pivot = arr[high]; //Pivot element
    int i = low - 1; //Index of smaller element

    for(int j=low;j<high;j++){
        //If current element is smaller than or equal to pivot
        if(arr[j]<pivot){
            i++; //Increment index of smaller element
            swap(&arr[i],&arr[j]);
        }
    }
    //Place the pivot in its correct position
    swap(&arr[i + 1], &arr[high]);
    return i + 1; //Return the index of the pivot
}

//Recursive function to implement quick sort
void quickSort(int arr[],int low,int high){
    if(low<high){
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);
        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter number of elements for quick sort: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d elements: \n", n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);

    printf("Sorted array: \n");
    printArray(arr,n);
    return 0;
}