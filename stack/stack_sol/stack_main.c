#include<stdio.h>

typedef int Data;

typedef struct _arraystack{
    Data stackArr[100];
    int topindex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void  SPush(Stack * pstack,Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

void StackInit(Stack * pstack){
    pstack->topindex = -1;
}

int SIsEmpty(Stack * pstack){
    if(pstack->topindex == -1){
        return 1;
    }
    else
        return 0;
}

void SPush(Stack * pstack,Data data){
    pstack->topindex += 1;
    pstack->stackArr[pstack->topindex] = data;
}

Data SPop(Stack * pstack){
    int rIdx;
    if(SIsEmpty(pstack)){
        printf("Stack Is Empty");
    }
    rIdx = pstack->topindex;
    pstack->topindex -= 1;
    return pstack->stackArr[rIdx];
}

Data SPeek(Stack * pstack){

    if(SIsEmpty(pstack)){
        printf("Stack Is Empty");
    }

    return pstack->stackArr[pstack->topindex];
}

int main(){
    Stack stack;
    StackInit(&stack);
    for(int i=1;i<6;i++){
        SPush(&stack,i);
    }
    while(!SIsEmpty(&stack)){
        printf("%d ",SPop(&stack));
    }
}