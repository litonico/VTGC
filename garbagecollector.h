#ifndef garbagecollector_h
#define garbagecollector_h

void markAll(VM* vm);

void mark(Object* object);

void sweep(VM* vm);

void gc(VM* vm);

#endif
