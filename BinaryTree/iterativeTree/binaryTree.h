typedef struct sNode sNode;
typedef struct tNode tNode;

void push(struct sNode **top_ref, struct tNode *t);
struct tNode* pop(struct sNode **top_ref);
//bool isEmpty(struct sNode *top);

struct tNode *create_node(int key);
struct tNode *insert(struct tNode *root, int key);
int isLeaf(struct tNode *node);
struct tNode *releaseNode(struct tNode *root, int key);
void inOrder(struct tNode *root);
void posOrder(struct tNode *root);
void preOrder(struct tNode *root);


