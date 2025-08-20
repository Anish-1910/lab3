#ifndef FUNCTIONS_H
#define FUNCTIONS_H


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;


Node* createNode(int data);
void insertAtBeginning(Node** head, int data);
void insertAtEnd(Node** head, int data);
void insertAtPosition(Node** head, int data, int pos);

void deleteAtBeginning(Node** head);
void deleteAtEnd(Node** head);
void deleteAtPosition(Node** head, int pos);

void displayList(Node* head);
void reverseList(Node** head);
void sortList(Node** head);
Node* search(Node* head, int key);

#endif

