//Name:Md Abdur Rahman
//ID:213-15-4343
//Sec:PC-C
//*********************************************************

//Problem-1 >>> binary search

#include<stdio.h>
int main() {
    int c, low , high , middle, n, search, array[100];
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);
    printf("Enter the value to find:\n");
    scanf("%d", &search);
    low = 0;
    high = n - 1;
    middle = (low + high) / 2;
    while (low <= high) {
        if (array[middle] < search)
            low = middle + 1;
        else if (array[middle] == search) {
            printf("%d is present at index %d.\n", search, middle + 1);
            break;
        } else
            high = middle - 1;
        middle = (low + high) / 2;
    }
    if (low > high)
        printf("Not found! %d is not present in the list.\n", search);

    printf("\n\n");


    //Problem-2 >>> Inserting Element

    int A[100],pos,i,size,value;
    printf("Enter The Array Size: \n");
    scanf("%d",&size);
    printf("Enter %d Elements of the Array: ",size);
    for(i=0;i<size;i++)
        scanf("%d",&A[i]);
    printf("Enter the position where you want to insert: ");
    scanf("%d",&pos);
    printf("Enter The Value: ");
    scanf("%d",&value);
    for(i=size-1;i>=pos-1;i--)
        A[i+1]=A[i];
    A[pos-1]= value;
    printf("Resultant Array is:\n");
    for(i=0;i<=size;i++)
        printf("%d ", A[i]);
    printf("\n\n");

    //Problem-3 >>> delete elements

    int B[110], position, j , size2;

    printf("Enter the Array Size: ");
    scanf("%d", &size2);

    printf("Enter %d Elements of the Array: \n", size2);

    for (j = 0; j < size2; j++)
        scanf("%d", &B[j]);

    printf("Enter the Location where you want to Delete: ");
    scanf("%d", &position);

    if (position >= size2+1)
        printf("Delete is not possible\n");
    else
    {
        for (j = position - 1; j < n - 1; j++)
            B[j] = B[j+1];

        printf("Resultant array is: \n");

        for (j = 0; j < size2 - 1; j++)
            printf("%d ", B[j]);
    }
    printf("\n\n");

//Problem-4 >>> Frequency

    int arr[100], freq[100];
    int size3, k, l, str;
    printf("Enter The Array Size: ");
    scanf("%d" , &size3);

    printf("Enter the %d Elements of the Array :\n",size3);
    for(k=0;k<size3;k++)
    {
        scanf("%d",&arr[k]);
        freq[k] = -1;
    }
    for(k=0; k<size3; k++)
    {
        str = 1;
        for(l=k+1; l<size3; l++)
        {
            if(arr[k]==arr[l])
            {
                str++;
                freq[l] = 0;
            }
        }

        if(arr[k]!=0)
        {
            freq[k] = str;
        }
    }
    printf("\nThe frequency of Elements of the array is: \n");
    for(k=0; k<size3; k++)
    {
        if(freq[k]!=0)
        {
            printf("%d occurs %d times\n", arr[k], freq[k]);
        }
    }
    return 0 ;
}





