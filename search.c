#include <stdio.h>

tree* search(tree* root, int key) {
    // Дефолтный кейс: root пустой или ключ такой же ка значение root
    if (root == NULL || root->key == key) {
        printf("\nThe key has found! %d\n", key);
        return root;
    }
    
    // Key больше, чем root key
    if (root->key < key) {
        return search(root->right, key);
    }
 
    // Key меньше, чем root key
    return search(root->left, key);
}