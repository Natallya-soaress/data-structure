#include <stdio.h>

void swap(int array[], int i, int smaller){
  int t = array[i];
  array[i] = array[smaller];
  array[smaller] = t;
}

void selection_sort(int array[], int n){

  int smaller;
  
  for (int i = 0; i < n - 1; i++){
    smaller = i;
      for (int j = i +1; j < n; j++){
        if (array[j] < array[smaller]){
          smaller = j;
        }
      }
      if(i != smaller){
        swap(array, i, smaller);
      }
    }
}

int main(){
  
  int max = 10;
  int array[10] = {28, 12, 0, 10, 14, 74, 88, 20, 50, 12};

  printf("\nUnordered list:");
  for (int i = 0; i < max - 1; i++)
      printf("\n%d, ", array[i]);
  printf("\n%d", array[max - 1]);
  
  selection_sort(array, max);

  printf("\n\nOrdered list:");
  for (int i = 0; i < max - 1; i++)
      printf("\n%d, ", array[i]);

  printf("\n%d", array[max - 1]);

  return 0;
}