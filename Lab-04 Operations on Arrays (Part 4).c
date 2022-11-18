#include<stdio.h>
#include<stdlib.h>
int main ()
{

    int A[100][100], i, j;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            A[i][j] = rand() % 100;    // taking randomly input
        }
    }
    printf("\t\t\t    |STUDENT DATABASE|\n");  //printing the marks of all student
    printf("____________________________________________________________________________________\n");
    printf("\t|S1|\t|S2|\t|S3|\t|S4|\t|S5|\t|S6|\t|S7|\t|S8|\t|S9|\t|S10|\n");
    printf("____________________________________________________________________________________\n");
    for (i = 1; i <= 5; i++)
    {
        printf("Sub-%d|  ", i);
        for (j = 1; j <= 10; j++)
        {
            printf(" %d|\t", A[i][j]);

        }
        printf("\n");
    }
    printf("____________________________________________________________________________________\n");
    printf("\n");
    // printing the mark given student

    int id  ;
    printf("Enter The Student ID: ");
    scanf("%d", &id);
    printf("Student %d Mark is :  ", id);
    for (j = 1 ; j <= 5 ; j++)
    {
        printf("%d ", A[j][id]);
    }

    printf("\n\n");

    printf("Average Marks in each Subject >\n");

    for(i = 1 ; i<= 5 ; i ++)
    {
        float sum = 0  ;    //printing average mark in each subjecect
        for (j = 1 ; j <= 10 ; j++)
        {
            sum += A[i][j];
        }
        printf("Subject %d average is: %.2f\n", i, sum/10) ;
    }

    printf("\n\n");
    //printing average mark of each student
    printf("Average Marks in each Student >\n");
    for (i = 1 ; i <= 10 ; i++)
    {
        float sum1 = 0 ;
        for (j = 1 ; j <= 5 ; j++)
        {
            sum1 += A[j][i] ;
        }
        printf("Student %d average is %.2f\n", i, sum1/5);

    }
    printf("\n\n");

    //problem five
    int sub  ;
    float a1 ;
    printf("Enter The Subject Code: ");
    scanf("%d", &sub);

    for (i = 1 ; i <= 10 ; i++)
    {
        a1 += A[sub][i];
    }
    float avr1 = a1/10 ;
    int sub2  ;
    float a2 ;
    printf("Enter The Another Subject Code: ");
    scanf("%d", &sub2);

    for (i = 1 ; i <= 10 ; i++)
    {
        a2 += A[sub2][i];
    }
    float avr2 = a2/10 ;

    if(avr1 > avr2)
    {
        printf("Subject %d have higer average mark and it's %.2lf", sub, avr1);
    }
    else
    {
        printf("Subject %d have higher average mark and it's %.2lf", sub2, avr2);
    }
    printf("\n\n");

    // problem 6
    printf("Enter the Subject Code: ");
    int code ;
    int count = 0 ;
    scanf("%d", &code);
    for (i  =1 ; i <= 10 ; i++)
    {
        if(A[code][i] > 80)
            count++ ;
    }
    printf("The Student Who get more than 80 is %d", count);











}









