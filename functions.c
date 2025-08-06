#include <stdio.h>
#include "functions.h"

void insert(int arr[], int *size, int element, int pos, int capacity) {
    if (*size >= capacity) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    if (pos < 1 || pos > *size + 1) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
    (*size)++;
}

void update(int arr[], int size, int pos, int newValue) {
    if (pos < 1 || pos > size) {
        printf("Invalid position.\n");
        return;
    }
    arr[pos - 1] = newValue;
}

void delete(int arr[], int *size, int pos) {
    if (pos < 1 || pos > *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

void sortArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void splitArray(int arr[], int size, int arr1[], int *size1, int arr2[], int *size2) {
    *size1 = size / 2;
    *size2 = size - *size1;
    for (int i = 0; i < *size1; i++) {
        arr1[i] = arr[i];
    }
    for (int i = 0; i < *size2; i++) {
        arr2[i] = arr[i + *size1];
    }
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < size1) merged[k++] = arr1[i++];
    while (j < size2) merged[k++] = arr2[j++];
}

void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

