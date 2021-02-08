#include<stdio.h>
#include<stdlib.h>

typedef int Data;

typedef struct _node{
    Data data;
    struct _node * prev;
    struct _node * next;
}Node;

typedef struct _dlDeque{
    Node * head;
    Node * tail;
}DLDeque;

typedef DLDeque Deque;

typedef Deque Queue;

void DequeInit(Deque * pdeq){
    pdeq->head=NULL;
    pdeq->tail=NULL;

}


int DQIsEmpty(Deque * pdeq){
    if(pdeq->head == NULL){
        return 1;
    }
    else
        return 0;
}

void DQAddFirst(Deque * pdeq,Data data){
    Node * newNode=(Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pdeq->head;

    if(DQIsEmpty(pdeq))
        pdeq->tail=newNode;
    else
        pdeq->head->prev=newNode;

    newNode->prev=NULL;
    pdeq->head=newNode;
}

void DQAddLast(Deque * pdeq,Data data){
    Node * newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;

    newNode->prev = pdeq->tail;

    if(DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;

    newNode->next = NULL;
    pdeq->tail=newNode;
}

Data DQRemoveFirst(Deque * pdeq){
    Node * rnode = pdeq->head;
    Data rdata;

    rdata = pdeq->head->data;

    pdeq->head = pdeq->head->next;
    free(rnode);

    if(pdeq->head == NULL)
        pdeq->tail = NULL;
    else   
        pdeq->head->prev=NULL;

    return rdata;
}

Data DQRemoveLast(Deque * pdeq){
    Node * rnode = pdeq->tail;
    Data rdata = pdeq->tail->data;

    pdeq->tail=pdeq->tail->prev;
    free(rnode);

    if(pdeq->tail == NULL)
        pdeq->head = NULL;
    else   
        pdeq->tail->next=NULL;

    return rdata;
}

Data DQGetFirst(Deque * pdeq){
    return pdeq->head->data;
}

Data DQGetLast(Deque * pdeq){
    return pdeq->tail->data;
}

void QueueInit(Queue * pq){
   DequeInit(pq);
}

int QIsEmpty(Queue * pq){
    return DQIsEmpty(pq);
}

void Enqueue(Queue * pq,Data data){
    DQAddLast(pq,data);
}

Data Dequeue(Queue * pq){
    return DQGetLast(pq);
}

Data QPeek(Queue * pq){
    return DQGetFirst(pq);
}

int main(){
    Queue q;
    QueueInit(&q);

    Enqueue(&q,1);
    Enqueue(&q,2);
    Enqueue(&q,3);
    Enqueue(&q,4);
    Enqueue(&q,5);

    while(!QIsEmpty(&q))
        printf("%d ",Dequeue(&q));
}