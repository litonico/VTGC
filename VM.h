#ifndef VM_h
#define VM_h
#define STACK_MAX 256

#include "language_h"

typedef struct {
    int numObjects;
    int maxObjects;

    Object* firstObject;

    Object* stack[STACK_MAX];
    int stackSize;
} VM;


VM* newVM();

void push(VM* vm, Object* value);

Object* pop(VM* vm);

Object* newObject(VM* vm, ObjectType type);

#endif
