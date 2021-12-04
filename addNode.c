#include <stdio.h>

tree* createTreeNode(int key) {
	tree* newTreeNode = (tree*) malloc (sizeof(tree));
	if (newTreeNode == NULL) {
		printf("\nOut of memory :(\n");
		return newTreeNode;
	}

	newTreeNode->key = key;
	newTreeNode->left = NULL;
	newTreeNode->right = NULL;
	printf("\n Key %d has added\n", key);

	return newTreeNode;
}

tree* addNode(tree* root, int key) {
	if (root == NULL) {
		root = createTreeNode(key);
	} else {
		if (key < root->key) {
			root->left = addNode(root->left, key);
		} else {
			root->right = addNode(root->right, key);
		}
	}

	return root;
}