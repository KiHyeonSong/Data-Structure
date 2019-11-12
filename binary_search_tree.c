#include <stdio.h>
#include <stdlib.h>


typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, *right;
}TreeNode;

TreeNode* new_node(int item);
TreeNode* search(TreeNode* node, int key);
TreeNode* min_value_node(TreeNode* node);
TreeNode* insert_node(TreeNode* root, int key);
TreeNode* delete_node(TreeNode* root, int key);
void inorder(TreeNode* root);

int main()
{
	TreeNode* root = NULL;
	TreeNode* temp = NULL;

	root = insert_node(root, 1);
	root = insert_node(root, 3);
	root = insert_node(root, 4);
	root = insert_node(root, 6);
	root = insert_node(root, 7);
	root = insert_node(root, 8);
	root = insert_node(root, 10);
	root = insert_node(root, 13);
	root = insert_node(root, 14);
	root = insert_node(root, 18);
	root = insert_node(root, 19);
	root = insert_node(root, 21);
	root = insert_node(root, 24);
	root = insert_node(root, 37);
	root = insert_node(root, 40);
	root = insert_node(root, 45);
	root = insert_node(root, 71);
	//printf("삭제 전\n");
	inorder(root);
	//root = delete_node(root, 50);
	//root = delete_node(root, 10);
	//printf("\n삭제 후\n");
	//inorder(root);
	printf("\n");

	// printf("이진 탐색 트리 중위 순회 결과\n");
	inorder(root);
	if (search(root, 7) != NULL)
		// printf("\n이진 탐색 트리에서 7을 발견함\n");
		printf("\n 7 OK \n");
	else
		// printf("\n이진 탐색 트리에서 7을 발견못함\n");
		printf("\n 7 NO \n");

	return 1;
}

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* search(TreeNode* node, int key)
{
	while (node != NULL)
	{
		if (key == node->key)
			return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL) return new_node(key);

	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	return node;
}

TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL) return root;
	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp= min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}