#include <stdlib.h>
#include <stdio.h>

#include "treeNode.c"
#include "stackNode.c"
#include "sort.h"
#include "addNode.h"
#include "remove.h"
#include "stack.h"
#include "search.h"
#include "actions.c"

void handleAction(tree*);

int main(int argc, char const *argv[]) {
	tree* root = NULL;

	handleAction(root);

	return 0;
}

void handleAction(tree* root) {
	enum action act;
	int numberToAdd;
	int numberToRemove;
	int elementToSearch;

	printf("\nPlease text back action you want to perform with your binary tree:\n0 - add;\n1 - remove single element;\n2 - remove all elements;\n3 - find specific element;\n4 - print preorder;\n5 - print inorder;\n6 - print postorder;\n7 - print levelorder;\n8 - finish your work\n");

	scanf("%d", &act);

	switch (act) {
		case add:
		printf("\nPlease enter how much elements you would like to add:\n");
		scanf("%d", &numberToAdd);

		for (int i = 0; i < numberToAdd; i++) {
			int key;

			printf("\nPlease enter the key:\n");
			scanf("%d", &key);

			root = addNode(root, key);
		}
		
		handleAction(root);
		break;

		case removeElement:
		printf("\nPlease enter how much elements you would like to remove:\n");
		scanf("%d", &numberToRemove);

		for (int i = 0; i < numberToRemove; i++) {
			int key;

			printf("\nPlease enter the key:\n");
			scanf("%d", &key);

			root = deleteNode(root, key);
		}
		
		handleAction(root);
		break;

		case removeAll:
		freeTree(&root);
		printf("\nAll elements have removed\n");
		
		handleAction(root);
		break;

		case searchElement:
		printf("\nPlease enter which key you would like to find:\n");
		scanf("%d", &elementToSearch);

		tree* temp = search(root, elementToSearch);

		if (temp != NULL) {
			printf("\nKey %d has sucessfully found:\n", elementToSearch);
		} else {
			printf("\nKey %d do not exist in that tree\n", elementToSearch);
		}
		
		handleAction(root);
		break;
		
		case printPreorder:
		printf("\n========PREORDER========\n");
		preorder(root);
		printf("\n========================\n");

		handleAction(root);
		break;

		case printInorder:
		printf("\n========INORDER========\n");
		inorder(root);
		printf("\n========================\n");

		handleAction(root);
		break;

		case printPostorder:
		printf("\n========POSTORDER========\n");
		postorder(root);
		printf("\n========================\n");

		handleAction(root);
		break;

		case printLevelorder:
		printf("\n========LEVELORDER========\n");
		levelorder(root);
		printf("\n========================\n");

		handleAction(root);
		break;

		case finishWork:
		printf("\nYour work has finished :)\n");
		break;

		default:
		printf("\nSorry, but currently we do not support such an action. Please choose something else.\n");
		handleAction(root);
		break;
	};
}
