#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define CUS_COME_TERM   15

#define CHE 0
#define BUL 1
#define DUB 2

#define CHE_T 12
#define BUL_T 15
#define DUB_T 24

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
    int makeproc=0;
    int cheord=0,bulord=0,dubord=0;
    int sec;

    Que que;

    QInit(&que);
    srand(time(NULL));

    //for문 1번당 1초의 시간
    for(sec =0;sec<3600;sec++){
        if(sec % CUS_COME_TERM == 0){
            switch(rand()%3){
                case CHE:
                    Enqueue(&que,CHE_T);
                    cheord+=1;
                    break;
                
                case BUL:
                    Enqueue(&que,BUL_T);
                    bulord+=1;
                    break;
                
                case DUB:
                    Enqueue(&que,DUB_T);
                    dubord+=1;
                    break;
            }
        }

    }   
    printf("cheese :%d\n",cheord);
    printf("bul :%d\n",bulord);
    printf("double :%d\n",dubord);
}