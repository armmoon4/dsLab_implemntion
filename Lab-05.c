#include<stdio.h>
int main ()
{
    int A[100], n = 9, i, j, temp   ;
    for (i = 0 ; i <  n ; i++)
    {
        //problem 1 b
        scanf("%d", &A[i]);
    }

    int pos = 5 ;
    int value  ;
    scanf("%d", &value);

    for (i = n-1 ; i >= pos-1 ; i--)
    {
        A[i+1] = A[i]  ;
    }
    A[pos-1] = value ;
    for (i = 0 ; i < n+1 ; i++)
    {
        for (j = i +1  ; j <  n ; j++)
        {
            if(A[i] < A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    for (i = 0 ; i < n ; i++ )
    {
        printf("%d ", A[i]);
    }

    printf("\n\n");

    //problem 2n


    for (i = 0 ; i < 7 ; i++ )
    {
        scanf("%d", &A[i]);
    }
    int search ;
    scanf("%d", &search);

    for (i = 0 ; i < 7 ; i++)
    {

        if(A[i] == search)
        {
            printf("Congratulations! You are selected for the\n"
                   "scholarship.");
            break;
        }
    }
    if(i == 7)
    {
        printf("Sorry! Hope for the Best Next Time.");
    }
    printf("\n\n");

    //

    int l ;


    int  F[100], count = 0 ;

    for (i = 0 ; i < 15 ; i++)
    {
        scanf("%d", &A[i]);
    }
    l = i ;

    printf("%d", l  );

    for(i=0; i<15; i++)
    {
        count = 1;
        for(j=i+1; j<15; j++)
        {
            if(A[i]==A[j])
            {
                count++;
                F[j]=-1;

            }
        }

        if(F[i] != -1)
            F[i] = count;


    }

    for(i=0; i<15; i++)
        if(F[i]!=-1)
            printf("\n%d -- %d ",F[i], A[i]);
    printf("\n");

    // ts 3
    int min, max ;
    min = 1000;
    max = 0;
    for (i = 0; i < 15; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    for (i = 0; i < 10; i++)
    {
        if (A[i] < min)
            min =A[i];
    }
    printf("%d -- %d", max, min);



    return 0;
}


