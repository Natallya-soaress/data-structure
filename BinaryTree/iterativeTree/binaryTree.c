#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

#include "binaryTree.h"

#define bool int

// estrutura do nó
struct tNode
{
    int key;
    struct tNode *left;
    struct tNode *right;
};

struct sNode
{
    struct tNode *t;
    struct sNode *next;
};

float timedifference_msec(struct timeval t0, struct timeval t1){
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

tNode *create_tree(){
    tNode *node = NULL;
    return node;
}

// create a new node
tNode *create_node(int key)
{
    tNode *node = calloc(1, sizeof(tNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// insert a new element
tNode *insert(tNode *root, int key)
{ 
     struct tNode **current = &root;
    
    while (*current != NULL){
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

void releaseTree(struct tNode *root){
    root = releaseNode(root, root->key);
}

tNode *releaseNode(struct tNode *root, int key)
{
    struct tNode *current = root;
    struct tNode *parent = NULL;
    struct tNode *subTree = NULL;
    struct sNode *s = NULL;
    struct sNode *garbage = NULL;
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
            push(&s, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
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

int amountNode(struct tNode *root)
{
    struct tNode *current = root;
    struct sNode *s = NULL;
    bool done = 0;
    int cont = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push(&s, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                cont++;
                current = current->right;
            }
            else
                done = 1;
        }
    }
    return cont;
}

// print in order
void inOrder(tNode *root)
{   
    tNode *current = root;
    sNode *s = NULL;
    bool done = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push(&s, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                printf("%d -  ", current->key);
                current = current->right;
            }
            else
                done = 1;
        }
    }
}

// print in pos order
void posOrder(tNode *root)
{
    tNode *current = root;
    sNode *s = NULL;
    bool done = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push(&s, current);

            current = current->right;
        }
        else
        {
            if (!isEmpty(s))
            {

                current = pop(&s);
                printf("%d -  ", current->key);
                current = current->left;
            }
            else
                done = 1;
        }
    }
}

// print in pre order
void preOrder(tNode *root)
{
    if (root == NULL)
        return;

    tNode *current = root;
    sNode *st = NULL;

    while (!isEmpty(st) || current != NULL)
    {
        while (current != NULL)
        {
            printf("%d -  ", current->key);
            if (current->right)
                push(&st, current->right);
            current = current->left;
        }
        if (!isEmpty(st))
            current = pop(&st);
    }
}

// Stach methods
void push(sNode **top_ref, tNode *t)
{

    sNode *new_tNode = (sNode *)malloc(sizeof(sNode));

    if (new_tNode == NULL)
    {
        printf("Stack Overflow!! \n");
        getchar();
        exit(0);
    }

    new_tNode->t = t;
    new_tNode->next = (*top_ref);
    (*top_ref) = new_tNode;
}

bool isEmpty(sNode *top)
{
    return (top == NULL) ? 1 : 0;
}

tNode *pop(sNode **top_ref)
{
    tNode *element;
    sNode *top;

    if (isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        element = top->t;
        *top_ref = top->next;
        free(top);
        return element;
    }
}

