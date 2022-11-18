#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[100], i, i2 ;
    int sum = 0 ;
    int *p;
    p = a;
    int n, in ;
    int di ;
    printf("Enter the number of element of an array :");
    scanf("%d", &n);
    printf("Enter the array element :");    //problem 1
    for (i = 0; i < n; i++)
    {
        *(p + i) = 10 + rand() % 100;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
    for (i = 0; i < n; i++)
    {
        sum += *(p + i);
    }
    printf("\nThe summation of 1D array is: %d \n", sum);
    int b[100][100], j;
    int *p2;
    p2 = &b[0][0];
    int sum1 = 0;
    int row, col;
    printf("\nEnter How many rows and coloums :");
    scanf("%d %d", &row, &col);
    printf(" \nEnter the Array:");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            *(p + (i * col) + j) = rand() % 99;
        }
    }
    printf("\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf(" %d", *(p + (i * col) + j));
            sum1 += *(p + (i * col) + j);
        }
        printf("\n");
    }
    printf("\nThe Summation of 2D array in pointer : %d\n", sum1);
    printf("\n");
    int m = 10, k = 20, temp;
    int *d, *tmp;
    int *x;
    d = &m;
    x = &k;
    tmp = &temp;
    printf("Before swapping the numbers : %d %d\n", m, k);
    *tmp = *x;
    *x = *d;
    *d = *tmp;
    printf("After swapping the numbers : %d %d\n", m, k);
// end swap
    int max, min;
    max = 0;
    for (i = 0; i < n; i++)
    {
        if (*(p + i) > max)
        {
            max = *(p + i);
        }
    }
    min = max;
    for (i = 0; i < n; i++)
    {
        if (min > *(p + i))
        {
            min = *(p + i);
        }
    }
    printf("Maximum is: %d\n Minimum Is: %d\n",max, min);

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (*(p + i) > *(p + j))          //pproblem 4
            {
                *(p + i) = *(p + i) + *(p + j);
                *(p + j) = *(p + i) - *(p + j);
                *(p + i) = *(p + i) - *(p + j);
            }
        }
    }
    printf("\nAfter bubble sort the element of array :\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d ", *(p + i));
    }

    int item;
    printf("\nEnter the item value for binary search\n :");
    scanf("%d", &item);
    int high = n - 1, mid, result = -1;             //problem 5
    int *ptr;
    int low = 0;
    while (low <= high)
    {
        mid = (high + low) / 2;
        ptr = &a[mid];
        if (item == *ptr)
        {
            printf("Item is %d is found\n", *ptr);
            result = 0;
            break;
        }
        else if (item < *ptr)
        {
            high = mid - 1;
        }
        else if (item > *ptr)
        {
            low = mid + 1;
        }
    }
    if (result == -1)
    {
        printf("Item is not found\n");
    }

    printf("Enter the for linear search \n");   //problem 6a
    int item2;
    scanf("%d", &item2);
    for (i = 0; i < n; i++)
    {
        if (item2 == *(p + i))
        {
            printf("Item is found\n");
            break;
        }
    }
    if (item2 != *(p + i))
    {
        printf("Item is not found");
    }

    printf("\nEnter a number to insert:\n");  //problem 6b
    scanf("%d", &in);
    printf("Enter the position where to Insert: :\n");
    scanf("%d", &i2);
    i2 = i2 - 1;
    if (i2 > n)
    {
        *(p + i2) = in;
    }
    else
    {
        for (i = n + 1; i >= i2; i--)
        {
            *(p + i + 1) = *(p + i);
        }
    }
    a[i2] = in;
    for (i = 0; i < n + 1; i++)
    {
        printf("%d ", *(p + i));
    }
    // problem 7
    printf("\nEnter the position Where to Remove:\n");
    scanf("%d", &di);
    di = di - 1;
    for (i = di; i <= n; i++)
    {
        *(p + i) = *(p + i + 1);
    }
    printf("Resultant Array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
    return 0;
}
