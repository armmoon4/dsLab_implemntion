#include <stdio.h>
#define INF 999

void printMatrix(int a[][4]);
void floydWarshall(int graph[][4])
{
    int a[4][4], i, j, k;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            a[i][j] = graph[i][j];


    for (k = 0; k < 4; k++)
    {
        for (i = 0; i < 4; i++)                        // Adding vertices individually
        {
            for (j = 0; j < 4; j++)
            {
                if (a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }
    printMatrix(a);
}

void printMatrix(int a[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == 4)
                printf("%4s", "4");
            else
                printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int a[10][10], i, j, count, cnt=0;
    printf("Enter Adjacency Matrix: \n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Adjacency Matrix is: \n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<4; i++)
    {
        count = 0;
        for(j=0; j<4; j++)
        {
            if(a[i][j] == 1)
            {
                count++;
                cnt++;
            }
        }
        printf("vertex %d has %d degree\n", i+1, count);
    }
    cnt = 0;
    printf("No of edges %d\n", cnt);
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if((i!=j) && (a[i][j] ==1))
            {
                cnt++;
            }
        }
    }
    if(cnt == 1)
    {
        printf("This is a complete graph\n");
    }
    else
    {
        printf("This is not a complete graph\n");
    }

    printf("\n");


    printf("Warshall Graph:\ n");

    int graph[4][4] = {{0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };
    floydWarshall(graph);


    return 0;
}
