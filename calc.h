#ifndef _CALC_H_INCL_
#define _CALC_H_INCL_

#include <math.h>
#include "stack_functions.h"

extern FILE* logs;

const int MAX_STACK_SIZE = 10000;

enum errors {
    CALC_ERR = 9,               ///Tells about calculation error.
    INCORRECT_EXPRESSION = 10,
    UNKNOWN_SYMBOL = 11
};

//=============================================================
int commit_op (STACK_t* ans, char op);
//=============================================================
int add (STACK_t* Stack);
//=============================================================
int sub (STACK_t* Stack);
//=============================================================
int mul (STACK_t* Stack);
//=============================================================
int div (STACK_t* Stack);
//=============================================================
int Sin (STACK_t* Stack);
//=============================================================
int Cos (STACK_t* Stack);
//=============================================================
int Tan (STACK_t* Stack);
//=============================================================
int Exp (STACK_t* Stack);
//=============================================================
int UpToDegree (STACK_t* Stack);
//=============================================================
int cnt (FILE* source, STACK_t* ans, data_t* res);
//=============================================================
void Exit (STACK_t* Stack);
//=============================================================
#endif // _CALC_H_INCL_
