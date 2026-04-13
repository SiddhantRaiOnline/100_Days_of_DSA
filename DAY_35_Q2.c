#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10000

typedef struct {
    int s1[SIZE];
    int s2[SIZE];
    int top1;
    int top2;
} MyQueue;

// Initialize
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

// Push → always in stack1
void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
}

// Helper: transfer if needed
void transfer(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->s2[++obj->top2] = obj->s1[obj->top1--];
        }
    }
}

// Pop
int myQueuePop(MyQueue* obj) {
    transfer(obj);
    return obj->s2[obj->top2--];
}

// Peek
int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    return obj->s2[obj->top2];
}

// Empty
bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

// Free
void myQueueFree(MyQueue* obj) {
    free(obj);
}