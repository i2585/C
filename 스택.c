#include <stdio.h>
#include <stdlib.h> //문자열 변환 등의 함수포함
#define TRUE 1
#define FALSE 0
typedef struct ArrayStack { //배열의 스택 정의
    int top;
    char stack[50];
}ArrayStack;
void init_stack(ArrayStack *AS) { //스택 초기화
    AS->top = -1;
}
void push(ArrayStack *AS, char data) //스택에 삽입
{
    AS->stack[++AS->top] = data;
}
char pop(ArrayStack *AS) //스택에서삭제
{
    return AS->stack[AS->top--];
}
int palindrome(char in_str[]) { // 입력받은 문자열이 회문인지 알아내는 함수
    ArrayStack s;
    int i;
    char ch, chs;
    int len = strlen(in_str);
    init_stack(&s); // 스택을 초기화하라
    for (i = 0; i < len; i++) {
        ch = in_str[i];
        // 만약ch가 스페이스거나 구두점이면
        if (ch == '\'' || ch == ' ' || ch == ',') continue;
        ch = tolower(ch); // ch를 소문자로 변경
        push(&s, ch); // 스택에 삽입한다.
    }
    for (i = 0; i < len; i++) {
        ch = in_str[i];
        // 만약ch가 스페이스거나 구두점이면
        if (ch == '\'' || ch == ' ' || ch == ',') continue;
        ch = tolower(ch); // ch를 소문자로 변경
        chs = pop(&s); // 스택에서 문자를 꺼낸다
        if (ch != chs) return FALSE; // 실패
    }
    return TRUE; // 성공
}
int main()
{
    char astack[100];
    int data;
    gets(astack); // 스페이스를포함하기위해gets를사용
    data = palindrome(&astack);
    if (data == 1) 
    {
        printf("회문입니다");
    }
    else
        printf("회문이아닙니다.");
}    
