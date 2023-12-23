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
    creatBinaryTree(root->left);
    creatBinaryTree(root->right);
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



/**非递归方式遍历**/
// 先序遍历
// 1、访问根节点
// 2、访问左子节点
// 3、访问右子节点
// 为什么用栈呢？先访问的左子节点，访问完之后需要能找到右子节点的指针，然后才能访问右子节点
// 因此需要提前存放右子节点指针，最后再取出其指针，满足“先进后出的特性”

void preOrderF(Node *root) {
    if (root == nullptr) {
        return;
    }

    stack<Node *> s;
    s.push(root); // 先存放根节点
    Node *p = nullptr;

    while (!s.empty()) {
        p = s.top();
        s.pop();
        cout << p->val << " ";
        if (p->right != nullptr)
            s.push(p->right);
        if (p->left != nullptr)
            s.push(p->left);
    }
}

// 中序遍历
// 先遍历左子树，再遍历根节点，最后遍历右子树
// 1、从树的root开始，先找到左子树最底层的叶子节点(左子节点)
// 2、访问左子节点->访问当前根节点->访问右子树(这个过程跟步骤1一样)
// 3、为了保证访问完左子节点之后，能够找到其根节点，步骤1在遍历左子树的过程中，需要按照
// 遍历的顺序将左子树的根节点入栈，这样出栈时即可保证按中序来访问根节点
void inOrderF(Node *root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> s;
    Node* p = root;
    while (p != nullptr || !s.empty()) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
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

    while (!s.empty()) {
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
