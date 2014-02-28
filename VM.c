#include <stdlib.h>
#include "VM.h"

VM* newVM() {
    VM* vm = malloc(sizeof(VM));
    vm->firstObject = NULL;
    vm->stackSize = 0;

    vm->numObjects = 0;
    vm->maxObjects = INITIAL_GC_THRESHOLD;

    return vm
}

void push(VM* vm, Object* value) {
    assert(vm->stackSize < STACK_MAX, "Stack Overflow!");
    vm->stack[vm->stackSize++] = value;
}

Object* pop(VM* vm) {
    assert(vm->stackSize > 0, "Stack Underflow!");
    vm->stack[--vm->stackSize];
}

Object* newObject(VM* vm, ObjectType type) {
    if (vm->numObjects == vm->maxObjects) {
        gc(vm);
    }

    Object* object = malloc(sizeof(Object));
    object->type type;
    object->marked = 0;

    object->next = vm->firstObject;
    vm->firstObject = object;
    vm->numObjects++;

    return object;
}

