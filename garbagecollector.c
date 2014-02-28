#include "garbagecollector.h"
#include "language.h"
#include "VM.h"

void markAll(VM* vm) {
    for (int i = 0; i < vm->stackSize; i++){
        mark(vm->stack[i]);
    }
}

void mark(Object* object) {
    if (object->marked) {
        return;
    }
    object->marked = 1;

    if (object-> == OBJ_PAIR) {
        mark(object->head);
        mark(object->tail);
    }
    
}

void sweep(VM* vm) {
    Object** object = &vm->firstObject;
    while (*object) {
        if (!(*object)->marked) {
            Object* unreached = *object;

            *object = unreached->next;
            free(unreached);
            vm->numObjects--;
        }
        else {
            (*object)->marked = 0;
            object = &(*object)->next;
        }
    }
}

void gc(VM* vm) {
    int numObjects = vm->numObjects;

    markAll(vm);
    sweep(vm);

    vm->maxObjects = vm->numObjects * 2;
}

