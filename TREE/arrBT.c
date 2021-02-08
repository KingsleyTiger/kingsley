#include<stdio.h>

typedef int Data;

typedef struct _arrayBT{
    Data BTarr[100];

}ABT;

void BTInit(ABT * bt){
    bt->BTarr = {0};
}

int BTIs