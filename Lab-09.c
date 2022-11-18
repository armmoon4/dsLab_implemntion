#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<stdbool.h>

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(char k)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

bool FullTree (struct Node* root)
{

    if (root == NULL)
        return 1;                      //full checking


    if (root->left == NULL && root->right == NULL)
        return 1;


    if ((root->left) && (root->right))
        return (FullTree(root->left) && FullTree(root->right));

    return -1;
}

unsigned int countNodes(struct Node* root)
{
    if (root == NULL)                                   //node counting
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}


bool Complete (struct Node* root, unsigned int index,
               unsigned int number_nodes)               //complete checking
{

    if (root == NULL)
        return (true);

    if (index >= number_nodes)
        return (false);


    return (Complete(root->left, 2*index + 1, number_nodes) &&
            Complete(root->right, 2*index + 2, number_nodes));
}


bool checkHeightBalance(struct Node *root, int *height)   //check for height
{

    int leftHeight = 0, rightHeight = 0;
    int l = 0, r = 0;                            // Check for emptiness

    if (root == NULL)
    {
        *height = 0;
        return 1;
    }

    l = checkHeightBalance(root->left, &leftHeight);
    r = checkHeightBalance(root->right, &rightHeight);

    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2))
        return 0;

    else
        return l && r;
}



int main()
{


    int tree[21] = {0,7,9,3,4,2,0,6,0,0,0,0,0,0,1,0,0,0,0,0,0},i,a;

    printf("Root of the tree is %d\n", tree[1]);
    printf("Internal Nodes : ");
    for(i=1; i<21; i++)
    {
        if ((tree[i] != 0) && ((tree[2 * i]) && (tree[2 * i + 1])))   //internal nodes
        {
            printf(" %d ", tree[i]);
        }
    }
    printf("\n");
    printf("External Nodes : ");
    for( i=1; i < 21; i++)
    {
        if((tree[i] != 0) && tree[2*i] ==0 && tree[2*i+1]==0)   //external nodes
        {
            printf(" %d ", tree[i]);
        }
    }

    printf("\n");
    printf("Enter the Value for Sibling: ");
    scanf("%d", &a);
    for( i = 0; i < 21 ; i++)
    {
        if(tree[i] ==a)
        {
            int p;                     //sibling
            if(i % 2)
            {
                p = (i-1)/2;
                if(p%2 && tree[2*p] !=0 && (p%2 ==0 && tree[2*p+1] !=0))
                    printf("%d %d", tree[2*p], tree[2*p+1]);

            }
            else
            {
                p = i/2;
                if(p%2 && tree[2*p+1] !=0 && (p%2 ==0 && tree[2*p] !=0));
                printf("Sibling are: %d %d", tree[2*p+1], tree[2*p]);

            }
        }
    }

    printf("\n");

    printf("Ancestor: ");
    for(i = 0 ; i< 21 ; i++)
    {
        if((tree[2*i] || tree[2*i+1]) && tree[i] != 0)       //ancestor
        {
            printf("%d ", tree[i]);
        }
    }

    printf("\n");

    printf("Deceandant: ");
    for(i = 1 ; i < 21 ; i++)
    {
        if((tree[i] != 0) && tree[2*i] ==0 && tree[2*i+1]==0)      //decendant
        {
            //cout << tree[i] << " ";
            printf("%d ", tree[i]);
        }
    }

    printf("\n");

    printf("Enter Genaration: ");
    scanf("%d", &a);


    for( i = pow(2,a-1) ; i < pow(2, a) ; i++)             //generation
    {
        if(tree[i] !=0)
        {
            printf("%d ", tree[i]);
        }
    }

    printf("\n");

    int h;
    printf("Level of each node: ");
    for(int i = 1 ; i < 21 ; i++)
    {
        if(tree[i] !=0)
        {
            printf("%d ",tree[i]);
            printf("Level: %d \n", pow(2, 1/tree[i]) -1);     //level
            h = pow(2, 1/tree[i]) -1;
        }
    }

    printf("\n");

    printf("Height is : %d ", h );




    int height =0;
    struct Node* root = NULL;
    root = newNode(10);
    root->left = newNode(20);   //driver p
    root->right = newNode(30);

    root->left->right = newNode(40);
    root->left->left = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);

    root->left->left->left = newNode(80);
    root->left->left->right = newNode(90);
    root->left->right->left = newNode(80);
    root->left->right->right = newNode(90);
    root->right->left->left = newNode(80);
    root->right->left->right = newNode(90);
    root->right->right->left = newNode(80);
    root->right->right->right = newNode(90);

    unsigned int node_count = countNodes(root);
    unsigned int index = 0;

    if (FullTree(root))
        printf("The Binary Tree is full\n");
    else
        printf("The Binary Tree is not full\n");


    if (Complete(root, index, node_count))
        printf("The Binary Tree is complete\n");
    else
        printf("The Binary Tree is not complete\n");


    if (checkHeightBalance(root, & height))
        printf("The tree is balanced");
    else
        printf("The tree is not balanced");


    return(0);
}
