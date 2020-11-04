#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//평문을 2진수로 변환하는 Binary 함수
void Binary(char *mes){     //char *mes = p
    char bit[512];       //bit배열에 비트값을 받음
    for(int i=0;i<64;i++){
        for(int j=0;j<512;j++){
            if(j%8==0){
                bit[j]=mes[i]/128;
            }
            if(j%8==1){
                bit[j]=mes[i]/64;
            }
            if(j%8==2){
                bit[j]=mes[i]/32;
            }
            if(j%8==3){
                bit[j]=mes[i]/16;
            }
            if(j%8==4){
                bit[j]=mes[i]/8;
            }
            if(j%8==5){
                bit[j]=mes[i]/4;
            }
            if(j%8==6){
                bit[j]=mes[i]/2;
            }
            if(j%8==7){
                mes[i]=mes[i]%2;    //마지막 값은 걍 2로 나눈값과 같다.
                bit[j]=mes[i];
            }
            //printf("%d ",bit[j]);
        }
    
        
    }
}

//단순 P박스 구현. rand_mes배열에 1~64 값 랜덤 할당 후 배열 리턴
//배열을 리턴해야하므로 char* 리턴형, 포인터인 이유는 배열의 주소값을 리턴하기 위해
char* SimplePBox(){
    srand((unsigned int)time(0));   //랜덤 함수의 시드값 설정
    static char rand_mes[64];       //정적 변수 선언으로 지역변수의 값을 초기화하지 않고 값을 그대로 사용
        
    for(int j = 0 ; j < 64 ; j++){
        rand_mes[j]=rand()%64;      //랜덤 값 할당
        //printf("배열 출력 \n%d ",rand_mes[j]);  
    }
    printf("\n");
    return rand_mes;    //배열 리턴
}

//char *mes라는 포인터 선언
//라운드 함수 구현. 16라운드 돌려야함.
void RoundFunc(char *mes){
int LBit[32];
int RBit[32];

//generate l32
printf("LBIT 출력\n");
for(int i=0;i<32;i++){
    LBit[i]=mes[i];
    printf("%d ",LBit[i]);
}
printf("\n");

//generate r32
printf("RBIT 출력\n");
for(int i=32;i<64;i++){
    RBit[i-32]=mes[i];
    printf("%d ",RBit[i-32]);
}
}
//DES 함수 키랑 xor연산 해야함.
void DES_func(int RBit[32]){
    for(int i=0;i<32;i++){

    }
}

//lbit와 rbit자리 바꿔주는 함수
void Swapper(int LBit[32],int RBit[32]){
    //int EN_LBit[32]=RBit[32];
    //int EN_RBit[32]=
}

int main(){
    char *p = SimplePBox();     //배열을 리턴하는 SimplePBox를 받아주는 포인터 p 선언
    Binary(p);      //배열의 주소를 가지고 있는 p를 사용
    
    //for(int i=0;i<16;i++){
    RoundFunc(p);
    //DES_func();
    //Swapper();
    //}

}