
//Name : Md Abdur Rahman
//ID : 213-15-4343
//Section : PC-C


#include<stdio.h>
#include<stdlib.h>
int main () {
    int A[100]  , B[10][10] ;
    int i , j ;

    //*problem_1 A take 100 numbers between 0 & 100 as input randomly one dimensional array

    printf("The Elements of 1D arrays are as follow : \n") ;
    for ( i = 0 ; i < 100 ; i++)
        A[i] = rand() % 1000 ;
    for ( i = 0 ; i < 100 ; i ++)
        printf("%d " , A[i]) ;

    printf("\n\n");

 //*problem_1 B take 100 numbers between 0 & 100 as input randomly two dimensional array

    printf("The Elements of 2D arrays are as follow : \n") ;
    for (i = 0 ; i < 10 ; i++ )
        for ( j = 0 ; j < 10 ; j++)
            B[i][j] = rand() % 1000 ;
    for ( i = 0 ; i < 10 ; i ++)
        for ( j= 0 ; j < 10 ; j++)
            printf("%d " , B[i][j]) ;

    printf("\n\n") ;

    //*problem_2 even and odd numbers from one dimensional array

    printf("The even & Odd numbers in 1D arrays are as follow: \n") ;
    int even , odd ;
    even = 0 ;
    odd = 0 ;
    for ( i = 0 ; i < 100 ; i++ )
        if(A[i] % 2 == 0)
            even++ ;
        else
            odd++ ;
        printf("The even numbers: %d\nThe odd numbers: %d \n" , even , odd) ;
    printf("\n") ;

    //*problem_3 the numbers those are multiple of 5 & 10 from two dimensional array.

    printf("The number which can multiple by 5 & 10 are in 2D Array: \n ") ;
    for ( i = 0 ; i < 10 ; i++)
        for (j = 0 ; j < 10 ; j++)
            if(((B[i][j] % 5) == 0) && ((B[i][j] % 10) == 0))
                for ( i = 0 ; i < 10 ; i++)
                    for ( j = 0 ; j < 10 ; j++)
                   printf("%d " , B[i][j]) ;


    printf("\n\n") ;

    //problem_4 A&B Find the occurrences of particular number in one dimensional array

    int item1  , item2 ;
    int count1 = 0 , count2 = 0 ;
    printf("Enter the item to be searched in 1D array: \n ") ;
    scanf("%d" , &item1) ;
    for (i = 0 ; i < 100 ; i ++)
        if(A[i] == item1)
            count1++ ;
    printf("Enter the item to be searched in 2D array: \n") ;
    scanf("%d" , &item2) ;
    for (i = 0 ; i < 10 ; i++)
        for (j =0 ; j < 10 ; j++)
            if (B[i][j] == item2)
                count2++ ;
    printf("The Occurrences of %d 1D in array is %d times \n" , item1 , count2) ;
    printf("The Occurrences of %d 2D in array is %d times \n" , item2 , count2) ;

    printf("\n") ;

    //problem_5 . Find the summation of
    //(a) Diagonal numbers
    //(b) Non-diagonal numbers from the two dimensional Array.

    int sum1 = 0 , sum2 = 0 ;
    for (i = 0 ; i < 10 ; i++)
        for (j = 0 ; j< 10 ; j++)
            if(i == j)
                sum1 += B[i][j] ;
            else
                sum2 += B[i][j] ;
    printf("\nThe Summation of Diagonal number of 2D Array is: %d \n" , sum1);
    printf("\nThe Summation of Non-Diagonal number of 2D Array is: %d \n" , sum2);
    printf("\n\n") ;

    //problem_6 Merge

    printf("\t\t\t**** MERGE ****\t\t\t\n") ;

    int A1[10] , A2[10] , A3[20] ;
    int size1 , size2 , index = 0 ;
    printf("Enter the size of First array: ");
    scanf("%d" , &size1);
    printf("Enter the size of Second array: ");
    scanf("%d" , &size2);
    printf("Enter the elements of first array :" );
    for( i = 0 ; i < size1 ; i++)
    {
        scanf("%d" , &A1[i]);
    }
    printf("Enter the elements of second array :");
    for( i = 0 ; i < size2 ; i++)
    {
        scanf("%d" , &A2[i]);
    }
    for( i = 0 ; i < size1 ; i++)
    {
        A3[index] = A1[i];
        index++;
    }
    for( i = 0 ; i < size2 ; i++)
    {
        A3[index] = A2[i];
        index++;
    }
    printf("The Marge array is : \n");
    for( i = 0 ; i < (size1+size2) ; i++)
    {
        printf("%d ", A3[i] );
    }
    printf("\n\n");

    //#problem_7 Sort.

    printf("\t\t\t**** Sort ****\t\t\t\n");
    int D[10] , size3 , temp;
    printf("Enter The Size of the Number: ");
    scanf("%d" , &size3);
    printf("Enter the elements of the matrix : ");
    for(i = 0 ; i < size3 ; i++)
    {
        scanf("%d",&D[i]);
    }
    for( i = 0 ; i < size3 ; i++)
    {
        for( j = i+1 ; j < size3 ; j++)
        {
            if(D[i] > D[j])
            {
                temp = D[i];
                D[i] = D[j];
                D[j] = temp;
            }
        }
    }
    printf("The Sort of the matrix is: \n");
    for( i = 0 ; i <size3 ; i++)
    {
        printf("%d " , D[i]);
    }
    printf("\n");

    //#problem_8 Matrix Multiplication

    printf("\t\t\t**** Matrix Multiplication ****\t\t\t\n");


        int a[10][10] , b[10][10] , c[10][10] , siz , k;

        printf("Enter the size of the matrix : ");
        scanf("%d" , &siz );
        printf("Enter the elements of First Matrix: \n");

        for( i = 0 ;  i < siz ; i++)
        {
            for ( j = 0 ; j < siz ; j++)
            {
                scanf("%d" , &a[i][j]);
            }
        }

        printf("Enter the elements of Second Matrix: \n");

        for(i = 0 ; i < siz ; i++)
        {
            for(j = 0 ; j < siz ; j++)
            {
                scanf("%d" , &b[i][j]);
            }
        }

        for(i = 0 ; i < siz ; i++)
        {
            for(j = 0 ; j < siz ; j++)
            {
                c[i][j] = 0;
                for(k = 0 ; k <siz ; k++)
                {
                    c[i][j]+=a[i][k]*b[k][j];
                }
            }
        }

        printf("The Multiplication of two matrices is: \n");
        for( i = 0 ; i < siz ; i++)
        {
            for( j = 0 ; j < siz ; j++)
            {
                printf("%d\t" , c[i][j]);
            }
            printf("\n");
        }
        return 0;
    }

