#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct list{
    int no[max];
    int end;
};

List create_list(){
    List lst;
    lst = (List) malloc(sizeof(struct list));

    if(lst != NULL){
        lst->end = 0;
    }
    return lst;
}

int empty_list(List lst){
    if(lst->end==0)
        return 1; 
    else
        return 0; 
}

int full_list(List lst){
    if(lst->end==max)
        return 1; 
    else
        return 0; 
}

int insert_ord(List lst, int elem){
    if(lst==NULL || full_list(lst)==1)
        return 0; 
    
    if(empty_list(lst)==1 || elem>=lst->no[lst->end-1]){
        lst->no[lst->end]=elem; 
    }
    else{
        int i, aux=0;
        while(elem>=lst->no[aux]) 
            aux++;
        for(i=lst->end;i>aux;i--)
            lst->no[i]=lst->no[i-1];
        lst->no[aux]=elem; 
    }
    lst->end++;
    return 1; 
}

int remove_ord(List lst, int elem){
    if(lst==NULL || empty_list(lst)==1 || elem<lst->no[0] || elem>lst->no[lst->end-1])
        return 0; 
    int i, aux=0;

    while(aux<lst->end && lst->no[aux]<elem)
        aux++;
    if(aux==lst-> end || lst->no[aux]>elem)
        return 0; 
  
    for(i=aux+1;i<lst->end;i++)
        lst->no[i-1]=lst->no[i];
    lst->end--; 
    return 1; 
}

List print_list(List lst){
    int i;
    if(lst->end<=0)
        printf("Empty list!\n\n");
    else{
        printf("List: ");
        for(i=0;i<lst->end;i++){
            printf("%d ", lst->no[i]);
        }
        printf("\n\n");
    }
}

int size(List lst){
    printf("List size: %d\n",lst->end);
}


int main(){

  List list;
  list = create_list();
  
  if(list==NULL){
        printf("Unable to create list!");
        return -1;
    }

  for(int i=0; i<max; i++){
    insert_ord(list, i+1);
  }
  
  print_list(list);

  size(list);

  remove_ord(list, 8);
  remove_ord(list, 10);
  remove_ord(list, 9);
  insert_ord(list, 8);

  print_list(list);
  
}