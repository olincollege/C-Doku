#include<stdlib.h>
#include<stdio.h>

struct bin_tree {
int data;
int size;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        *tree -> size = 1;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}



void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

int check_col(int board[9][9], int i){
    node *root;
    for(int j = 0; j<9; j++){
        insert(&root, board[j][i]);
    }
    size_t types = root -> size;
    deltree(root);
    if (types == 9){
        return 0;
    }
    return 1;
}



void main()
{
    int board_complete[9][9] = {
    {3, 9, 1, 2, 8, 5, 7, 4, 6}, 
    {6, 2, 5, 4, 3, 7, 1, 9, 8},
    {4, 8, 7, 9, 1, 6, 2, 3, 5}, 
    {8, 6, 3, 1, 5, 9, 4, 2, 7},
    {5, 1, 4, 8, 7, 2, 3, 6, 9}, 
    {2, 7, 9, 6, 4, 3, 5, 8, 1},
    {1, 3, 8, 7, 6, 4, 9, 5, 2}, 
    {9, 4, 6, 5, 2, 1, 8, 7, 3},
    {7, 5, 2, 3, 9, 8, 6, 1, 4},
    };
    int i = check_col(board_complete, 1);
    printf("%d", i);
}
