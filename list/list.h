#define max 12

typedef struct list *List;

List create_list();
int empty_list(List lst);
int full_list(List lst);
int insert_ord(List lst, int elem);
int remove_ord(List lst, int elem);
List print_list(List lst);
int size(List lst);
