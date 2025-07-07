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
Node* sort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    int swapped;
    do {
        swapped = 0;
        Node* curr = head;

        while (curr->next != NULL) {
            if (curr->data > curr->next->data) {
                swapped = 1;

                Node* next1 = curr->next;
                Node* next2 = next1->next;
                Node* prev1 = curr->prev;

                if (prev1 != NULL) {
                    prev1->next = next1;
                } else {
                    head = next1;
                }
                next1->prev = prev1;

                if (next2 != NULL) {
                    next2->prev = curr;
                }
                curr->next = next2;
                curr->prev = next1;
                next1->next = curr;
            } else {
                curr = curr->next;
            }
        }
    } while (swapped);

    return head;
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
    head=sort(head);
    printList(head);
    return 0;
}