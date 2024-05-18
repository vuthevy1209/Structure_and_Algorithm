#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

using node = struct node;

node* makeNode(int x){
    node* newnode = new node;
    newnode->data = x;
    newnode->next = nullptr;
    return newnode;
}

void push(node* &queue, int x){
    node* newnode = makeNode(x);
    if(queue == nullptr){
        queue = newnode;
        return;
    }
    node* temp = queue;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newnode;
}

void pop(node* &queue){
    if(queue == nullptr){
        return;
    }
    node* temp = queue;
    queue = queue->next;
    delete temp;
}

int size_Queue(node* queue){
    int cnt = 0;
    while(queue != nullptr){
        cnt++;
        queue = queue->next;
    }
    return cnt;
}

int Front(node* queue){
    return queue->data;
}

void print_list(node* queue){
    while(queue != nullptr){
        printf("%d ", queue->data);
        queue = queue->next;
    }
}

void remove_all(node*& queue){
    node* temp = nullptr;
    while(queue != nullptr){
        temp = queue;
        queue = queue->next;
        delete temp;
    }
    queue = nullptr;
}
int main() {
    node* queue = nullptr;
    while(true){
        printf("----------------------MENU----------------------\n");
        printf("          1. Them vao hang doi gia tri x.\n");
        printf("          2. Xoa hang doi\n");
        printf("          3. In ra hang doi\n");
        printf("          4. In ra Front cua ngan xep\n");
        printf("          0. Exit!\n");
        printf("----------------------END-----------------------");
        int choose;
        printf("\nNhap lua chon: ");
        scanf("%d", &choose);
        if(choose < 0 || choose > 4){
            printf("Ban da nhap sai yeu cau, Vui long nhap lai!\n");
        }
        else if(choose == 1){
            int x = 0;
            printf("Moi nhap gia tri x : ");
            scanf("%d", &x);
            push(queue, x);
        }
        else if (choose == 2){
            pop(queue);
        }
        else if(choose == 3){
            print_list(queue);
            printf("\n");
        }
        else if(choose == 4){
            int n = Front(queue);
            printf("%d\n", n);
        }
        else if(choose == 0){
            remove_all(queue);
            return 0;
        }
    }
}
    
