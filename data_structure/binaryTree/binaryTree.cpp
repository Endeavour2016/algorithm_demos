/*******************************************************
> File Name: BinaryTree.cpp
> Author: zlm
> Mail: 
> Created Time: 2018年8月6日 星期一
********************************************************/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stdlib.h>
using namespace std;

/// definition of tree node 
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {};
};

// create a binary tree
void creatBinaryTree(Node* &root) {
    int x;
    cin >> x;
    if (x == -1) {
        root = nullptr;
        return;
    }
    root = new Node(x);
    creatBiTree(root->left);
    creatBiTree(root->right);
}

// visit node T
void visit(Node *T) {
    if (T->val != -1)
        cout << T->val << " ";
}

// Recursive Traversal
// 1.preorder traversal method
void preOrder(Node *root)
{
    if (root != nullptr) {
        visit(root);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 2.inorder traversal
void inOrder(Node *root) {
    if (root != nullptr) {
        inOrder(root->left);
        visit(root);
        inOrder(root->right);
    }
}

// 3.postorder traversal
void postOrder(Node *root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        visit(root);
    }
}


// Traverse non-recursively
// 先序遍历: stack
void preOrderF(Node *root) {
    if (root == nullptr)
        return;

    stack<Node *> s;
    s.push(root); // 先存放根节点

    Node *p = nullptr;

    while (!s.empty()) {
        p = s.top();
        s.pop();
        
        // visit root first
        cout << p->val << " ";
        
        if (p->right)
            s.push(p->right);
        if (p->left)
            s.push(p->left);
    }
}

// 中序遍历
void inOrderF(Node *root)
{
    if (root == nullptr)
        return;
    stack<Node *> s;
    Node *p = root;

    while (p || !s.empty()) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        }
        else {
            p = s.top();
            s.pop();
            cout << p->val << " ";
            p = p->right;
        }
    }
}

// 后序遍历
// 思路：先访问root,再访问right, left. 将该访问序列反序输出即可得到后序遍历的效果。
void postOrderF(Node *root)
{
    if (root == nullptr)
        return;
    stack<Node *> s;

    vector<int> rs;
    
    s.push(root);
    
    Node *p = nullptr;

    while (!s.empty())
    {
        p = s.top();
        s.pop();
        rs.insert(rs.begin(), p->val);

        if (p->left)
            s.push(p->left);
        if (p->right)
            s.push(p->right);
    }

    for (int i = 0; i < rs.size(); i++)
        cout << rs[i] << " ";
}

int main(int argc, char *argv[])
{
    Node *root;
    //二叉树的创建(根据先序创建)
    creatBinaryTree(root);

    preOrderF(root);
    cout << endl;
    
    inOrderF(root);
    cout << endl;
    
    postOrderF(root);
    cout << endl;

    system("pause");
    return 0;
}
