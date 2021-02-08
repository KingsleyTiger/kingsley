#include<stdio.h>
#include"stack.h"

void StackInit(Stack * pstack){
    pstack->topindex = -1;
}

int SIsEmpty(Stack * pstack){
    if(pstack->topindex == -1){
        return TRUE;
    }
    else
        return FALSE;
}

void SPush(Stack * pstack,Data data){
    pstack->topindex += 1;
    pstack->stackArr[pstack->topindex] = data;
}

Data SPop(Stack * pstack){
    int rIdx;
    if(SIsEmpty(pstack)){
        printf("Stack Is Empty");
        exit(-1);
    }
    rIdx = pstack->topindex;
    pstack->topindex -= 1;
    return pstack->stackArr[rIdx];
}

Data SPeek(Stack * pstack){

    if(SIsEmpty(pstack)){
        printf("Stack Is Empty");
        exit(-1);
    }

    return pstack->stackArr[pstack->topindex];
}