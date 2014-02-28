#ifndef language_h
#define language_h

typedef enum {
    OBJ_INT,
    OBJ_PAIR
} ObjectType;

typedef struct sObject {
    struct sObject* next;

    unsigned char marked;

    ObjectType type;

    union {
        // OBJ_INT
        int value;

        // OBJ_PAIR
        struct {
            struct sObject* head;
            struct sObject* tail;
        }
    }
} Object; 

#endif
