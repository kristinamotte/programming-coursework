#include <stdio.h>

int calculateSum(tree* root) {
    int sum = 0, sumLeft = 0, sumRight = 0;

    if(root == NULL) {  
        printf("\nTree is empty\n");  
        return 0;  
    } else {  
        // Сумма узлов, представленних в левом поддереве
        if(root->left != NULL)  
            sumLeft = calculateSum(root->left);  
          
        // Сумма узлов, представленных в правом поддереве
        if(root->right != NULL)  
              sumRight = calculateSum(root->right);  
          
        // Сумма всех узлов при помощи добавления sumLeft, sumRight и корневого узла
        sum = root->key + sumLeft + sumRight;   
        return sum;  
  }        
}