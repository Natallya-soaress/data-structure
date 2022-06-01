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

treeNode *root = create_tree();
root = insert(root, 25);
//root = insert(root, 28);
root = insert(root, 20);
root = insert(root, 27);
root = insert(root, 29);
root = insert(root, 19);
root = insert(root, 21);
root = insert(root, 28);

printf("\nPrint in order:\n");
inOrder(root);

int leafNode = amountLeafNode(root);
printf("\n%d leaf nodes", leafNode);

int noLeafNode = amountNoLeafNode(root);
printf("\n%d no leaf nodes", noLeafNode);

/*
printf("\nPrint pos order:\n");
posOrder(root);

printf("\nPrint pre order:\n");
preOrder(root);

printf("\nPrint after delete node 20: \n");
root = releaseNode(root, 20);
inOrder(root);

printf("\nPrint after delete root: \n");
releaseTree(root); */


/*
Testes de tempo
   struct timeval t0;
   struct timeval t1;
   float elapsed;
   int N = 100001;
   int *dados =(int*) malloc(sizeof(int)*N);

   treeNode *root = create_tree();
   

   srand(time(NULL));
      for(int i = 0; i <=  N; i++){
         dados[i] = (rand() % 1000000);
    }

   for(int i=0; i < N; i++){
        root = insert(root, dados[i]);
   }

   gettimeofday(&t0, 0);
   preOrder(root);
   gettimeofday(&t1, 0);
    
   elapsed = timedifference_msec(t0, t1);

   printf("Code executed in %f milliseconds.\n", elapsed);

*/    

}