#include <stdlib.h>
#include "VM.h"

VM* newVM() {
    VM* vm = malloc(sizeof(VM));
    vm->stackSize = 0;
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
    Object* object = malloc(sizeof(Object));
    object->type type;
    return object;
}

