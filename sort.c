#include <stdio.h>
#include <string.h>

typedef struct Trunk {
    struct Trunk *prev;
    char *str;
} trunk;

void showTrunks(trunk *p) {
    if (p == NULL) {
        return;
    }
 
    showTrunks(p->prev);
	printf("%s", p->str);
}

void preorder(trunk *prev, tree* root, int isLeft) { 
	if (root != NULL) {
		char prev_str[15] = "    ";
    	trunk *trunkEx = (trunk*) malloc (sizeof(trunk));
		trunkEx->prev = prev;
		trunkEx->str = prev_str;

		if (!prev) {
        	trunkEx->str = "———";
    	} else if (isLeft) {
        	trunkEx->str = ".———";
			strcpy(prev_str, "   |");
    	} else {
        	trunkEx->str = "`———";
        	prev->str = prev_str;
    	}
 
    	showTrunks(trunkEx);
		printf(" %d\n", root->key);
 
    	if (prev) {
        	prev->str = prev_str;
    	}

    	trunkEx->str = "   |";
		
		preorder(trunkEx, root->left, 1);
		preorder(trunkEx, root->right, 0);
	}
}

void inorder(trunk *prev, tree* root, int isLeft) {
	if (root != NULL) {
		char prev_str[15] = "    ";
    	trunk *trunkEx = (trunk*) malloc (sizeof(trunk));
		trunkEx->prev = prev;
		trunkEx->str = prev_str;

		inorder(trunkEx, root->left, 1);

		if (!prev) {
        	trunkEx->str = "———";
    	} else if (isLeft) {
        	trunkEx->str = ".———";
			strcpy(prev_str, "   |");
    	} else {
        	trunkEx->str = "`———";
        	prev->str = prev_str;
    	}
 
    	showTrunks(trunkEx);
		printf(" %d\n", root->key);
 
    	if (prev) {
        	prev->str = prev_str;
    	}

    	trunkEx->str = "   |";

		inorder(trunkEx, root->right, 0);
	}
}

void postorder(trunk *prev, tree* root, int isLeft) {
	if (root != NULL) {
		char prev_str[15] = "    ";
    	trunk *trunkEx = (trunk*) malloc (sizeof(trunk));
		trunkEx->prev = prev;
		trunkEx->str = prev_str;

		postorder(trunkEx, root->left, 1);
		postorder(trunkEx, root->right, 0);
		
		if (!prev) {
        	trunkEx->str = "———";
    	} else if (isLeft) {
        	trunkEx->str = ".———";
			strcpy(prev_str, "   |");
    	} else {
        	trunkEx->str = "`———";
        	prev->str = prev_str;
    	}
 
    	showTrunks(trunkEx);
		printf(" %d\n", root->key);
 
    	if (prev) {
        	prev->str = prev_str;
    	}

    	trunkEx->str = "   |";

	}
}