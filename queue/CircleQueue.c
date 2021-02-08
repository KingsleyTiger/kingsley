#include<stdio.h>
#include<stdlib.h>

#define LEN 100
typedef int Data;

typedef struct _cQueue{
    int front;
    int rear;
    Data queArr[LEN];
}CQueue;

typedef CQueue Queue;


void QueueInit(Queue *pq){
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue * pq){
    if(pq->front == pq->rear)
        return 1;
    else return 0;
}

int NextPosIdx(int pos){
    if(pos == LEN - 1)
        return 0;
    else
        return pos+1;
}

void Enqueue(Queue *pq,Data data){
    if(NextPosIdx(pq->rear) == pq->front)){
        printf("Queue Memory Error");
        exit(0);
    }
    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear]=data;
}

Data Dequeue(Queue * pq){
    if(QIsEmpty(pq)){
        printf("Queue memory error");
        exit(0);
    }
    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

Data Qpeek(Queue * pq){
    if(QIsEmpty(pq)){
        printf("Queue memory error");
        exit(0);
    }
    return pq->queArr[NextPosIdx(pq->front)];
}

