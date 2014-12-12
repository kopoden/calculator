#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

//===================================================================================
#define MakeLogs //Turn on/off making logs. Put into comments to turn off all reports
//===================================================================================
#ifdef MakeLogs
#define safe_push( res )                                                            \
do {                                                                                \
    switch (res) {                                                                  \
                                                                                    \
        case OK:                                                                    \
                                                                                    \
            fprintf(logs, "%s == OK\n", __PRETTY_FUNCTION__);                       \
                                                                                    \
            break;                                                                  \
                                                                                    \
        case FULL:                                                                  \
                                                                                    \
            fprintf(logs, "%s == STACK IS FULL. CAN'T PUSH\n", __PRETTY_FUNCTION__);\
                                                                                    \
            return FULL;                                                            \
                                                                                    \
        case ERR_MEM:                                                               \
                                                                                    \
            fprintf(logs, "%s == MEMORY ALLOCATION ERROR\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            return ERR_MEM;                                                         \
                                                                                    \
        case INCORRECT_COUNTER:                                                     \
                                                                                    \
            fprintf(logs, "%s == INCORRECT STACK COUNTER\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            return INCORRECT_COUNTER;                                               \
                                                                                    \
        case NULL_DATA_POINTER:                                                     \
                                                                                    \
            fprintf(logs, "%s == NULL DATA POINTER\n", __PRETTY_FUNCTION__);        \
                                                                                    \
            return NULL_DATA_POINTER;                                               \
                                                                                    \
        case NOT_INITIALIZED:                                                       \
                                                                                    \
            fprintf(logs, "%s == STACK ISN'T INITIALIZED\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            return NOT_INITIALIZED;                                                 \
                                                                                    \
        default:                                                                    \
                                                                                    \
            fprintf(logs, "%s == UNKNOWN ERROR HAS OCCURED\n", __PRETTY_FUNCTION__);\
                                                                                    \
            return UNKNOWN_ERR;                                                     \
    }                                                                               \
                                                                                    \
} while (0);                                                                        \

#else
#define safe_push( res ) res
#endif
//===================================================================================
#ifdef MakeLogs
#define safe_pop( res )                                                             \
do {                                                                                \
    switch (res) {                                                                  \
                                                                                    \
        case OK:                                                                    \
                                                                                    \
            fprintf(logs, "%s == OK\n", __PRETTY_FUNCTION__);                       \
                                                                                    \
            break;                                                                  \
                                                                                    \
        case EMPTY:                                                                 \
                                                                                    \
            fprintf(logs, "%s == STACK IS EMPTY. CAN'T POP\n", __PRETTY_FUNCTION__);\
                                                                                    \
            return EMPTY;                                                           \
                                                                                    \
        case ERR_MEM:                                                               \
                                                                                    \
            fprintf(logs, "%s == MEMORY ALLOCATION ERROR\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            return ERR_MEM;                                                         \
                                                                                    \
        case INCORRECT_COUNTER:                                                     \
                                                                                    \
            fprintf(logs, "%s == INCORRECT STACK COUNTER\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            return INCORRECT_COUNTER;                                               \
                                                                                    \
        case NULL_DATA_POINTER:                                                     \
                                                                                    \
            fprintf(logs, "%s == NULL DATA POINTER\n", __PRETTY_FUNCTION__);        \
                                                                                    \
            return NULL_DATA_POINTER;                                               \
                                                                                    \
        case NOT_INITIALIZED:                                                       \
                                                                                    \
            fprintf(logs, "%s == STACK ISN'T INITIALIZED\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            return NOT_INITIALIZED;                                                 \
                                                                                    \
        default:                                                                    \
                                                                                    \
            fprintf(logs, "%s == UNKNOWN ERROR HAS OCCURED\n", __PRETTY_FUNCTION__);\
                                                                                    \
            return UNKNOWN_ERR;                                                     \
    }                                                                               \
                                                                                    \
} while (0);                                                                        \

#else
#define safe_pop( res ) res
#endif
//===================================================================================
#ifdef MakeLogs
#define check( res )                                                                \
do {                                                                                \
    switch (res) {                                                                  \
                                                                                    \
        case OK:                                                                    \
                                                                                    \
            break;                                                                  \
                                                                                    \
        case CALC_ERR:                                                              \
                                                                                    \
            fprintf(logs, "%s == CALCULATION ERROR\n", __PRETTY_FUNCTION__);        \
                                                                                    \
            return CALC_ERR;                                                        \
                                                                                    \
        case EMPTY:                                                                 \
                                                                                    \
            fprintf(logs, "%s == STACK IS EMPTY. CAN'T POP\n", __PRETTY_FUNCTION__);\
                                                                                    \
            break;                                                                  \
                                                                                    \
        case FULL:                                                                  \
                                                                                    \
            fprintf(logs, "%s == STACK IS FULL. CAN'T PUSH\n", __PRETTY_FUNCTION__);\
                                                                                    \
            return FULL;                                                            \
                                                                                    \
                                                                                    \
        case ERR_MEM:                                                               \
                                                                                    \
            fprintf(logs, "%s == MEMORY ALLOCATION ERROR\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            return ERR_MEM;                                                         \
                                                                                    \
        case INCORRECT_COUNTER:                                                     \
                                                                                    \
            fprintf(logs, "%s == INCORRECT STACK COUNTER\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            return INCORRECT_COUNTER;                                               \
                                                                                    \
        case NULL_DATA_POINTER:                                                     \
                                                                                    \
            fprintf(logs, "%s == NULL DATA POINTER\n", __PRETTY_FUNCTION__);        \
                                                                                    \
            return NULL_DATA_POINTER;                                               \
                                                                                    \
        case NOT_INITIALIZED:                                                       \
                                                                                    \
            fprintf(logs, "%s == STACK ISN'T INITIALIZED\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            return NOT_INITIALIZED;                                                 \
                                                                                    \
        case UNKNOWN_SYMBOL:                                                        \
                                                                                    \
            fprintf(logs, "%s == UNKNOWN SYMBOL DETECTED\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            return UNKNOWN_SYMBOL;                                                  \
                                                                                    \
        default:                                                                    \
                                                                                    \
            fprintf(logs, "%s == UNKNOWN ERROR HAS OCCURED\n", __PRETTY_FUNCTION__);\
                                                                                    \
            return UNKNOWN_ERR;                                                     \
    }                                                                               \
                                                                                    \
} while (0);                                                                        \

#else
#define check( res ) res
#endif
//===================================================================================

int commit_op (STACK_t* res, char op) {

    switch (op) {

        case '+':

            check(add(res));
            break;

        case '-':

            check(sub(res));
            break;

        case '*':

            check(mul(res));
            break;

        case '/':

            check(div(res));

            break;

        case 'S':

            check(Sin(res));
            break;

        case 'C':

            check(Cos(res));
            break;

        case 'T':

            check(Tan(res));
            break;

        case 'E':

            check(Exp(res));
            break;

        case '^':

            check(UpToDegree(res));
            break;

        default:

            return UNKNOWN_SYMBOL;
    }

    return OK;
}
//=============================================================================
int add (STACK_t* Stack) {

    data_t value1 = 0, value2 = 0, res = 0;

    safe_pop(pop(Stack, &value1));


    safe_pop(pop(Stack, &value2));

    res = value1 + value2;

    safe_push(push(Stack, res));

    return OK;
}
//=============================================================================
int sub (STACK_t* Stack) {

    data_t value1 = 0, value2 = 0, res = 0;

    safe_pop(pop(Stack, &value1));

    safe_pop(pop(Stack, &value2));

    res = value2 - value1;

    safe_push(push(Stack, res));

    return OK;

}
//=============================================================================
int mul (STACK_t* Stack) {

    data_t value1 = 0, value2 = 0, res = 0;

    safe_pop(pop(Stack, &value1));

    safe_pop(pop(Stack, &value2));

    res = value1 * value2;

    safe_push(push(Stack, res));

    return OK;

}
//=============================================================================
int div (STACK_t* Stack) {

    data_t value1 = 0, value2 = 0, res = 0;

    safe_pop(pop(Stack, &value1));

    safe_pop(pop(Stack, &value2));

    if (value1 == 0)
        return CALC_ERR;

    res = value2 / value1;

    safe_push(push(Stack, res));

    return OK;

}

//=============================================================
int Sin (STACK_t* Stack) {

    data_t value1 = 0;

    safe_pop(pop(Stack, &value1));

    value1 = sin(value1);

    safe_push(push(Stack, value1));

    return OK;
}
//=============================================================
int Cos (STACK_t* Stack) {

    data_t value1 = 0;

    safe_pop(pop(Stack, &value1));

    value1 = cos(value1);

    safe_push(push(Stack, value1));

    return OK;
}
//=============================================================
int Tan (STACK_t* Stack) {

    data_t value1 = 0;

    double DBL_EPSILON = 0.00000001; /// Neighborhood of zero

    safe_pop(pop(Stack, &value1));

    double check = cos(value1);

    if (check > (-DBL_EPSILON) && check < DBL_EPSILON)
        return CALC_ERR;

    value1 = tan(value1);

    safe_push(push(Stack, value1));

    return OK;
}
//=============================================================
int Exp (STACK_t* Stack) {

    data_t value1 = 0;

    safe_pop(pop(Stack, &value1));

    value1 = exp(value1);

    safe_push(push(Stack, value1));

    return OK;
}
//=============================================================================
int UpToDegree (STACK_t* Stack) {

    data_t value = 0;

    data_t degree = 0;

    safe_pop(pop(Stack, &degree));

    safe_pop(pop(Stack, &value));

    value = pow(value, degree);

    safe_push(push(Stack, value));

    return OK;
}
//=============================================================================
int cnt (FILE* source, STACK_t* ans, data_t* res) {

    long int length_of_file = 0;

    fseek(source, 0, SEEK_END);

    length_of_file = ftell(source);

    fseek(source, 0, SEEK_SET);

    while (ftell(source) < length_of_file) {

        data_t value = 0;

        char op = 0;

        while ((op >= 0 && op <= 13) || op == 32) {

            op = getc(source);

            if (op >= '0' && op <= '9') {

                char op1 = op;
                ungetc(op1, source);

            }

        }

        if ( op < '0' || op > '9') {

            int check = commit_op(ans, op);

            if (check != OK)
                return check;
        }

        else {

            fscanf(source, "%lg", &value);

            safe_push(push(ans, value));

        }
    }

    safe_pop(pop(ans, res));

    if (stack_ok(ans) != EMPTY)
        return INCORRECT_EXPRESSION;

    return OK;
}

//=============================================================================

