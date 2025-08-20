#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}


void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}


void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}


void insertAtPosition(Node** head, int data, int pos) {
    if (pos <= 1) {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        insertAtEnd(head, data);
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}


void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}


void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head = NULL;
    free(temp);
}


void deleteAtPosition(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    if (pos == 1) {
        deleteAtBeginning(head);
        return;
    }
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}


void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


void reverseList(Node** head) {
    Node* temp = NULL;
    Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        *head = temp->prev;
}


void sortList(Node** head) {
    if (*head == NULL) return;
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = *head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


Node* search(Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return head;
        head = head->next;
    }
    return NULL;
}

