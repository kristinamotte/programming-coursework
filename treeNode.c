#include <stdio.h>

typedef struct treeNode {
	struct treeNode * left;
	int key;
	struct treeNode * right;
} tree;