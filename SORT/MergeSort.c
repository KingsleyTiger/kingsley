#include<stdio.h>
#include<stdlib.h>

void MergeTwoArea(int *arr,int left,int mid,int right){
    int fidx = left;
    int ridx = mid+1;
    int i;

    int * sortArr = (int*)malloc(sizeof(int)*(right+1));    //right(6)+1개 만큼 배열 만듬,형변환을 하는 이유는?
    int sidx = left;

    while(fidx <= mid && ridx <= right){    //끝까지 가면
        if(arr[fidx]<=arr[ridx]){    //왼쪽 배열과 오른쪽 배열을 비교
            printf("sortArr[%d] = %d\n",sidx,arr[fidx]);
            sortArr[sidx] = arr[fidx++];    //왼쪽이 작으면 값 리턴 후 한칸 앞으로
        }
        else{
            printf("sortArr[%d] = %d\n",sidx,arr[fidx]);    
            sortArr[sidx] = arr[ridx++];    //오른쪽이 작으면 값 리턴 후 한칸 앞으로
        }
        
        sidx++;
    }

    if(fidx > mid){ //남은걸 병합
        for(i=ridx;i<=right;i++,sidx++){
            printf("sortArr[%d] = %d\n",sidx,arr[fidx]);
            sortArr[sidx] = arr[i];
        }
    }
    else{
        for(i=fidx;i<=mid;i++,sidx++){
            printf("sortArr[%d] = %d\n",sidx,arr[fidx]);
            sortArr[sidx] = arr[i];
        }
    }
    for(i=left;i<=right;i++)
        arr[i] = sortArr[i];

    free(sortArr);
}

void MergeSort(int *arr,int left,int right){
    int mid;

    if(left<right){
        mid = (left+right)/2;
        
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);

        MergeTwoArea(arr,left,mid,right);
    }
}

int main(){
    int arr[7] = {3,2,4,1,7,6,5};
    int i;
    
    MergeSort(arr,0,sizeof(arr)/sizeof(int)-1);

    for(i=0;i<7;i++)
        printf("%d ",arr[i]);

}