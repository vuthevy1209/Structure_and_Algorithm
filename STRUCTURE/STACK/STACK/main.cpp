#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

using node = struct node;

node *makeNode(int x)
{
    node *newnode = new node;
    newnode->data = x;
    newnode->next = nullptr;
    return newnode;
}

int size(node *stack)
{
    int cnt = 0;
    while (stack != nullptr)
    {
        cnt++;
        stack = stack->next;
    }
    return cnt;
}

void push(node *&stack, int x)
{
    node *newnode = makeNode(x);
    if (stack == nullptr)
    {
        stack = newnode;
        return;
    }
    newnode->next = stack;
    stack = newnode;
}
void pop(node *&stack)
{
    node *temp = stack;
    stack = stack->next;
    delete temp;
}

int Top(node *stack)
{
    return stack->data;
}

void print_list(node *stack)
{
    while (stack != nullptr)
    {
        printf("%d ", stack->data);
        stack = stack->next;
    }
}

void removeall(node *&stack)
{
    node *temp = nullptr;
    while (stack != nullptr)
    {
        temp = stack;
        stack = stack->next;
        delete temp;
    }
    stack = nullptr;
}

int main()
{
    node *stack = nullptr;
    while (true)
    {
        printf("----------------------MENU----------------------\n");
        printf("          1. Them vao ngan xep gia tri x.\n");
        printf("          2. Xoa ngan xep\n");
        printf("          3. In ra ngan xep\n");
        printf("          4. In ra Top cua ngan xep\n");
        printf("          0. Exit!\n");
        printf("----------------------END-----------------------");
        int choose;
        printf("\nNhap lua chon: ");
        scanf("%d", &choose);
        if (choose < 0 || choose > 4)
        {
            printf("Ban da nhap sai yeu cau, Vui long nhap lai!\n");
        }
        else if (choose == 1)
        {
            int x = 0;
            printf("Moi nhap gia tri x : ");
            scanf("%d", &x);
            push(stack, x);
        }
        else if (choose == 2)
        {
            pop(stack);
        }
        else if (choose == 3)
        {
            print_list(stack);
            printf("\n");
        }
        else if (choose == 4)
        {
            int n = Top(stack);
            printf("%d\n", n);
        }
        else if (choose == 0)
        {
            removeall(stack);
            return 0;
        }
    }
}
