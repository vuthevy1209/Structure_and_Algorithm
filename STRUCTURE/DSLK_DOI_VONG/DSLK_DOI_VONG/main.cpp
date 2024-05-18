#define _CRT_SECURE_NO_WARNINGS
#define NULL nullptr
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node node;

node* makenode(int x){
    node* newnode = new node;
    newnode->data = x;
    newnode->next = newnode->prev = newnode;
    return newnode;
}


void pushBack(node** head, int x){
    node* newnode = makenode(x);
    if(*head == nullptr){
        *head = newnode;
        (*head)->next = *head;
        (*head)->prev = *head;
    }
    else if ((*head)->next == (*head)){
        (*head)->next = newnode;
        newnode->prev = *head;
        newnode->next = *head;
        (*head)->prev = newnode;
    }
    else{
        node* previot = (*head)->prev;
        previot->next = newnode;
        newnode->next = *head;
        (*head)->prev = newnode;
        newnode->prev = previot;
    }
}
void duyet(node* head){
    if(head == nullptr) return;
    node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp != head);
}

void duyet_2(node* head){
    node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->prev;
    }
    while(temp != head);
}
             
void xoa_full(node** head){
    if (*head == nullptr) return;
    node* Tail = (*head)->prev;
    Tail->next = nullptr;
    node* temp = nullptr;
    while(*head != nullptr){
        temp = *head;
        *head = (*head)->next;
        delete temp;
    }
    *head = nullptr;
}

int main()
{
    node* head = NULL;
    int n = 0;
    int k = 0;
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        pushBack(&head, i);
    }
    //thuchienyeudebai(&head, k);
    duyet(head);
    xoa_full(&head);
    duyet(head);
    return 0;
}

