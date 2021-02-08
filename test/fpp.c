#include<stdio.h>

int main(){
    int arr[4]={1,2,3,4};
    int fidx = 0;
    int ridx = 2;

    arr[fidx] = arr[ridx++];
    printf("ridx = %d, arr[0] = %d",ridx,arr[fidx]);
    //내 예상 : 3,3
}