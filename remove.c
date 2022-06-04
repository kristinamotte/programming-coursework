#include <stdio.h>

/* Возвращает ноду с минимальным значением key, 
	которое может быть найдедо в данном дереве. */
tree* minValueNode(tree* node) {
	tree* current = node;
	
	/* поиск крайнего левого листа */
	while (current && current->left != NULL) {
    	current = current->left;
	}
 
    return current;
}

/* Дано бинарное дерево и ключ, эта функция
   удаляет ключ и возвращает новый root */
tree* deleteNode(tree* root, int key) {
    if (root == NULL) {
		printf("\nThe tree doesn't contain such key\n");
        return root;
	}
	
	// Если ключ меньше, чем root ключ,
    // значит он находится в левом поддереве
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
	}
	// Если ключ больше, чем root ключ,
    // значит он находится в правом поддереве
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
	} 
	// Если ключ такой же как root ключ,
    // значит это нода, которую нужно удалить
	else {
		// нода с одним единственным наследником или без него
        if (root->left == NULL) {
            tree* temp = root->right;
            free(root);
			printf("\nKey %d has removed\n", key);

            return temp;
        } else if (root->right == NULL) {
            tree* temp = root->left;
            free(root);
			printf("\nKey %d has removed\n", key);

            return temp;
        }

		// нода с двумя наследниками:
        // Получение inorder преемника
        // (самый маленький в правом поддереве)
        tree* temp = minValueNode(root->right);
	
		// Копировать ключ преемника в эту ноду
        root->key = temp->key;

		// Удалить inorder преемника
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

/* Освобождает полностью все дерево */
void freeTree(tree** root) {
	if (*root != NULL) {
		freeTree(&((*root)->left));
		freeTree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}