#pragma once
#include "typedefs.h"

template <typename T>
struct TreeNode {
	T data;	
	TreeNode* left;
	TreeNode* right;
};

template <typename T>
class Tree {
	TreeNode<T>* root;

public:
	Tree() {
		this->root = nullptr;
	}

	void add(T data) {
		root = add(data, root);
	}
	TreeNode<T>* add(T data, TreeNode<T>* node) {
		if (node == nullptr) {
			node = new TreeNode<T>;
			node->data = data;
			node->left = nullptr;
			node->right = nullptr;
		}
		else if (data < node->data)
			node->left = add(data, node->left);
		else node->right = add(data, node->right);
		return node;
	}
	
	void deleteNode(TreeNode<T>* node) {
		if (node != nullptr) {
			deleteNode(node->left);
			deleteNode(node->right);
			delete node;
		}
	}

	void inorder(iteratorCallback<T> callback) {
		inorder(root, callback);
	}
	//обход в симметричном порядке
	void inorder(TreeNode<T>* current, iteratorCallback<T> callback) {
		if (current != nullptr) {
			inorder(current->left, callback);
			callback(&(current->data));
			inorder(current->right, callback);
		}
	}
	void preorder(iteratorCallback<T> callback) {
		preorder(root, callback);
	}
	//обход в прямом порядке
	void preorder(TreeNode<T>* current, iteratorCallback<T> callback) {
		if (current != nullptr) {
			callback(&(current->data));
			preorder(current->left, callback);
			preorder(current->right, callback);
		}
	}
	void postorder(iteratorCallback<T> callback) {
		postorder(root, callback);
	}
	//обход в постфиксной форме
	void postorder(TreeNode<T>* current, iteratorCallback<T> callback) {
		if (current != nullptr) {
			postorder(current->left, callback);
			postorder(current->right, callback);
			callback(&(current->data));
		}
	}

	template <typename K>
	T* search(K &item) {
		return search(root, item);
	}
	template <typename K>
	T* search(TreeNode<T>* node, K& item) {
		if (node == nullptr)
			return nullptr;
		if (node->data < item)
			return search(node->right, item);
		else if (node->data > item)
			return search(node->left, item);
		return &(node->data);
	}
};