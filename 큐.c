#include <stdio.h>
#include <stdlib.h> //���ڿ���ȯ, �����޸��Ҵ��Լ�
#include <string.h> //���ڿ�ó��
#define DataType char
#define MAX_SIZE 100
typedef struct Qnode { // ť ��� ��������
    DataType data[MAX_SIZE];
    struct Qnode *link;
}Qnode;    
typedef struct LinkedQueue{ // ť�� ����� ��������
    Qnode *front;
    Qnode *rear;
}LinkedQueue;
void init_queue(LinkedQueue *LQ) //ť �ʱ�ȭ
{
    LQ->front = LQ->rear = NULL;
}
int is_queue_empty(LinkedQueue *LQ)//ť�� ����������� �Ǵ�
{
    return LQ->front == NULL;
}
void enqueue(LinkedQueue *LQ, DataType *data) { // ť�� ����
    Qnode *new = (Qnode *)malloc(sizeof(Qnode));
    strcpy(new->data,data);// ���ڿ�����
    new->link = NULL;
    if (is_queue_empty(LQ)) //���� ť�� ����
        LQ->front = new;
    else //�Ϲ����λ���
        LQ->rear->link = new;
    LQ->rear = new; //�����۾�
}
void dequeue(LinkedQueue *MQ, LinkedQueue *FQ) {// ����ť, ����ť���� �����ͻ���
    if (is_queue_empty(MQ) || is_queue_empty(FQ))// ����ť, ����ť �� �� �ϳ��� ������ ���
        printf("��������ڰ������ϴ�. ��ٷ��ֽʽÿ�.\n");
    else {
        Qnode *deleted = MQ->front;
        Qnode *deleted1 = FQ->front;
        MQ->front = MQ->front->link;
        FQ->front = FQ->front->link;
        if (is_queue_empty(MQ))// ������ ���� ť ���
            MQ->rear = NULL;
        if (is_queue_empty(MQ))// ������ ���� ť ���
            FQ->rear = NULL;
        printf("Ŀ����ź���߽��ϴ�!%s��%s\n", deleted->data, deleted1->data);
        free(deleted);// �޸𸮹ݳ�
        free(deleted1);// �޸𸮹ݳ�
    }
}
void main() {
    LinkedQueue mqueue;
    LinkedQueue fqueue;
    printf("�����ּ����α׷��Դϴ�.\n");
    init_queue(&mqueue);// ���� ť �ʱ�ȭ
    init_queue(&fqueue);// ���� ť �ʱ�ȭ
    while (1) {// ���ѹݺ����� ��� �����ּ� ���α׷��� ����
        char name[MAX_SIZE];
        char a;
        printf("\n");
        printf("���̸�: ");
        scanf("%s", name);
        printf("�������Է��ϼ���(f or m)   ");
        scanf("%s", &a);
        if (a == 'm') {// ������ ��� ����ť�� �̸� ����
            enqueue(&mqueue, name);
        }
        else {//������ ��� ����ť�� �̸� ����
            enqueue(&fqueue, name);
        }
        dequeue(&mqueue, &fqueue);
    }
}
