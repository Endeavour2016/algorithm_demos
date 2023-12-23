/**
 * 二叉搜索树的定义
 * created by zlm 2018-7-18 9:48
 */
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Definition of Binary Search Tree
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 1. 二叉树的插入
// 这里返回根结点是为了便于递归
TreeNode* InsertBST(TreeNode* root, int x) {
	// root为空，插入新结点
	if (root == nullptr) {
		root = new TreeNode(x);
		root->left = root->right = nullptr;
	} else {
		if (x < root->val)
			root->left = InsertBST(root->left, x);
		else if (x > root->val)
			root->right = InsertBST(root->right, x);
	}
	return root;
}

// 2. 二叉树的查找
TreeNode *FindElem(TreeNode *root, int x) {
	if (!root)
		return nullptr;

	if (x == root->val)
		return root;
	else if (x < root->val)
		return FindElem(root->left, x);
	else
		return FindElem(root->right, x);
}

// 3.preorder traversal(recursive)
void preOrderTraverse(TreeNode *root) {
	if (root != nullptr) {
		cout << root->val << endl;
		preOrderTraverse(root->left);
		preOrderTraverse(root->right);
	}
}

// 4.inorder traversal(recursive)
void InOrderTraverse(TreeNode *root) {
	if (root != nullptr) {
		InOrderTraverse(root->left);
		cout << root->val << endl;
		InOrderTraverse(root->right);
	}
}
// 5.postorder traversal(recursive)
void PostOrderTraverse(TreeNode *root) {
	if (root != nullptr) {
		PostOrderTraverse(root->left);
		PostOrderTraverse(root->right);
		cout << root->val << endl;
	}
}

// traversal non-recursively
/**
 * 1-先序遍历
 * 先把root入栈,
 * 1. 取出栈顶，访问；
 * 2. 把右子结点入栈；
 * 3. 把左子结点入栈。循环此过程
 */
 void preOrder(TreeNode *root) {
	if (root == nullptr)
		return;

	stack<TreeNode *> sk;
	TreeNode *tmp;
	
	sk.push(root);
	while (!sk.empty()) {
		tmp = sk.top();
		sk.pop();
		cout << tmp->val << " ";

		if (tmp->right != nullptr)
			sk.push(tmp->right);

		if (tmp->left != nullptr)
			sk.push(tmp->left);
	}
	cout << endl;
}

int main(int argc, char * argv[]) {
	TreeNode *root = new TreeNode(10);
	int d = 0;
	for (int i = 1; i <= 4; i++) {
		cin >> d;
		InsertBST(root, d);
	}

	cout << "preOrder with recursive method: \n";
	preOrderTraverse(root);

	cout << "preOrder without recursive method: \n";
	preOrder(root);

	return 0;
}
