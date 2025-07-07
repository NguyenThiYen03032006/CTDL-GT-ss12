#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node* creatNode(int value) {
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=value;
    node->next=NULL;
    node->prev=NULL;
    return node;
}
int main(void) {
    int n;
    printf("Nhap so luong phan tu : ");
    scanf("%d", &n);
    Node* head=NULL;
    Node* tail=NULL;
    for (int i=1; i<=n; i++) {
        Node* node=creatNode(i);
        if (!head) {
            head=tail=node;
        }else {
            tail->next=node;
            node->prev=tail;
            tail=node;
        }
    }

    return 0;
}