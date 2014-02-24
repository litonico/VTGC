#define STACK_MAX 256

typedef struct {
    Object* stack[STACK_MAX];
    int stackSize;
} VM;
