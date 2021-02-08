#define STACK_LEN 100
#include "stack.c"

typedef int Data;

typedef struct _arraystack{
    Data stackArr[STACK_LEN];
    int topindex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void  SPush(Stack * pstack,Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);