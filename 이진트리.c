#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType char
#define SIZE 100
typedef struct Tnode { // ����Ʈ����屸������
    struct Tnode *left;
    DataType data[SIZE];
    struct Tnode *right;
    int count;
}Tnode;
typedef struct LinkedBT { // ����Ʈ��������屸������
    Tnode *root;
}LinkedBT;
void init_BT(Tnode **root) { // Ʈ���ʱ�ȭ
    *root = NULL;
}
void inorder(Tnode *root) // ������ȸ���̿��Ͽ����
{
if (root) {
    inorder(root->left);
    printf("%10s%10d\n", root->data, root->count);
    inorder(root->right);
    }
}
void insert_node_BST(Tnode **root, DataType *data) { // data��Ű�������ϴ³�带Ʈ��root������
    Tnode *searched = *root;
    Tnode *parent = NULL;
    int i;
    char temp[SIZE];
    for (i = 0; i < SIZE; i++)// ��������Ʈ���������ܽ�Ű�¹ݺ���
    {
        temp[i] = data[i];
    if (data[i] == (char) NULL)
        break;
    if (data[i] == '?')
        data[i] = (char) NULL;
    }
    while (searched) { //Ʈ��Ž���ݺ���
        if (strcmp(searched->data, data) == 0) {
            searched->count++;
            return;
        }
        parent = searched; //parent���Ʒ���
        if (strcmp(data, searched->data) < 0)
            searched = searched->left; //searched����������
        else
            searched = searched->right; //searched������������
    }
    Tnode *new = (Tnode *)malloc(sizeof(Tnode));
    if (!new) {
        printf("�����޸��Ҵ����\n");
        exit(1);
    }
    strcpy(new->data, data);
    new->left = new->right = NULL;
    if (!parent) *root = new; // ��Ʈ��������
    else if (strcmp(data, parent->data) < 0)
        parent->left = new; // parent�ǿ��ʿ�����
    else
        parent->right = new; // parent�ǿ����ʿ�����
    new->count = 1;
    data = temp;
}
void main()
{
    LinkedBT tr;
    DataType data[SIZE];
    int count = 0;
    init_BT(&(tr.root)); // Ʈ���ʱ�ȭ
    while (1) { // ���ڿ�������Է¹޾�Ʈ���������ϴ¹��ѷ���
        gets(data);
        if (data[0] == '1') // 1���Է��ϸ鹫�ѷ�������
            break;
        DataType *ptr = strtok(data, " "); // �Է¹������ڿ��������̽��ٸ����������ڸ��¸�ɾ�
        while (ptr != NULL) {
            insert_node_BST(&(tr.root), ptr);
            count++;
            ptr = strtok(NULL, " ");
        }
    }
    printf("       �ܾ�      Ƚ��\n");
    inorder(tr.root);
    printf("       �� %10d\n", count);
}
