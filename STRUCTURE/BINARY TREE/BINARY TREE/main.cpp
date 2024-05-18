#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
    int data;
    struct node* right;
    struct node* left;
};

using node = struct node;

//hàm tạo node mới cho cây
node* makeNode(int x){
    node* newnode = new node;
    newnode->data = x;
    newnode->right = nullptr;
    newnode->left = nullptr;
    return newnode;
}

//Thêm node vào cây nhị phân
void push_to_tree(node* &root, int x)
{
    if(root==nullptr){// Đã tìm ra vị trí thích hợp để thêm
        node* newnode = makeNode(x);
        root = newnode;
        return;
    }
    if(x == root->data)
        return;
    if(x < root->data)// nếu giá trị thêm nhỏ hơn giá trị của gốc thì đi qua bên trái
        push_to_tree(root->left, x);
    if(x > root->data)// nếu giá trị thêm lớn hơn giá trị của gốc thì đi qua bên phải
        push_to_tree(root->right, x);
}

//Duyệt cây nhị phân theo kiểu Left-Node-Right
void Duyet_LNR(node* root){
    if(root != nullptr)
    {
        Duyet_LNR(root->left);
        printf("%d ", root->data);
        Duyet_LNR(root->right);
    }
}

//Duyệt cây nhị phân theo kiểu Right-Node-Left
void Duyet_RNL(node* root){
    if(root != nullptr){
        Duyet_RNL(root->right);
        printf("%d ", root->data);
        Duyet_RNL(root->left);
    }
}


//Hàm hỗ trở tìm node có giá trị nhỏ nhất tính từ node gốc
node* min_Right(node* root){
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}

// hàm xóa node có giá trị x trong cây nhị phân
void pop(node* &root, int x){
    if(root == nullptr)// Nếu không tìm thấy
        return;
    if(x < root->data)// nếu giá trị thêm nhỏ hơn giá trị của gốc thì đi qua bên trái
        pop(root->left, x);
    else if(x > root->data)// nếu giá trị thêm lớn hơn giá trị của gốc thì đi qua bên phải
        pop(root->right, x);
    else{ // nếu đã tìm thấy node cần xóa
        if(root->left == nullptr && root->right == nullptr){ // TH1: node cần xóa là node lá
            delete root;
            root = nullptr;
        }
        else if(root->left == nullptr){ //TH2: node cần xóa là node có 1 con phải
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr){ //TH3: node cần xóa là node có 1 con trái
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else{ //TH4: node cần xóa là node có 2 con
            node* temp = min_Right(root->right);
            root->data = temp->data;
            pop(root->right, temp->data);
        }
    }
}

//Hàm tìm kiếm xem giá trị x có trong cây nhị phân hay không
node* Search(node* root, int x){
    if (root == nullptr || root->data == x)
           return root;
    else if(x < root->data)
        return Search(root->left, x);
    else
        return Search(root->right, x);
}

//hàm xóa full cây nhị phân
void remove_all(node* &root){
    if(root != nullptr){
        remove_all(root->left);
        remove_all(root->right);
        delete root;
        root = nullptr;
    }
}

//hàm tìm max của cây nhị phân
int max_tree(node* root){
    while(root -> right != nullptr){
        root = root->right;
    }
    return root->data;
}



int main()
{
    node* root = nullptr;
    int n = 0;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        int x = 0;
        scanf("%d", &x);
        push_to_tree(root, x);
    }
    
    pop(root, 3);
//    printf("\n");
//    if(Search(root, 4) != nullptr)
//    {
//        printf("YES");
//    }
//    else
//    {
//        printf("No");
//    }
//    printf("\n");
    Duyet_RNL(root);
    //printf("%d", max_tree(root));
    remove_all(root);
    return 0;
}

