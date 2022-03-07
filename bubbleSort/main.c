#include <stdio.h>

void swap(int array[], int j){
  int t = array[j];
  array[j] = array[j + 1];
  array[j + 1] = t;
}

void bubble_sort(int array[], int n){
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < n - i - 1; j++){
        if (array[j] > array[j + 1]){
          swap(array, j);
        }
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
  
  bubble_sort(array, max);

  printf("\n\nOrdered list:");
  for (int i = 0; i < max - 1; i++)
      printf("\n%d, ", array[i]);
  printf("\n%d", array[max - 1]);
  
  return 0;
}