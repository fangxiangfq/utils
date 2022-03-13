#pragma once
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include "namespace_def.h"

NameSpace_Beg(utils)

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
TreeNode<T>* create_binarytree(It& beg, It end, const T& invalid)
{
	if (beg < end && *beg != invalid) {
		TreeNode<T>* root = new TreeNode<T>(*beg);
		TreeNode<T>* l = create_binarytree<T>((beg < end) ? ++beg : end, end, invalid);
		TreeNode<T>* r = create_binarytree<T>((beg < end) ? ++beg : end, end, invalid);
		root->left_ = l;
		root->right_ = r;
		return root;
	}

	return nullptr;
}

template<typename T>
void distroy_binarytree(TreeNode<T>*& root)
{
	if (root) {
		distroy_binarytree(root->left_);
		distroy_binarytree(root->right_);
		delete root;
		root = nullptr;
	}
}

template<typename T>
std::vector<std::vector<T>> level_order_traverse(TreeNode<T>*& root)
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
std::vector<std::vector<T>> zigzag_level_order_traverse(TreeNode<T>*& root)
{
	std::queue<TreeNode<T>*> q;
	std::vector<std::vector<T>> ret;
	if (root) {
		q.push(root);
	}
	bool reverse = false;
	while (!q.empty()) {
		const int levelnum = q.size();
		int curnum = levelnum;
		std::vector<T> level(total);
		while (curnum > 0) {
			auto node = q.front();
			q.pop();
			if (reverse) {
				level[curnum - 1] = node->val_;
			}
			else {
				level[levelnum - curnum] = node->val_;
			}
			
			if (node->left_) {
				q.push(node->left_);
			}
			if (node->right_) {
				q.push(node->right_);
			}
			--curnum;
		}

		ret.push_back(level);

	}

	return ret;
}

template<typename T>
bool symmetric(TreeNode<T>* left, TreeNode<T>* right) 
{
	if (!left && !right) {
		return true;
	}

	if (!left || !right || left->val_ != right->val_) {
		return false;
	}

	return symmetric(left->left_, right->right_) && symmetric(left->right_, right->left_);
}

template<typename T>
bool symmetric(TreeNode<T>* root) 
{
	if (!root) {
		return true;
	}

	return symmetric(root->left_, root->right_);
}

template<typename T>
bool is_same_tree(TreeNode<T>* p, TreeNode<T>* q) 
{
	if (!p && !q) {
		return true;
	}

	if (!p || !q || p->val_ != q->val_) {
		return false;
	}

	return is_same_tree(p->left_, q->left_) && is_same_tree(p->right_, q->right_);
}

template<typename T>
void preorder_traverse(TreeNode<T>* root, std::vector<T>& ret) 
{
	if (root) {
		ret.push_back(root->val_);
		preorder_traverse(root->left_, ret);
		preorder_traverse(root->right_, ret);
	}
}

template<typename T>
void inorder_traverse(TreeNode<T>* root, std::vector<T>& ret) 
{
	if (root) {
		inorder_traverse(root->left_, ret);
		ret.push_back(root->val_);
		inorder_traverse(root->right_, ret);
	}
}

template<typename T>
void postorder_traverse(TreeNode<T>* root, std::vector<T>& ret) 
{
	if (root) {
		postorder_traverse(root->left_, ret);
		postorder_traverse(root->right_, ret);
		ret.push_back(root->val_);
	}
}

template<typename T>
void preorder_traverse_tterative(TreeNode<T>* root, std::vector<T>& ret) 
{
	TreeNode<T>* cur = root;
	std::stack<TreeNode<T>*> s;
	while (cur || !s.empty()) {
		if (cur) {
			ret.push_back(cur->val_);
			s.push(cur);
			cur = cur->left_;
		}
		else {
			cur = s.top();
			s.pop();
			cur = cur->right_;
		}
	}
}

template<typename T>
void inorder_traverse_iterative(TreeNode<T>* root, std::vector<T>& ret) 
{
	TreeNode<T>* cur = root;
	std::stack<TreeNode<T>*> s;
	while (cur || !s.empty()) {
		if (cur) {
			s.push(cur);
			cur = cur->left_;
		}
		else {
			cur = s.top();
			s.pop();
			ret.push_back(cur->val_);
			cur = cur->right_;
		}
	}
}

template<typename T>
void postorder_traverse_iterative(TreeNode<T>* root, std::vector<T>& ret) 
{
	TreeNode<T>* cur = root;
	std::stack<std::pair<TreeNode<T>*, bool>> s;
	while (cur || !s.empty()) {
		if (cur) {
			s.emplace(cur, false);
			cur = cur->left_;
		}
		else {
			if (!s.top().second) {
				s.top().second = true;
				cur = s.top().first->right_;
			}
			else {
				ret.push_back(s.top().first->val_);
				s.pop();
			}
		}
	}
}

NameSpace_End(utils)