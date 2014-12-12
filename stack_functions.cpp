#include "stack_functions.h"

//===========================================================
int stack_ctor ( STACK_t* new_stack ) {

    if (new_stack == NULL)
        return NOT_INITIALIZED;

    new_stack->stack_arr = NULL; // Empty stack
    new_stack->counter = 0;      // Empty stack. Counter points to the zero element
    new_stack->max_size = 0;

    return OK;
}
//======================================================

//======================================================
int push (STACK_t* Stack, data_t value) {

    int check = stack_ok(Stack);

    if (check != OK && check != EMPTY)
        return check;

    Stack->counter++;
    Stack->stack_arr[Stack->counter - 1] = value;

    return OK;
}
//======================================================

//======================================================
int pop (STACK_t* Stack, data_t* value) {

    int check = stack_ok(Stack);

    if (check != FULL && check != OK) {
        return check;
    }

    Stack->counter--;

    if (value == NULL)
        return OK;

    *value = Stack->stack_arr[Stack->counter];

    return OK;
}
//======================================================
int stack_resize (STACK_t* Stack, int Size) {

    if (Stack == NULL)
        return NOT_INITIALIZED;

    if (Stack->stack_arr == NULL && (Stack->counter != 0 || Stack->max_size != 0))
        return NULL_DATA_POINTER;

    if (Stack->stack_arr == NULL)
        Stack->stack_arr = (data_t*) calloc (Size, sizeof(data_t));
    else
        Stack->stack_arr = (data_t*) realloc (Stack->stack_arr, sizeof(data_t) * Size);

    if (Stack->stack_arr == NULL && Size != 0) {
        return ERR_MEM;
    }

    Stack->max_size = Size;

    return OK;
}
//======================================================
//======================================================
int insrt (STACK_t* Stack, int position, data_t value) {

    if ((position < 0) && (position >= Stack->max_size))
        return INCORRECT_POSITION_FOR_INSERT;

    int check = stack_ok(Stack);

    if (check != OK && check != EMPTY)
        return check;

    Stack->counter++;

    for (int END = Stack->counter - 1; END > position; END--)
        Stack->stack_arr[END] = Stack->stack_arr[END - 1];

    Stack->stack_arr[position] = value;

    return OK;
}
//======================================================

//======================================================
int stack_ok (STACK_t* Stack) {

    if (Stack == NULL)
        return NOT_INITIALIZED;

    if (Stack->stack_arr == NULL)
        return NULL_DATA_POINTER;

    if ((Stack->counter < 0) || (Stack->counter > Stack->max_size))
        return INCORRECT_COUNTER;

    if (Stack->counter == Stack->max_size)
        return FULL;

    if (Stack->counter == 0)
        return EMPTY;   //Stack is empty(can't pop, but still can push).

    return OK;      //Stack is fully workable.
}
//======================================================

//======================================================

int stack_dtor(STACK_t* Stack) {

    if (Stack == NULL)
        return NOT_INITIALIZED;

    free(Stack->stack_arr);

    Stack->stack_arr = NULL;
    Stack->counter = 0;
    Stack->max_size = 0;

    return OK;
}
//=====================================================
void stack_dump(STACK_t* Stack, FILE* dump) {

    if (Stack == NULL) {

        fprintf(dump, "*********************STACK DUMP******************************\nCOUNTER: %d\nMAX SIZE: %d\n\
               IMPOSSIBLE TO DUMP STACK. STACK POINTER = NULL. DATA LOCATION UNDEFINED.\n\
               *************************************************************\n\n",                        \
              Stack->counter, Stack->max_size);

        return;
    }

    if (Stack->stack_arr == NULL) {

        fprintf(dump, "*********************STACK DUMP******************************\nCOUNTER: %d\nMAX SIZE: %d\n\
               IMPOSSIBLE TO DUMP STACK. STACK DATA POINTER = NULL. DATA LOCATION UNDEFINED.\n\
               *************************************************************\n\n",                        \
              Stack->counter, Stack->max_size);

        fprintf(dump, "\n*************************************************************\n\n");

        return;
    }

    fprintf(dump, "*********************STACK DUMP******************************\nCOUNTER: %d\nMAX SIZE: %d\nSTACK:", \
            Stack->counter, Stack->max_size);

    for (int i = 0; i < Stack->counter; i++)
        fprintf(dump, " | %lg |", Stack->stack_arr[i]);

    fprintf(dump, "\n*************************************************************\n\n");
}

