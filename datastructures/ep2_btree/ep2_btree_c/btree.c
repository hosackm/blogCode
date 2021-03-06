#include <stdlib.h>
#include "btree.h"

/* Node Data Type */
struct tree_s {
    /* the data */
    elem val;
    /* left and right subtrees */
    struct tree_s *left, *right;
};

/* Recursively deallocate all nodes within this tree */
void btree_destroy(btree t)
{
    /* Recursively call btree_destroy on the left and
     * right subtrees. */
    if (t) {
        btree_destroy(t->left);
        btree_destroy(t->right);
        
        /* Free this node once we've reached the end case */
        free(t);
    }
}

/* Recursively search for correct place and add a value to the tree */
int btree_insert(btree *t, const elem val)
{
    /* Create the node if it doesn't exist yet */
    if (!*t) {
        *t = malloc(sizeof(struct tree_s));
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->val = val;
        return 0;
    }

    /* If val is less than the current val
     * it goes in the left subtree */
    if (val < (*t)->val)
    {
        return btree_insert(&(*t)->left, val);
    }
    /* Otherwise it goes in the right subtree */
    else
    {
        return btree_insert(&(*t)->right, val);
    }

    /* We shouldn't get here, error! */
    return -1;
}

/* Find an element in the tree */
int btree_find(btree t, const elem val)
{
    /* If we've reached a NULL leaf we've exhausted the tree */
    if (!t)
        return 0;

    /* If val exhists it will be in the left subtree */
    if (val < t->val)
    {
        return btree_find(t->left, val);
    }
    /* If val exhists it will be in the right subtree */
    else if(val > t->val)
    {
        return btree_find(t->right, val);
    }

    /* t is not NULL and val is (not gt.) and (not lt.) so it must be eq. */
    return 1;
}
