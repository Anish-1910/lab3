#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Node* head = NULL;
    int choice, data, pos, key;
    
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Search\n");
        printf("8. Sort\n");
        printf("9. Reverse\n");
        printf("10. Display\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(&head, data, pos);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &key);
                if (search(head, key))
                    printf("Element found!\n");
                else
                    printf("Element not found!\n");
                break;
            case 8:
                sortList(&head);
                break;
            case 9:
                reverseList(&head);
                break;
            case 10:
                displayList(head);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

