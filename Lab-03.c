#include<stdio.h>
int main ()
{

    //Duplicate elimination from an array

    int arr[100], t, i, j, k ;
    printf("Enter The Size of the Array : ");
    scanf("%d", &t);
    printf("Enter The Elements of the Array: ");
    for (i = 0 ; i<t ; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0 ; i < t ; i++)
    {
        for (j = i+1 ; j<t ; j++)
        {
            if(arr[i] == arr[j])
            {
                for (k = 0 ; k < t ; k++)
                {
                    arr[k] = arr[k+1];
                }
                t--;
                j--;
            }
        }
    }
    printf("After Removing Duplicate Elements : ");
    for (i = 0 ; i<t ; i++ )
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    //Finding k-th maximum and k-th minimum.

    int temp ;
    printf("Enter The size of the Array: ");
    scanf("%d", &t);
    printf("Enter The Elements of The Array: ");
    for (i = 0 ; i < t ; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0 ; i<t ; i++)
    {
        for (j = i+1 ; j < t ; j++)
        {
            if(arr[i] >  arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp ;
            }
        }
    }

    printf("Enter The kth position : ");
    scanf("%d", &k) ;
    printf("The Kth max is %d \n",  arr[t-k]);
    printf("The kth min is %d ",  arr[k-1]);

    return 0 ;
}
