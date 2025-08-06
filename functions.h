#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Function prototypes for array operations

void insert(int arr[], int *size, int element, int pos, int capacity);
void update(int arr[], int size, int pos, int newValue);
void delete(int arr[], int *size, int pos);
int search(int arr[], int size, int element);
void sortArray(int arr[], int size);
void splitArray(int arr[], int size, int arr1[], int *size1, int arr2[], int *size2);
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]);
void reverseArray(int arr[], int size);
void printArray(int arr[], int size);

#endif

