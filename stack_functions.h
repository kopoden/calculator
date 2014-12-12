#ifndef _STACK_FUNCTIONS_H_INCL_
#define _STACK_FUNCTIONS_H_INCL_

#include <stdlib.h>
#include <stdio.h>

enum stack_errors {
    OK = 0,                             ///< Successful action.
    EMPTY = 1,                          ///< Stack is empty.
    FULL = 2,                           ///< Stack is full.
    ERR_MEM = 3,                        ///< There is no enough memory to allocate.
    INCORRECT_COUNTER = 4,              ///< Counter points at the segment is out of stack.
    NULL_DATA_POINTER = 5,              ///< Pointer of stack array = NULL.
    NOT_INITIALIZED = 6,                ///< Stack structure was not initialized.
    INCORRECT_POSITION_FOR_INSERT = 7,   ///< Incorrect insert operation.
    UNKNOWN_ERR = 8
};

//==================================================================
/*! \struct STACK_t

    \param  stack_arr   Stack pointer
    \param  counter     Current number of elements in stack
*/

typedef double data_t;

struct STACK_t {
    data_t* stack_arr;
    int counter;
    int max_size;
};
//==================================================================
/*! \fn     int stack_ctor (STACK_t* new_stack);
    \brief  Creates new stack.
*/
int stack_ctor ( STACK_t* new_stack );
//==================================================================

//==================================================================
/*! \fn     int push (STACK_t* Stack, data_t value);
    \brief  Pushes the value onto the stack.

    \param      Stack       Stack pointer
    \param      value     Value to be pushed
*/
int push (STACK_t* Stack, data_t value);
//==================================================================

//==================================================================
/*! \fn     int pop (STACK_t* Stack, data_t* value);
    \brief  Gets the number from the stack.

    \param      Stack       Stack pointer
*/
int pop (STACK_t* Stack, data_t* value);
//==================================================================
//==================================================================
int stack_resize (STACK_t* Stack, int Size);
//==================================================================
//==================================================================
/*! \fn     int insrt (STACK_t* Stack, int position, data_t element);
    \brief  Puts the number in any part of the stack.

    \param      Stack       Stack pointer
    \param      position    Position to insert
    \param      element     Value to be pushed
*/
int insrt (STACK_t* Stack, int position, data_t element);
//==================================================================

//==================================================================
/*! \fn     int stack_ok (STACK_t* Stack);
    \brief  Checks stack's validity.

    \param      Stack       Stack pointer
*/
int stack_ok (STACK_t* Stack);
//==================================================================

//==================================================================
/*! \fn     int stack_dtor(STACK_t* Stack);
    \brief  Erases the content of stack.

    \param      Stack       Stack pointer
*/
int stack_dtor(STACK_t* Stack);
//==================================================================
void stack_dump(STACK_t* Stack, FILE* dump);
//==================================================================
#endif // _STACK_FUNCTIONS_H_INCL_
