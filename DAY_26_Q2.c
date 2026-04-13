#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} MyLinkedList;

// Create list
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    return obj;
}

// Get value
int myLinkedListGet(MyLinkedList* obj, int index) {
    Node* temp = obj->head;
    int i = 0;

    while (temp) {
        if (i == index) return temp->val;
        temp = temp->next;
        i++;
    }
    return -1;
}

// Add at head
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
}

// Add at tail
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (!obj->head) {
        obj->head = newNode;
        return;
    }

    Node* temp = obj->head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

// Add at index
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* temp = obj->head;
    int i = 0;

    while (temp && i < index - 1) {
        temp = temp->next;
        i++;
    }

    if (!temp) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at index
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (!obj->head) return;

    if (index == 0) {
        Node* del = obj->head;
        obj->head = obj->head->next;
        free(del);
        return;
    }

    Node* temp = obj->head;
    int i = 0;

    while (temp->next && i < index - 1) {
        temp = temp->next;
        i++;
    }

    if (!temp->next) return;

    Node* del = temp->next;
    temp->next = del->next;
    free(del);
}
void myLinkedListFree(MyLinkedList* obj) {
    Node* temp = obj->head;

    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    free(obj);
}