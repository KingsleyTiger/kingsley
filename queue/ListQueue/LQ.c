#include<stdio.h>
#include<stdlib.h>

typedef int Data;

typedef struct _node{
    Data data;
    struct _node * next;
}Node;

typedef struct queue{
    Node * front;
    Node * rear;
}Que;

void QInit(Que * pq){
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Que * pq){
    if(pq->front == NULL)
        return 1;
    else
        return 0;
}

void Enqueue(Que * pq,Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if(QIsEmpty(pq)){
        pq->front = newNode;
        pq->rear = newNode;
    }
    
    else{
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Que * pq){
        if(QIsEmpty(pq)){
            printf("Queue memory error");
            exit(0);
        }

        Data rdata=pq->front->data;
        Node * delNode = pq->front;
        
        pq->front = pq->front->next;
        
        free(delNode);
        
        return rdata;
}

int main(){
    Que Q;
    QInit(&Q);

    Enqueue(&Q,1);
    Enqueue(&Q,2);
    Enqueue(&Q,3);
    Enqueue(&Q,4);
    Enqueue(&Q,5);

    while(!QIsEmpty(&Q)){
        printf("%d ",Dequeue(&Q));
    }
}