#include<stdio.h>
#include<stdlib.h>
#include "liststack.h"

void StackInit(stack * pstack){
    pstack->head = NULL;
}

int SIsEmpty(stack * pstack){
    if(pstack->head == NULL)
        return 1;
    else
        return 0;
}

void SPush(stack * pstack,Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = pstack->head;

    pstack->head = newNode;
}

Data SPop(Stack * pstack){
    Data rdata;
    Node * rnode;

    if(SIsEmpty(pstack)){
        printf("Stack Memory Error");
        exit(0);
    }

    rdata = pstack->head->data;
    rnode = pstack->head;

    pstack->head = pstack->head->data;
    free(rnode);

    return rdata;
}

Data SPeek(Stack * pstack){
    if(SIsEmpty(pstack)){
        printf("Stack Memory Error");
        exit(0);
    }
    return pstack->head->data;
}
