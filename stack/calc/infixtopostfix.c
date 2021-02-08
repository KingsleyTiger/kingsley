#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct node{
    int data;
    struct node * next;
}Node;

typedef struct _stack{
    Node * head;
}ListStack;
typedef ListStack stack;
typedef int Data;

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

Data SPop(stack * pstack){
    Data rdata;
    Node * rnode;

    if(SIsEmpty(pstack)){
        printf("Stack Memory Error");
        exit(0);
    }

    rdata = pstack->head->data;
    rnode = pstack->head;

    pstack->head = pstack->head->next;
    free(rnode);

    return rdata;
}

Data SPeek(stack * pstack){
    if(SIsEmpty(pstack)){
        printf("Stack Memory Error");
        exit(0);
    }
    return pstack->head->data;
}

int GetOpPrec(char op){
    switch(op){
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
            return 1;
    }
    return -1;
}

int WhoPrecOp(char op1,char op2){
    int op1prec = GetOpPrec(op1);
    int op2prec = GetOpPrec(op2);

    if(op1prec > op2prec)
        return 1;
    if(op1prec < op2prec)
        return -1;
    else
        return 0;
}

void ConvToRPNExp(char exp[]){
    stack st;
    int explen = strlen(exp);
    char * convExp = (char*)malloc(explen+1);

    int i,idx=0;
    char tok,popOp;

    memset(convExp,0,explen+1);
    StackInit(&st);

    for(i=0;i<explen;i++){
        tok = exp[i];
        if(isdigit(tok)){
            convExp[idx++] = tok;
        }
        else{
            switch(tok){
                case '(':
                    SPush(&st,tok);
                    break;
                
                case ')':
                    while(1){
                        popOp = SPop(&st);
                        if(popOp == '(')
                            break;
                        convExp[idx++] = popOp;
                    }
                    break;
                
                case '+': case '-':
                case '*': case '/':
                    while(!SIsEmpty(&st) && WhoPrecOp(SPeek(&st),tok) >= 0){
                        convExp[idx++] = SPop(&st);
                    }
                    SPush(&st,tok);
                    break;
            }
        }
    }
    while(!SIsEmpty(&st))
        convExp[idx++] = SPop(&st);

    strcpy(exp,convExp);
    free(convExp);
}

int main(){
    
}