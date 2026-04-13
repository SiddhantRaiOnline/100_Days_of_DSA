#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Get length
int length(struct Node* head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection (by value match)
int findIntersection(struct Node* h1, struct Node* h2) {
    int l1 = length(h1);
    int l2 = length(h2);

    int diff = abs(l1 - l2);

    // Move pointer of longer list
    if(l1 > l2) {
        for(int i = 0; i < diff; i++) h1 = h1->next;
    } else {
        for(int i = 0; i < diff; i++) h2 = h2->next;
    }

    // Traverse together
    while(h1 && h2) {
        if(h1->data == h2->data) {
            return h1->data;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    return -1;
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    int result = findIntersection(list1, list2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}