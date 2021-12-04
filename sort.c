#include <stdio.h>

void printCurrentLevel(tree* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d\n", root->key);
    } else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(tree* root) {
    if (root == NULL) {
        return 0;
    } else {
        int lheight = height(root->left);
        int rheight = height(root->right);
 
        if (lheight > rheight) {
            return (lheight + 1);
        } else {
            return (rheight + 1);
        }
    }
}

void preorder(tree* root) { 
	if (root != NULL) {
		printf("%d\n", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(tree* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d\n", root->key);
		inorder(root->right);
	}
}

void postorder(tree* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->key);
	}
}

void levelorder(tree* root) {
    int h = height(root);

    for (int i = 1; i <= h; i++) {
        printCurrentLevel(root, i);
    }
}