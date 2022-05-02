typedef struct sNode sNode;
typedef struct tNode tNode;

void push(struct sNode **top_ref, struct tNode *t);
tNode *pop(struct sNode **top_ref);
//bool isEmpty(struct sNode *top);

tNode *create_node(int key);
tNode *insert(struct tNode *root, int key);
int isLeaf(struct tNode *node);
tNode *releaseNode(struct tNode *root, int key);
void inOrder(struct tNode *root);
void posOrder(struct tNode *root);
void preOrder(struct tNode *root);


