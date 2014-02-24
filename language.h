typedef enum {
    OBJ_INT,
    OBJ_PAIR
} ObjectType;

typedef struct sObject {
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

