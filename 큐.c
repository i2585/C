#include <stdio.h>
#include <stdlib.h> //문자열변환, 동적메모리할당함수
#include <string.h> //문자열처리
#define DataType char
#define MAX_SIZE 100
typedef struct Qnode { // 큐 노드 구조정의
    DataType data[MAX_SIZE];
    struct Qnode *link;
}Qnode;    
typedef struct LinkedQueue{ // 큐의 헤드노드 구조정의
    Qnode *front;
    Qnode *rear;
}LinkedQueue;
void init_queue(LinkedQueue *LQ) //큐 초기화
{
    LQ->front = LQ->rear = NULL;
}
int is_queue_empty(LinkedQueue *LQ)//큐가 공백상태인지 판단
{
    return LQ->front == NULL;
}
void enqueue(LinkedQueue *LQ, DataType *data) { // 큐에 삽입
    Qnode *new = (Qnode *)malloc(sizeof(Qnode));
    strcpy(new->data,data);// 문자열복사
    new->link = NULL;
    if (is_queue_empty(LQ)) //공백 큐에 삽입
        LQ->front = new;
    else //일반적인삽입
        LQ->rear->link = new;
    LQ->rear = new; //공통작업
}
void dequeue(LinkedQueue *MQ, LinkedQueue *FQ) {// 남자큐, 여자큐에서 데이터삭제
    if (is_queue_empty(MQ) || is_queue_empty(FQ))// 여자큐, 남자큐 둘 중 하나라도 공백일 경우
        printf("아직대상자가없습니다. 기다려주십시요.\n");
    else {
        Qnode *deleted = MQ->front;
        Qnode *deleted1 = FQ->front;
        MQ->front = MQ->front->link;
        FQ->front = FQ->front->link;
        if (is_queue_empty(MQ))// 삭제후 공백 큐 경우
            MQ->rear = NULL;
        if (is_queue_empty(MQ))// 삭제후 공백 큐 경우
            FQ->rear = NULL;
        printf("커플이탄생했습니다!%s과%s\n", deleted->data, deleted1->data);
        free(deleted);// 메모리반납
        free(deleted1);// 메모리반납
    }
}
void main() {
    LinkedQueue mqueue;
    LinkedQueue fqueue;
    printf("미팅주선프로그램입니다.\n");
    init_queue(&mqueue);// 남자 큐 초기화
    init_queue(&fqueue);// 여자 큐 초기화
    while (1) {// 무한반복으로 계속 미팅주선 프로그램을 돌림
        char name[MAX_SIZE];
        char a;
        printf("\n");
        printf("고객이름: ");
        scanf("%s", name);
        printf("성별을입력하세요(f or m)   ");
        scanf("%s", &a);
        if (a == 'm') {// 남자일 경우 남자큐에 이름 삽입
            enqueue(&mqueue, name);
        }
        else {//여자일 경우 여자큐에 이름 삽입
            enqueue(&fqueue, name);
        }
        dequeue(&mqueue, &fqueue);
    }
}
