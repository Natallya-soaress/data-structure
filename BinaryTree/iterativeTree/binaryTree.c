#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

#include "binaryTree.h"

#define bool int

// estrutura do nó
struct treeNode
{
    int key;
    struct treeNode *left;
    struct treeNode *right;
};

struct stackNode
{
    struct treeNode *key;
    struct stackNode *next;
};

float timedifference_msec(struct timeval t0, struct timeval t1){
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

treeNode *create_tree(){
    treeNode *node = NULL;
    return node;
}

// create a new node
treeNode *create_node(int key)
{
    treeNode *node = calloc(1, sizeof(treeNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// insert a new element
treeNode *insert(treeNode *root, int key)
{ 
     struct treeNode **current = &root;
    
    while (*current != NULL){
        if(key == (*current)->key){
                printf("Invalid key [%d]", key);
                return root;
            }
        if (key > (*current)->key){
            current = &(*current)->right;
        }
        else{
            current = &(*current)->left;
        }
    }

    *current = create_node(key);
    return root;
}

void releaseTree(struct treeNode *root){
    root = releaseNode(root, root->key);
}

treeNode *releaseNode(struct treeNode *root, int key)
{
    struct treeNode *current = root;
    struct treeNode *parent = NULL;
    struct treeNode *subTree = NULL;
    struct stackNode *stack = NULL;
    struct stackNode *garbage = NULL;
    bool done = 0;

    while (current->key != key)
    {
        parent = current;
        if (key > current->key)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    while (!done)
    {
        if (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(stack))
            {
                current = pop(&stack);
                push(&garbage, current);
                current = current->right;
            }
            else
                done = 1;
        }
    }
    if (root->key == key)
    {
        parent = NULL;
    }
    while (!isEmpty(garbage))
    {
        current = pop(&garbage);
        if (current->key == root->key)
        {
            free(root);
            root = NULL;
            return root;
        }
        else
        {
            if (current->key == key)
            {
                if (parent->right != NULL && parent->right->key == current->key)
                {
                    parent->right = NULL;
                }
                else if (parent->left != NULL && parent->left->key == current->key)
                {
                    parent->left = NULL;
                }
            }
            free(current);
        }
    }
    return root;
}

int amountNode(struct treeNode *root)
{
    struct treeNode *current = root;
    struct stackNode *stack = NULL;
    bool done = 0;
    int amountNode = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(stack))
            {
                current = pop(&stack);
                amountNode++;
                current = current->right;
            }
            else
                done = 1;
        }
    }
    return amountNode;
}

int amountLeafNode(struct treeNode *root)
{
    struct treeNode *current = root;
    struct stackNode *stack = NULL;
    bool done = 0;
    int amount = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(stack))
            {
                current = pop(&stack);
                if(isLeaf(current)){
                    amount++;
                    current = current->right;
                } else {
                    current = current->right;
                }
            }
            else
                done = 1;
        }
    }
    return amount;
}

int amountNoLeafNode(struct treeNode *root)
{
    struct treeNode *current = root;
    struct stackNode *stack = NULL;
    bool done = 0;
    int amount = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(stack))
            {
                current = pop(&stack);
                if(!isLeaf(current)){
                    amount++;
                    current = current->right;
                } else {
                    current = current->right;
                }
            }
            else
                done = 1;
        }
    }
    return amount;
}

int isLeaf(treeNode *node){
    return ((node)->left == NULL && (node)->right == NULL) ? 1 : 0;
}

// print in order
void inOrder(treeNode *root)
{   
    treeNode *current = root;
    stackNode *stack = NULL;
    bool done = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(stack))
            {
                current = pop(&stack);
                printf("%d -  ", current->key);
                current = current->right;
            }
            else
                done = 1;
        }
    }
}

// print in pos order
void posOrder(treeNode *root)
{
    treeNode *current = root;
    stackNode *stack = NULL;
    bool done = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push(&stack, current);
            current = current->right;
        }
        else
        {
            if (!isEmpty(stack))
            {
                current = pop(&stack);
                printf("%d -  ", current->key);
                current = current->left;
            }
            else
                done = 1;
        }
    }
}

// print in pre order
void preOrder(treeNode *root)
{
    if (root == NULL)
        return;

    treeNode *current = root;
    stackNode *stack = NULL;

    while (!isEmpty(stack) || current != NULL)
    {
        while (current != NULL)
        {
            printf("%d -  ", current->key);
            if (current->right)
                push(&stack, current->right);
            current = current->left;
        }
        if (!isEmpty(stack))
            current = pop(&stack);
    }
}

// Stach methods
void push(stackNode **top_ref, treeNode *key)
{

    stackNode *new = (stackNode *)malloc(sizeof(stackNode));

    if (new == NULL)
    {
        printf("Stack Overflow!! \n");
        return;
    }

    new->key = key;
    new->next = (*top_ref);
    (*top_ref) = new;
}

bool isEmpty(stackNode *top)
{
    return (top == NULL) ? 1 : 0;
}

treeNode *pop(stackNode **top_ref)
{
    treeNode *element;
    stackNode *top;

    if (isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        return;
    }
    else
    {
        top = *top_ref;
        element = top->key;
        *top_ref = top->next;
        free(top);
        return element;
    }
}

