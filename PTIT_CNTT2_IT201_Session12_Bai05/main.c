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
Node* deleteByValue(Node* head, int value) {
    Node* curr=head;
    if (head==NULL) {
        return head;
    }else {
        while(curr!=NULL) {
            if (curr->data==value) {
                Node* temp = curr;
                if (curr==head) {
                    head=curr->next;
                    if (head!=NULL) {
                        head->prev=NULL;
                    }
                }else {
                    if (curr->prev!=NULL) {
                        curr->prev->next=curr->next;
                    }
                    if (curr->next!=NULL) {
                        curr->next->prev=curr->prev;
                    }
                    curr=curr->next;
                    free(temp);
                }
            }else {
                curr=curr->next;
            }

        }

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
    printf("Nhap gia tri muon xoa khoi danh sach: ");
    scanf("%d",&x);
    printf("Sau khi xoa phan tu %d trong danh sach: ",x);
    head=deleteByValue(head,x);
    printList(head);
    return 0;
}