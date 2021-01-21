#include <stdio.h>
#include <stdlib.h>
// Structure of tree node.
typedef struct node
{
    int data;
    struct node *lft;
    struct node *rt;
} tree_node;
// Function to insert  new node.
tree_node *insert_node(tree_node *root, int value)
{
    if (root == NULL)
    {
        root = (tree_node *)malloc(sizeof(tree_node));
        root->data = value;
        root->lft = root->rt = NULL;
    }
    else
    {
        if (value > root->data)
            root->rt = insert_node(root->rt, value);
        if (value < root->data)
            root->lft = insert_node(root->lft, value);
    }
    return root;
}
// Function to get maximum value.
int max(int a, int b) { return (a < b ? b : a); }
// Function for height of  the tree.
int tree_height(tree_node *root)
{
    if (root == NULL)
        return 0;
    return max(tree_height(root->lft), tree_height(root->rt)) + 1;
}
// Main 
int main()
{
    tree_node *root = NULL;
    int number_of_nodes;
    int node;
    printf("\n NUMBER OF NODES : ");
    scanf("%d", &number_of_nodes);
    printf("\n INSERT NODES : ");
    int i;
    for (i = 0; i < number_of_nodes; i++)
    {
        scanf("%d", &node);
        root = insert_node(root, node);
    }
    printf("\n HEIGHT : ");
    printf("%d", tree_height(root));
    printf("\n");
    return 0;
}
