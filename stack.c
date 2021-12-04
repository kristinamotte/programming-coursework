#include <stdio.h>

stack* push(tree* root, stack* top) {
    stack* node = (stack*)malloc(sizeof(stack));

    if(node == NULL) {
        printf("\nMemory Overflow\n");
		return node;
    }

    node->element = root;
	node->next = top;

    return node;
}

void pop(stack** top) {
	if (*top != NULL) {
		stack* remove = *top;
        *top = remove->next;
		remove->element = NULL;
		remove->next = NULL;

		free(remove);
		remove = NULL;
	}
}