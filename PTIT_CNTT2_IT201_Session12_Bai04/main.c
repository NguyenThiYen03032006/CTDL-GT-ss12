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
Node* deleteTail(Node* head) {
    Node* curr=head;
    if (head==NULL) {
        return head;
    }else {
        while(curr->next->next!=NULL) {
            curr=curr->next;
        }
        Node* temp=curr->next;
        curr->next=NULL;
        free(temp);

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
    printf("Sau khi xoa phan tu o cuoi danh sach: ");
    head=deleteTail(head);
    printList(head);
    return 0;
}