#pragma once
#include <algorithm>
#include <vector>
#include <queue>
#include "namespace_def.h"

NameSpace_Beg(MyAlgorithm)
NameSpace_Beg(BinaryTree)

template<typename T>
struct TreeNode {
	T val_;
	TreeNode *left_;
	TreeNode *right_;

	TreeNode() : val_(), left_(nullptr), right_(nullptr) {}
	TreeNode(const T& x) : val_(x), left_(nullptr), right_(nullptr) {}
	TreeNode(const T& x, TreeNode *left, TreeNode *right) : val_(x), left_(left), right_(right) {}
};

template<typename T, typename It>
TreeNode<T>* createBinaryTree(It& beg, It end, const T& invalid)
{
	if (beg < end && *beg != invalid) {
		TreeNode<T>* root = new TreeNode<T>(*beg);
		TreeNode<T>* l = createBinaryTree<T>((beg < end) ? ++beg : end, end, invalid);
		TreeNode<T>* r = createBinaryTree<T>((beg < end) ? ++beg : end, end, invalid);
		root->left_ = l;
		root->right_ = r;
		return root;
	}

	return nullptr;
}

template<typename T>
void distroyBinaryTree(TreeNode<T>*& root)
{
	if (root) {
		distroyBinaryTree(root->left_);
		distroyBinaryTree(root->right_);
		delete root;
		root = nullptr;
	}
}

template<typename T, typename F>
void levelOrderTraverse(TreeNode<T>*& root, F func)
{
	std::queue<TreeNode<T>*> q;
	if (root) {
		q.push(root);
	}

	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		func(p->val_);
		if (p->left_) {
			q.push(p->left_);
		}

		if (p->right_) {
			q.push(p->right_);
		}
	}
}

template<typename T>
std::vector<std::vector<T>> levelOrderTraverse(TreeNode<T>*& root)
{
	std::queue<TreeNode<T>*> q;
	std::vector<std::vector<T>> ret;
	if (root) {
		q.push(root);
	}

	while (!q.empty()) {
		int levelnum = q.size();
		std::vector<T> level;
		while (levelnum > 0) {
			auto node = q.front();
			q.pop();
			level.push_back(node->val_);

			if (node->left_) {
				q.push(node->left_);
			}
			if (node->right_) {
				q.push(node->right_);
			}
			--levelnum;
		}

		ret.push_back(level);

	}

	return ret;
}

template<typename T>
bool isSymmetric(TreeNode<T>* left, TreeNode<T>* right) {
	if (!left && !right) {
		return true;
	}

	if (!left || !right || left->val_ != right->val_) {
		return false;
	}

	return isSymmetric(left->left_, right->right_) && isSymmetric(left->right_, right->left_);
}

template<typename T>
bool isSymmetric(TreeNode<T>* root) {
	if (!root) {
		return true;
	}

	return isSymmetric(root->left_, root->right_);
}

template<typename T>
bool isSameTree(TreeNode<T>* p, TreeNode<T>* q) {
	if (!p && !q) {
		return true;
	}

	if (!p || !q || p->val_ != q->val_) {
		return false;
	}

	return isSameTree(p->left_, q->left_) && isSameTree(p->right_, q->right_);
}

template<typename T>
void preorderTraverse(TreeNode<T>* root, std::vector<T>& ret) {
	if (root) {
		ret.push_back(root->val_);
		preorderTraverse(root->left_, ret);
		preorderTraverse(root->right_, ret);
	}
}

template<typename T>
void inorderTraverse(TreeNode<T>* root, std::vector<T>& ret) {
	if (root) {
		inorderTraverse(root->left_, ret);
		ret.push_back(root->val_);
		inorderTraverse(root->right_, ret);
	}
}

template<typename T>
void postorderTraverse(TreeNode<T>* root, std::vector<T>& ret) {
	if (root) {
		postorderTraverse(root->left_, ret);
		postorderTraverse(root->right_, ret);
		ret.push_back(root->val_);
	}
}

NameSpace_End(BinaryTree)
NameSpace_End(MyAlgorithm)