#include<stdio.h>

void SelSort(int arr[],int n){
    int i,j;
    int maxidx;
    int temp;

    for(i=0;i<n-1;i++){
        maxidx = i;
        for(j=i+1;j<n;j++){
            if(arr[j] < arr[maxidx])
                maxidx = j;
        }
        temp = arr[i];
        arr[i] = arr[maxidx];
        arr[maxidx] = temp;
    }
}

int main(){
    int arr[4] = {3,4,2,1};
    int i;

    SelSort(arr,sizeof(arr)/sizeof(int));

    for(i=0;i<4;i++){
        printf("%d ",arr[i]);
    }


}