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

//함수 포인터형 visitfuncptr의 정의
typedef void VisitFuncPtr(BTData data);

//중위 순회
//공 노드이면 재귀 함수 탈출 후 다음 라인 실행
//action에 들어간 함수는 void형,매개변수가 1개 여야함
void InorderTraverse(BTreeNode * bt,VisitFuncPtr action){
    if(bt == NULL)
        return;
    
    InorderTraverse(bt->left,action);
    action(bt->data);   //출력 외의 다른 기능을 구현하기 위해 함수 포인터를 사용
    InorderTraverse(bt->right,action);
}

//전위 순회
void PreorderTraverse(BTreeNode * bt,VisitFuncPtr action){
    if(bt == NULL)
        return;
    
    action(bt->data);
    PreorderTraverse(bt->left,action);
    PreorderTraverse(bt->right,action);
}

//후위순회
void PostorderTraverse(BTreeNode * bt,VisitFuncPtr action){
    if(bt == NULL)
        return;
    
    PostorderTraverse(bt->left,action);
    PostorderTraverse(bt->right,action);
    action(bt->data);
}

void ShowData(int data){
    printf("%d ",data);
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
    InorderTraverse(bt0,ShowData);

    //bt1의 왼쪽 자식 노드의 데이터 출력
    //printf("%d \n",GetData(GetLeftSubTree(bt1)));

    //bt2의 오른쪽 자식 노드의 데이터 출력
    //printf("%d \n",GetData(GetRightSubTree(bt2)));
}