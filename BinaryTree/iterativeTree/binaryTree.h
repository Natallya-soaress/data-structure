typedef struct stackNode stackNode;
typedef struct treeNode treeNode;

void push(struct stackNode **top_ref, struct treeNode *t);
treeNode *pop(struct stackNode **top_ref);
//bool isEmpty(struct stackNode *top);

treeNode *create_node(int key);
treeNode *insert(struct treeNode *root, int key);
treeNode *releaseNode(treeNode *root, int key);
void inOrder(struct treeNode *root);
void posOrder(struct treeNode *root);
void preOrder(struct treeNode *root);


