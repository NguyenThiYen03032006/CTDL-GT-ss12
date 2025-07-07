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
        printf("%d<->",curr->data);
        curr=curr->next;
        count++;
    }
    printf("NULL\n");

}
void findNode(Node* head, int len){
    Node* curr=head;
    while(curr!=NULL) {
        for (int i=0; i<len/2; i++) {
            curr=curr->next;
        }
        printf("Node: %d\n",curr->data);
        return;
    }
    }
int main(void){
        int n;
        printf("Nhap so luong phan tu: ");
        scanf("%d",&n);
        Node* head=NULL;
        Node* tail=NULL;
        printf("Nhap phan tu cua danh sach:\n");
        for (int i=1;i<=n; i++) {
            int temp;
            printf("Nhap gia tri phan tu thu %d: ", i);
            scanf("%d",&temp);
            Node* node=createNode(temp);
            if (!head) {
                head=tail=node;
            }else {
                tail->next=node;
                node->prev=tail;
                tail=node;
            }
        }
        printList(head);
        findNode(head,n);
        return 0;
    }