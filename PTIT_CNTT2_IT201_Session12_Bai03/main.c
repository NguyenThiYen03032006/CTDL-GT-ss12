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
Node* insertTail(Node* head, int data) {
    Node* node = createNode(data);
    Node* curr=head;
    if(head==NULL) {
        head = node;
    }else {
        while(curr->next!=NULL) {
            curr=curr->next;
        }
        curr->next = node;
        node->prev = curr;
    }
    return head;
}
int main(void) {
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
    int x;
    printf("Nhap vao phan tu them vao cuoi: ");
    scanf("%d",&x);
    head=insertTail(head,x);
    printList(head);
    return 0;
}