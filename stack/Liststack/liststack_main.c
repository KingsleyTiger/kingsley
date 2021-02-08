#include<stdio.h>

int main(){
    Stack stack;
    StackInit(&stack);

    SPush(&stack,1);
    SPush(&stack,2);
    SPush(&stack,3);
    SPush(&stack,4);
    SPush(&stack,5);

    while(!IsEmpty(&stack)){
        printf("%d",SPop(&stack));
    }
}