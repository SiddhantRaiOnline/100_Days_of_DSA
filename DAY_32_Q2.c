#define SIZE 10000

typedef struct {
    int stack[SIZE];
    int minStack[SIZE];
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;

    if (obj->top == 0)
        obj->minStack[obj->top] = val;
    else {
        int min = obj->minStack[obj->top - 1];
        obj->minStack[obj->top] = (val < min) ? val : min;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0)
        obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

//  REQUIRED
void minStackFree(MinStack* obj) {
    free(obj);
}