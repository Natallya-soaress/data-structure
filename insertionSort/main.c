#include <stdio.h>

void swap(int array[], int j){
  int t = array[j];
  array[j] = array[j + 1];
  array[j + 1] = t;
}

void insertion_sort(int array[], int n){
  int current, j, i;
  for (i = 1; i < n; i++){
    current = array[i];
    for (j = i; (j > 0) && current < array[j-1]; j--){
      array[j] = array[j - 1];
    }
    array[j] = current;
  }  
}

int main(){
  
  int max = 10;
  int array[10] = {28, 12, 0, 10, 14, 74, 88, 20, 50, 12};

  printf("\nUnordered list:");
  for (int i = 0; i < max - 1; i++)
    printf("\n%d, ", array[i]);
  printf("\n%d", array[max - 1]);
  
  insertion_sort(array, max);

  printf("\n\nOrdered list:");
  for (int i = 0; i < max - 1; i++)
      printf("\n%d, ", array[i]);

  printf("\n%d", array[max - 1]);

  return 0;
}