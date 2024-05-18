#include <iostream>
#include <cstring>
#include <vector>
#include "set"
#include <sstream>
#include "math.h"
#include "queue"
#include "algorithm"
#include <stack>
#include "fstream"
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    int height;
};

node *create_node(int x){
    node *newnode = new node;
    newnode->data = x;
    newnode->left = newnode->right = nullptr;
    newnode->height = 0;
    return newnode;
}

int height(node *t){
    if (t == nullptr)
        return -1;
    else
        return t->height;
}

void Left_Left(node *&k){
    node *k1 = k->left;
    k->left = k1->right;
    k1->right = k;
    k->height = max(height(k->left), height(k->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k = k1;
}

void Right_Right(node *&k){
    node *k1 = k->right;
    k->right = k1->left;
    k1->left = k;
    k->height = max(height(k->left), height(k->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k = k1;
}

void Left_Right(node *&k){
    Right_Right(k->left);
    Left_Left(k);
}

void Right_Left(node *&k){
    Left_Left(k->right);
    Right_Right(k);
}

void balance(node *&k){
    if (k == nullptr)
        return;
    if (height(k->left) - height(k->right) > 1){
        if (height(k->left->left) >= height(k->left->right))
            Left_Left(k);
        else
            Left_Right(k);
    }
    else if (height(k->right) - height(k->left) > 1){
        if (height(k->right->right) >= height(k->right->left))
            Right_Right(k);
        else
            Right_Left(k);
    }
    k->height = max(height(k->left), height(k->right)) + 1;
}

void push(node *&root, int x){
    if (root == nullptr){
        node *newnode = create_node(x);
        root = newnode;
    }
    if (x < root->data)
        push(root->left, x);
    else if (x > root->data)
        push(root->right, x);
    else
        return; // root->data = x
    balance(root);
}

void pop(node *&root, int x){
    if (root == nullptr)
        return;
    if (x < root->data)
        pop(root->left, x);
    else if (x > root->data)
        pop(root->right, x);
    else{
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr && root->right != nullptr){
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->left != nullptr && root->right == nullptr){
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else{
            node *temp = root->right;
            while (temp->left != nullptr)
                temp = temp->left;
            swap(root->data, temp->data);
            pop(root->right, x);
        }
    }
    balance(root);
}


void LNR(node *root){
    if (root != nullptr){
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}

void LRN(node *root){
    if (root != nullptr){
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}

void BFS(node *root){
    queue<node *> Q;
    Q.push(root);
    while (!Q.empty()){
        node *temp = Q.front();
        Q.pop();
        cout << temp->data << " ";
        if (temp->left != nullptr)
            Q.push(temp->left);
        if (temp->right != nullptr)
            Q.push(temp->right);
    }
}

void remove_all(node *&root){
    if (root != nullptr){
        remove_all(root->left);
        remove_all(root->right);
        delete root;
        root = nullptr;
    }
}

int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    node *root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x = 0;
        cin >> x;
        push(root, x);
    }
    // pop(root,1);
    // LRN(root);
    // BFS(root);
    BFS(root);
    remove_all(root);
    return 0;
}
