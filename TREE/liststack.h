typedef int Data;

typedef struct _node{
    Data data;
    struct _node * next;
}Node;

typedef struct stack{
    Node * head;
}ListStack;

typedef ListStack stack;

void StackInit(stack * pstack);
int SIsEmpty(stack * pstack);

void SPush(stack * pstack,Data data);
Data SPop(stack * pstack);
Data SPeek(stack * pstack);
