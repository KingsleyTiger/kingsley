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

void SPush(Stack * pstack,Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);
