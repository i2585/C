#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType char
#define SIZE 100
typedef struct Tnode { // 이진트리노드구조정의
    struct Tnode *left;
    DataType data[SIZE];
    struct Tnode *right;
    int count;
}Tnode;
typedef struct LinkedBT { // 이진트리의헤드노드구조정의
    Tnode *root;
}LinkedBT;
void init_BT(Tnode **root) { // 트리초기화
    *root = NULL;
}
void inorder(Tnode *root) // 중위순회를이용하여출력
{
if (root) {
    inorder(root->left);
    printf("%10s%10d\n", root->data, root->count);
    inorder(root->right);
    }
}
void insert_node_BST(Tnode **root, DataType *data) { // data를키값으로하는노드를트리root에삽입
    Tnode *searched = *root;
    Tnode *parent = NULL;
    int i;
    char temp[SIZE];
    for (i = 0; i < SIZE; i++)// 마지막를트리에서제외시키는반복문
    {
        temp[i] = data[i];
    if (data[i] == (char) NULL)
        break;
    if (data[i] == '?')
        data[i] = (char) NULL;
    }
    while (searched) { //트리탐색반복문
        if (strcmp(searched->data, data) == 0) {
            searched->count++;
            return;
        }
        parent = searched; //parent를아래로
        if (strcmp(data, searched->data) < 0)
            searched = searched->left; //searched를왼쪽으로
        else
            searched = searched->right; //searched를오른쪽으로
    }
    Tnode *new = (Tnode *)malloc(sizeof(Tnode));
    if (!new) {
        printf("새노드메모리할당실패\n");
        exit(1);
    }
    strcpy(new->data, data);
    new->left = new->right = NULL;
    if (!parent) *root = new; // 빈트리에삽입
    else if (strcmp(data, parent->data) < 0)
        parent->left = new; // parent의왼쪽에삽입
    else
        parent->right = new; // parent의오른쪽에삽입
    new->count = 1;
    data = temp;
}
void main()
{
    LinkedBT tr;
    DataType data[SIZE];
    int count = 0;
    init_BT(&(tr.root)); // 트리초기화
    while (1) { // 문자열을계속입력받아트리에삽입하는무한루프
        gets(data);
        if (data[0] == '1') // 1을입력하면무한루프종료
            break;
        DataType *ptr = strtok(data, " "); // 입력받은문자열을스페이스바를기준으로자르는명령어
        while (ptr != NULL) {
            insert_node_BST(&(tr.root), ptr);
            count++;
            ptr = strtok(NULL, " ");
        }
    }
    printf("       단어      횟수\n");
    inorder(tr.root);
    printf("       계 %10d\n", count);
}
