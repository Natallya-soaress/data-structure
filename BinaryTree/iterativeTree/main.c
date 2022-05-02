#include <stdio.h>
#include <stdlib.h>


#include "binaryTree.c"
#include "binaryTree.h"

int main(){

/*
          25

    20          28

 19   21      27   29

*/

   tNode *root = create_tree();
   root = insert(root, 25);
  // printf("key root %d", root->key);
   root = insert(root, 20);
  // printf("2");
   root = insert(root, 28);
   root = insert(root, 28);
   //printf("3");
   inOrder(root);
   printf("Print in order: \n");

}