#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <cstring>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node node;

int size(node* head)
{
    int cnt = 0;
    while(head != nullptr)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

node* makeNode(int x)
{
    node* newnode = new node;
    newnode->data = x;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    return newnode;
}

void pushFront(node* &head, int x)
{
    node* newnode = makeNode(x);
    if(head == nullptr)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void pushBack(node* head, int x)
{
    node* newnode = makeNode(x);
    if(head == nullptr)
    {
        head = newnode;
    }
    else
    {
        node* temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insert(node* head, int x, int k)
{
    int n = size(head);
    if(k < 1 || k > n+1)
    {
        return;
    }
    else if (k == 1)
    {
        pushFront(head, x);
    }
    else
    {
        node* newnode = makeNode(x);
        node* temp = head;
        for(int i = 1; i <= k-1; i++)
        {
            temp = temp->next;
        }
        node* prev = temp->prev;
        prev->next = newnode;
        newnode->prev = prev;
        newnode->next = temp;
        temp->prev = newnode;
    }
}

void popFront(node* &head)
{
    if(head == nullptr)
    {
        return;
    }
    else if((head)->next == nullptr)
    {
        node* temp = head;
        head = nullptr;
        delete temp;
    }
    else
    {
        node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

void popBack(node* &head)
{
    if(head == nullptr || head->next == nullptr)
    {
        popFront(head);
    }
    else
    {
        node* temp = head;
        while((temp->next)->next != nullptr)
        {
            temp = temp->next;
        }
        node* node_delete = temp->next;
        temp->next = nullptr;
        delete node_delete;
    }
}

void Erase(node* &head, int k)
{
    int n = size(head);
    if(k < 1 || k > n)
    {
        return;
    }
    if(k == 1)
    {
        popFront(head);
    }
    else if(k == n)
    {
        popBack(head);
    }
    else
    {
        node* temp = head;
        for(int i = 1; i <= k - 1; i++)
        {
            temp = temp->next;
        }
        node* prev = temp->prev;
        prev->next = temp->next;
        (temp->next)->prev = prev;
        delete temp;
    }
}

void print_list(node* head)
{
    if(head != nullptr)
    {
        printf("%d ", head->data);
        print_list(head->next);
    }
}

void remove_all(node* &head)
{
    node* temp = nullptr;
    while(head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

void lat_nguoc_DSLK_doi(node* &head)
{
    // Nếu danh sách rỗng hoặc chỉ có một phần tử thì không cần lật ngược
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    // Di chuyển con trỏ tới phần tử cuối cùng của danh sách liên kết đôi
    node* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    // Lật ngược danh sách liên kết đôi
    while (head != nullptr)
    {
        // Hoán đổi con trỏ prev và next của nút hiện tại
        node* tmp = head->next;
        head->next = head->prev;
        head->prev = tmp;

        // Di chuyển con trỏ tới phần tử tiếp theo
        head = head->prev;
    }
    //cập nhật lại head
    head = current;
}

node* merge(node* left, node* right)
{
    node* result = nullptr;
    if(left == nullptr)
    {
        return right;
    }
    if(right == nullptr)
    {
        return left;
    }
    if(left->data <= right->data)
    {
        result = left;
        node* temp = merge(left->next, right);
        result->next = temp;
        temp->prev = result;
    }
    if(left->data > right->data)
    {
        result = right;
        node* temp = merge(left, right->next);
        result->next = temp;
        temp->prev = result;
    }
    return result;
}

void Merge_Sort(node* &head)
{
    if(head == nullptr || (head->next == nullptr && head->prev == nullptr))
    {
        return;
    }
    
    node* left = head;
    node* right = nullptr;
    node* temp = head;
    while((temp->next)->next != nullptr)
    {
        temp = temp-> next;
    }
    right = temp->next;
    (temp->next)->prev = nullptr;
    temp->next = nullptr;
    
    Merge_Sort(left);
    Merge_Sort(right);
    
    head = merge(left, right);
}

int main()
{
    node* head = nullptr;
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i<n;  i++)
    {
        int x = 0;
        scanf("%d", &x);
        pushBack(&head, x);
    }
    Merge_Sort(&head);
//    popFront(&head);
//    popBack(&head);
//    Erase(&head, 3);
//    pushFront(&head, 99);
//    pushBack(&head, 98);
//    insert(&head, 100, 3);
    //lat_nguoc_DSLK_doi(&head);
    print_list(head);
    remove_all(&head);
    return 0;
}
