#include <stdio.h>
#include <stdlib.h>
// Structure of tree node.
typedef struct node
{
    int data;
    struct node *lft;
    struct node *rgt;
} tree_node;

// Function for inserting new node.
tree_node *insert_node(tree_node *root, int value)
{
    if (root == NULL)
    {
        root = (tree_node *)malloc(sizeof(tree_node));
        root->data = value;
        root->lft = root->rgt = NULL;
    }
    else
    {
        if (value > root->data)
        {
            root->rgt = insert_node(root->rgt, value);
        }
        if (value < root->data)
        {
            root->lft = insert_node(root->lft, value);
        }
    }
    return root;
}

// Function for preorder.
void preorder(tree_node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->lft);
        preorder(root->rgt);
    }
}
// Function for inroder.
void inorder(tree_node *root)
{
    if (root != NULL)
    {
        inorder(root->lft);
        printf("%d ", root->data);
        inorder(root->rgt);
    }
}
// Function for postorder.
void postorder(tree_node *root)
{
    if (root != NULL)
    {
        // printf("printnode\n");
        postorder(root->lft);
        postorder(root->rgt);
        printf("%d ", root->data);
    }
}
// Main function.
int main()
{
    tree_node *root = NULL;
    int number_of_nodes;
    int node;
    // printf("\n NUMBER OF NODES : ");
    scanf("%d", &number_of_nodes);
    // printf("\n INSERT NODES : ");
    int i;
    for (i= 0; i < number_of_nodes; i++)
    {
        scanf("%d", &node);
        root = insert_node(root, node);
    }
    // printf("PRE-ORDER");
    preorder(root);
    printf("\n");
    // printf("INORDER");
    inorder(root);
    printf("\n");
    // printf("POST-ORDER");
    postorder(root);
    // printf("\n");
    return 0;
}
