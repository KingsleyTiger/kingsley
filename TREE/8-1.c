#include<stdio.h>
#include<stdlib.h>

typedef int BTData;

typedef struct _bTreeNode{
    BTData data;
    struct _bTreeNode * left;
    struct _bTreeNode * right;
}BTreeNode;

//노드 생성,노드 초기화
BTreeNode * MakeTreeNode(){
    BTreeNode * newNode=(BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//노드에 저장된 데이터를 반환
BTData GetData(BTreeNode * bt){
    return bt->data;
}

//노드에 데이터 저장
void SetData(BTreeNode * bt,BTData data){
    bt->data = data;
}

//왼쪽 서브 트리 주소값 반환
BTreeNode * GetLeftSubTree(BTreeNode * bt){
    return bt->left;
}

//오른쪽 서브 트리 주소값 반환
BTreeNode * GetRightSubTree(BTreeNode * bt){
    return bt->right;
}

//메인 트리와 왼쪽 서브 트리를 연결한다. 
void MakeLeftSubTree(BTreeNode * main,BTreeNode * sub){
    if(main->left != NULL)
        free(main->left);

    main->left = sub;
}

//메인 트리와 오른쪽 서브 트리를 연결한다.
void MakeRightSubTree(BTreeNode * main,BTreeNode * sub){
    if(main->right != NULL)
        free(main->right);

    main->right=sub;
}

//포인터 선언
//typedef void (*VisitFuncPtr)(BTData);

//중위 순회
//공 노드이면 재귀 함수 탈출 후 다음 라인 실행
void InorderTraverse(BTreeNode * bt){
    if(bt == NULL)
        return;
    
    InorderTraverse(bt->left);
    action(bt->data);
    InorderTraverse(bt->right);
}

//전위 순회
void PreorderTraverse(BTreeNode * bt){
    if(bt == NULL)
        return;
    
    action(bt->data);
    InorderTraverse(bt->left);
    InorderTraverse(bt->right);
}

//후위순회
void PostorderTraverse(BTreeNode * bt){
    if(bt == NULL)
        return;
    
    InorderTraverse(bt->left);
    InorderTraverse(bt->right);
    action(bt->data);
}


//void ShowData(BTreeNode * bt){
//    printf("%d \n",bt->data);
//}

//삭제 구현
void DeleteTree(BTreeNode * bt){
    if(bt == NULL)
        return;
    DeleteTree(bt->left);
    DeleteTree(bt->right);
    free(bt);
}


int main(){
    BTreeNode * bt0 = MakeTreeNode();
    BTreeNode * bt1 = MakeTreeNode();
    BTreeNode * bt2 = MakeTreeNode();
    BTreeNode * bt3 = MakeTreeNode();
    BTreeNode * bt4 = MakeTreeNode();
     BTreeNode * bt5 = MakeTreeNode();

    SetData(bt0,0);
    SetData(bt1,1);
    SetData(bt2,2);
    SetData(bt3,3);
    SetData(bt4,4);
    SetData(bt5,5);

    MakeLeftSubTree(bt0,bt1);
    MakeRightSubTree(bt0,bt2);
    MakeRightSubTree(bt1,bt4);
    MakeLeftSubTree(bt1,bt3);
    MakeRightSubTree(bt2,bt5);

    //VisitFuncPtr = showData;
    //InorderTraverse(bt0,VisitFuncPtr(bt0));

    //bt1의 왼쪽 자식 노드의 데이터 출력
    //printf("%d \n",GetData(GetLeftSubTree(bt1)));

    //bt2의 오른쪽 자식 노드의 데이터 출력
    //printf("%d \n",GetData(GetRightSubTree(bt2)));
}