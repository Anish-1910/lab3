#include <stdio.h>
#include "functions.h"

#define CAPACITY 100

int main() {
    int arr[CAPACITY];
    int size = 0;
    int choice, element, pos, newValue;
    int arr1[CAPACITY], arr2[CAPACITY], size1, size2;
    int merged[2*CAPACITY];

    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert element\n");
        printf("2. Update element\n");
        printf("3. Delete element\n");
        printf("4. Search element\n");
        printf("5. Sort array\n");
        printf("6. Split array into two\n");
        printf("7. Merge two arrays\n");
        printf("8. Reverse array\n");
        printf("9. Display array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert (1 to %d): ", size + 1);
                scanf("%d", &pos);
                insert(arr, &size, element, pos, CAPACITY);
                break;
            case 2:
                if (size == 0) {
                    printf("Array is empty. Nothing to update.\n");
                    break;
                }
                printf("Enter position to update (1 to %d): ", size);
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                update(arr, size, pos, newValue);
                break;
            case 3:
                if (size == 0) {
                    printf("Array is empty. Nothing to delete.\n");
                    break;
                }
                printf("Enter position to delete (1 to %d): ", size);
                scanf("%d", &pos);
                delete(arr, &size, pos);
                break;
            case 4:
                if (size == 0) {
                    printf("Array is empty. Nothing to search.\n");
                    break;
                }
                printf("Enter element to search: ");
                scanf("%d", &element);
                pos = search(arr, size, element);
                if (pos == -1)
                    printf("Element %d not found in the array.\n", element);
                else
                    printf("Element %d found at position %d.\n", element, pos + 1);
                break;
            case 5:
                if (size == 0) {
                    printf("Array is empty. Nothing to sort.\n");
                    break;
                }
                sortArray(arr, size);
                printf("Array sorted successfully.\n");
                break;
            case 6:
                if (size == 0) {
                    printf("Array is empty. Nothing to split.\n");
                    break;
                }
                splitArray(arr, size, arr1, &size1, arr2, &size2);
                printf("First half: ");
                printArray(arr1, size1);
                printf("Second half: ");
                printArray(arr2, size2);
                break;
            case 7:
                if (size == 0) {
                    printf("Main array is empty. Please insert elements first.\n");
                    break;
                }
                printf("Enter size of second array (max %d): ", CAPACITY);
                scanf("%d", &size2);
                if (size2 < 1 || size2 > CAPACITY) {
                    printf("Invalid size.\n");
                    break;
                }
                printf("Enter elements of second array:\n");
                for (int i = 0; i < size2; i++) {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &arr2[i]);
                }
                sortArray(arr, size);
                sortArray(arr2, size2);
                mergeArrays(arr, size, arr2, size2, merged);
                printf("Merged array: ");
                printArray(merged, size + size2);
                break;
            case 8:
                if (size == 0) {
                    printf("Array is empty. Nothing to reverse.\n");
                    break;
                }
                reverseArray(arr, size);
                printf("Array reversed successfully.\n");
                break;
            case 9:
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Current array: ");
                    printArray(arr, size);
                }
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

