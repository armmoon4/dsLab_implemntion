#include <stdio.h>


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




    return 0;
}
