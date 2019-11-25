#include <stdio.h>
#include <stdlib.h> //���ڿ� ��ȯ ���� �Լ�����
#define TRUE 1
#define FALSE 0
typedef struct ArrayStack { //�迭�� ���� ����
    int top;
    char stack[50];
}ArrayStack;
void init_stack(ArrayStack *AS) { //���� �ʱ�ȭ
    AS->top = -1;
}
void push(ArrayStack *AS, char data) //���ÿ� ����
{
    AS->stack[++AS->top] = data;
}
char pop(ArrayStack *AS) //���ÿ�������
{
    return AS->stack[AS->top--];
}
int palindrome(char in_str[]) { // �Է¹��� ���ڿ��� ȸ������ �˾Ƴ��� �Լ�
    ArrayStack s;
    int i;
    char ch, chs;
    int len = strlen(in_str);
    init_stack(&s); // ������ �ʱ�ȭ�϶�
    for (i = 0; i < len; i++) {
        ch = in_str[i];
        // ����ch�� �����̽��ų� �������̸�
        if (ch == '\'' || ch == ' ' || ch == ',') continue;
        ch = tolower(ch); // ch�� �ҹ��ڷ� ����
        push(&s, ch); // ���ÿ� �����Ѵ�.
    }
    for (i = 0; i < len; i++) {
        ch = in_str[i];
        // ����ch�� �����̽��ų� �������̸�
        if (ch == '\'' || ch == ' ' || ch == ',') continue;
        ch = tolower(ch); // ch�� �ҹ��ڷ� ����
        chs = pop(&s); // ���ÿ��� ���ڸ� ������
        if (ch != chs) return FALSE; // ����
    }
    return TRUE; // ����
}
int main()
{
    char astack[100];
    int data;
    gets(astack); // �����̽��������ϱ�����gets�����
    data = palindrome(&astack);
    if (data == 1) 
    {
        printf("ȸ���Դϴ�");
    }
    else
        printf("ȸ���̾ƴմϴ�.");
}    
