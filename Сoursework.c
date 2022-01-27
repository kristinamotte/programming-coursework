#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "treeNode.c"
#include "sort.h"
#include "addNode.h"
#include "remove.h"
#include "search.h"
#include "actions.c"
#include "sumOfAllNodes.h"

void handleAction(tree*);
int getNumber();
void scanFromFile(int[], int);

int main(int argc, char const *argv[]) {
	tree* root = NULL;

	handleAction(root);

	return 0;
}

int getNumber() {
	int number = -1;
	char line[100];

	while(fgets(line, sizeof(line), stdin)) {
        if(sscanf(line, "%i ",&number) != 1 ) {
            fprintf(stderr, "Please enter a number.\n");
            continue;
        }

        break;
    }

   return number;
}

void scanFromFile(int array[], int size) {
    FILE *ifp;
    ifp = fopen("Keys.txt", "r");

    for (int i = 0; i < size; i++) {
        fscanf(ifp, "%d", &array[i]);
    }

    fclose(ifp);
}

void handleAction(tree* root) {
	enum action act;
	int numberToAdd = 0;
	int numberToRemove = 0;
	int elementToSearch;
	int numberOfElements = 0;
	int arrOfKeys[1000];

	printf("\nPlease text back action you want to perform with your binary tree:\n0 - add manually;\n1 - add from file,\n2 - remove single element;\n3 - remove all elements;\n4 - find specific element;\n5 - print preorder;\n6 - print inorder;\n7 - print postorder;\n8 - sum of all nodes;\n9 - finish your work\n");

	act = getNumber();

	switch (act) {
		case add:
		printf("\nPlease enter how much elements you would like to add:\n");
		numberToAdd = getNumber();

		for (int i = 0; i < numberToAdd; i++) {
			int key;

			printf("\nPlease enter the key:\n");
			key = getNumber();

			root = addNode(root, key);
		}
		
		handleAction(root);
		break;

		case addFromFile:
		printf("\nPlease enter how much elements you have in the file\n");
		numberOfElements = getNumber();

		if (numberOfElements > 1000) {
			printf("\nMax number of key's can't be more than 1000. \n");
			handleAction(root);
			break;
		}

		scanFromFile(arrOfKeys, numberOfElements);

		for (int i = 0; i < numberOfElements; i++) {
        	root = addNode(root, arrOfKeys[i]);
    	}

		handleAction(root);
		break;

		case removeElement:
		printf("\nPlease enter how much elements you would like to remove:\n");
		numberToRemove = getNumber();

		for (int i = 0; i < numberToRemove; i++) {
			int key;

			printf("\nPlease enter the key:\n");
			key = getNumber();

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
		elementToSearch = getNumber();

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
		preorder(NULL, root, 0);
		printf("\n========================\n");

		handleAction(root);
		break;

		case printInorder:
		printf("\n========INORDER========\n");
		inorder(NULL, root, 0);
		printf("\n========================\n");

		handleAction(root);
		break;

		case printPostorder:
		printf("\n========POSTORDER========\n");
		postorder(NULL, root, 0);
		printf("\n========================\n");

		handleAction(root);
		break;

		case sumOfAllNodes:
		printf("\n========SUM OF ALL NODES========\n");
		printf("\n%d\n", calculateSum(root));
		printf("\n=================================\n");

		handleAction(root);
		break;

		case finishWork:
		printf("\nYour work has finished :)\n");
		break;

		default:
		printf("\nSorry, but currently we do not support such an action. Please choose something else.\n");
		handleAction(root);
		break;
	}
}
