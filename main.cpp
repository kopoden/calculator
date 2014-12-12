#include "calc.h"
//===================================================================================
#define MakeLogs //Turn on/off making logs. Put into comments to turn off all reports
//===================================================================================
#ifdef MakeLogs

#define msg( error )                                                                \
do {                                                                                \
    switch (error) {                                                                \
                                                                                    \
        case OK:                                                                    \
                                                                                    \
            fprintf(logs, "%s == OK\n", __PRETTY_FUNCTION__);                       \
            break;                                                                  \
                                                                                    \
        case CALC_ERR:                                                              \
                                                                                    \
            fprintf(logs, "%s == CALCULATION ERROR\n", __PRETTY_FUNCTION__);        \
                                                                                    \
            printf("CALCULATION ERROR\n");                                          \
                                                                                    \
            stack_dump(&Stack, dump);                                               \
                                                                                    \
            return CALC_ERR;                                                        \
                                                                                    \
        case INCORRECT_EXPRESSION:                                                  \
                                                                                    \
            fprintf(logs, "%s == INCORRECT EXPRESSION\n", __PRETTY_FUNCTION__);     \
                                                                                    \
            printf("INCORRECT EXPRESSION\n");                                       \
                                                                                    \
            stack_dump(&Stack, dump);                                               \
                                                                                    \
            return INCORRECT_EXPRESSION;                                            \
                                                                                    \
        case EMPTY:                                                                 \
                                                                                    \
            fprintf(logs, "%s == STACK IS EMPTY. CAN'T POP\n", __PRETTY_FUNCTION__);\
                                                                                    \
            printf("STACK IS EMPTY. CAN'T POP\n");                                  \
                                                                                    \
            stack_dump(&Stack, dump);                                               \
                                                                                    \
            return EMPTY;                                                           \
                                                                                    \
        case FULL:                                                                  \
                                                                                    \
            fprintf(logs, "%s == STACK IS FULL. CAN'T PUSH\n", __PRETTY_FUNCTION__);\
                                                                                    \
            printf("STACK IS FULL. CAN'T PUSH\n");                                  \
                                                                                    \
            stack_dump(&Stack, dump);                                               \
                                                                                    \
            return FULL;                                                            \
                                                                                    \
                                                                                    \
        case ERR_MEM:                                                               \
                                                                                    \
            fprintf(logs, "%s == MEMORY ALLOCATION ERROR\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            printf("MEMORY ALLOCATION ERROR\n");                                    \
                                                                                    \
            stack_dump(&Stack, dump);                                               \
                                                                                    \
            return ERR_MEM;                                                         \
                                                                                    \
        case INCORRECT_COUNTER:                                                     \
                                                                                    \
            fprintf(logs, "%s == INCORRECT STACK COUNTER\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            printf("INCORRECT STACK COUNTER\n");                                    \
                                                                                    \
            stack_dump(&Stack, dump);                                               \
                                                                                    \
            return INCORRECT_COUNTER;                                               \
                                                                                    \
        case NULL_DATA_POINTER:                                                     \
                                                                                    \
            fprintf(logs, "%s == NULL DATA POINTER\n", __PRETTY_FUNCTION__);        \
                                                                                    \
            printf("NULL DATA POINTER\n");                                          \
                                                                                    \
            stack_dump(&Stack, dump);                                               \
                                                                                    \
            return NULL_DATA_POINTER;                                               \
                                                                                    \
        case NOT_INITIALIZED:                                                       \
                                                                                    \
            fprintf(logs, "%s == STACK ISN'T INITIALIZED\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            printf("STACK ISN'T INITIALIZED\n");                                    \
                                                                                    \
            stack_dump(&Stack, dump);                                               \
                                                                                    \
            return NOT_INITIALIZED;                                                 \
                                                                                    \
        case UNKNOWN_SYMBOL:                                                        \
                                                                                    \
            fprintf(logs, "%s == UNKNOWN SYMBOL DETECTED\n", __PRETTY_FUNCTION__);  \
                                                                                    \
            printf("UNKNOWN SYMBOL DETECTED\n");                                    \
                                                                                    \
            return UNKNOWN_SYMBOL;                                                  \
                                                                                    \
        default:                                                                    \
                                                                                    \
            fprintf(logs, "%s == UNKNOWN ERROR HAS OCCURED\n", __PRETTY_FUNCTION__);\
                                                                                    \
            printf("UNKNOWN ERROR HAS OCCURED\n");                                  \
                                                                                    \
            stack_dump(&Stack, dump);                                               \
                                                                                    \
            return UNKNOWN_ERR;                                                     \
    }                                                                               \
                                                                                    \
} while (0);                                                                        \

#else
#define msg( error ) error
#endif
//================================================
FILE* logs = NULL; //Global
//================================================
int main() {

    logs = fopen("logs.txt", "w");
   
   if (logs == NULL) {
      
      printf("CAN'T CREATE LOG FILE\n");
      
      return 0;
   }
   
    FILE* source = fopen("expression.txt", "r");
    
    if (source == NULL) {
      
      printf("CAN'T FIND FILE WITH EXPRESSSION\n");
      
      fprintf(logs, "CAN'T FIND FILE WITH EXPRESSSION\n");
      
      return 0;
   }

    FILE* dump = fopen("dump.txt", "w");

    STACK_t Stack = {};

    stack_ctor(&Stack);

    stack_resize(&Stack, MAX_STACK_SIZE);

    double res = 0;

    msg(cnt(source, &Stack, &res));
   
    printf("\n%lg\n\n", res);

    stack_dtor(&Stack);

    fclose(source);
    fclose(logs);
    fclose(dump);

    return 0;
}
