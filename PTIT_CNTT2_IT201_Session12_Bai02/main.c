#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
void printList(Node* head) {
    Node* curr=head;
    int count=1;
    while(curr!=NULL) {
        printf("Node %d: %d\n",count, curr->data);
        curr=curr->next;
        count++;
    }

}
int main(void) {
    int n;
    scanf("%d",&n);
    Node* head=NULL;
    Node* tail=NULL;
    printf("Nhap phan tu cua danh sach:\n");
    for (int i=1;i<=n; i++) {
        Node* node=createNode(i);
        if (!head) {
            head=tail=node;
        }else {
            tail->next=node;
            node->prev=tail;
            tail=node;
        }
    }
    printList(head);
    return 0;
}