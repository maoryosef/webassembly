#include <stdio.h>
#include <stdlib.h>
#include <emscripten/emscripten.h>

void merge(int arr[], int left[], int leftCount, int right[], int rightCount) {
    int i, j, k;

    i = 0;
    j = 0;
    k = 0;

    while (i < leftCount && j < rightCount) {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < leftCount) {
        arr[k++] = left[i++];
    }
    
    while (j < rightCount) {
        arr[k++] = right[j++];
    }
}

void EMSCRIPTEN_KEEPALIVE mergeSort(int arr[], int length) {
    int mid, i, *left, *right;
    if (length < 2) {
        return;
    }

    mid = length / 2;

    left = (int *)malloc(mid * sizeof(int));
    right = (int *)malloc((length - mid) * sizeof(int));

    for (i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (i = mid; i < length; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, length - mid);
    merge(arr, left, mid, right, length - mid);
    free(left);
    free(right);
}


void EMSCRIPTEN_KEEPALIVE bubbleSort(int arr[], int length) {
    int i, j, swap;
    
    for (i = 0; i < (length - 1); i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
}
 
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    
    return (i + 1);
}
 
void EMSCRIPTEN_KEEPALIVE quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partitionWithIndex(int arr[], int low, int high, int indexArr[]) {
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]); 
            swap(&indexArr[i], &indexArr[j]); 
        }
    }

    swap(&arr[i + 1], &arr[high]);
    swap(&indexArr[i + 1], &indexArr[high]);

    return (i + 1); 
}

void quickSortWithIndexRec(int arr[], int low, int high, int indexArr[]) {
    if (low < high) {
        int pi = partitionWithIndex(arr, low, high, indexArr);
 
        quickSortWithIndexRec(arr, low, pi - 1, indexArr); 
        quickSortWithIndexRec(arr, pi + 1, high, indexArr);
    }
}

void initArray(int* a, int len) {
    for (int i = 0; i < len; i++) {
        a[i] = i;
    }
}

void EMSCRIPTEN_KEEPALIVE quickSortWithIndex(int arr[], int low, int high, int indexArr[]) {
    initArray(indexArr, high + 1);
    quickSortWithIndexRec(arr, low, high, indexArr);
}
