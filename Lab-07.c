#include<stdio.h>
#include<stdlib.h>

struct node
{

    int data ;
    struct node *next ;

}*head;

struct Student
{
    int sub1;
    int sub2;
    int sub3;
    int sub4;
    int sub5;

    struct Student *next;
};


void createList(int n);
void display();
void search() ;
void frequency();
void oddeven();
void Studentdatabase() ;

void minNode()
{
    struct node *current = head;
    int min;

    if(head == NULL)
    {
        printf("List is empty \n");
    }
    else
    {

        min = head->data;

        while(current != NULL)
        {
            if(min > current->data)
            {
                min = current->data;
            }
            current= current->next;
        }
        printf("Minimum value: %d\n", min);
    }
}


void maxNode()
{
    struct node *current = head;
    int max;

    if(head == NULL)
    {
        printf("List is empty \n");
    }
    else
    {

        max = head->data;

        while(current != NULL)
        {

            if(max < current->data)
            {
                max = current->data;
            }
            current = current->next;
        }
        printf("Maximum value: %d\n", max);
    }
}


int main ()
{
    int n ;
    printf("Enter the Numbers of Node: ");
    scanf("%d", &n);
    createList(n);

    printf("List is : \n");
    display() ;
    printf("\n");
    minNode();
    printf("\n");
    maxNode();

    printf("\n");

    search() ;

    printf("\n");

    frequency();

    printf("\n");

    oddeven();

    printf("\n");

    Studentdatabase();


}

void createList(int n)
{
    struct node *NewNode,  *temp;
    int data, i ;

    head = malloc(sizeof (struct node));
    printf("Enter The data Node 1:");
    scanf("%d", &data );

    head->data = data ;
    head->next = NULL  ;

    temp = head ;

    for (i = 2 ; i <= n ; i++ )
    {
        NewNode = malloc(sizeof (struct node));
        printf("Enter The Data Node %d:", i );
        scanf("%d", &data);
        NewNode->data = data  ;
        NewNode->next = NULL ;


        temp->next = NewNode ;
        temp = temp->next  ;

    }

}

void display()
{

    struct node *temp ;

    temp = head ;

    while (temp != NULL)
    {

        printf(" %d ", temp->data);
        temp = temp->next ;
    }

}

void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Enter item which you want to search?\n");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("item found at location %d ", i + 1);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("Item not found\n");
        }
    }
}

void frequency()
{
    struct node *ptr2;
    int item,  count = 0 ;
    ptr2 = head;
    if (ptr2 == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Enter item to count the Frequency:\n");
        scanf("%d", &item);
        while (ptr2 != NULL)
        {
            if (ptr2->data == item)
            {
                count++ ;
            }
            ptr2 = ptr2->next;
        }
        printf("Frequency is: %d ", count);
    }
}

void oddeven()
{

    struct node *ptr3 ;
    ptr3 = head ;
    printf("Even Numbers: " );
    while (ptr3 != NULL)
    {
        if(ptr3->data % 2 == 0 )
        {
            printf("%d ", ptr3->data);
        }
        ptr3  = ptr3->next ;
    }
    printf("\nOdd Numbers: ");
    ptr3 = head ;
    while (ptr3 != NULL)
    {
        if(ptr3->data % 2!= 0 )
        {
            printf("%d ", ptr3->data);
        }
        ptr3  = ptr3->next ;
    }

}

void Studentdatabase()
{

    struct Student *head;
    struct Student *newStudent;
    struct Student *temp;

    int i, n, sub1, sub2, sub3, sub4, sub5;

    head = (struct Student *) malloc((sizeof(struct Student)));

    printf("Enter the number of students:\n");
    scanf("%d", &n);

    printf("Enter Marks For Student 1:\n");
    printf("Subject 1:");
    scanf("%d", &head->sub1);

    printf("Subject 2:");
    scanf("%d", &head->sub2);

    printf("Subject 3:");
    scanf("%d", &head->sub3);

    printf("Subject 4:");
    scanf("%d", &head->sub4);

    printf("Subject 5:");
    scanf("%d", &head->sub5);

    head->next = NULL;
    temp = head;
    for (i = 1; i < n; i++)
    {

        newStudent = (struct Student *) malloc((sizeof(struct Student)));

        printf("Enter Marks For Student %d:\n", i + 1);
        printf("Subject 1:");
        scanf("%d", &sub1);

        printf("Subject 2:");
        scanf("%d", &sub2);

        printf("Subject 3:");
        scanf("%d", &sub3);

        printf("Subject 4:\n");
        scanf("%d", &sub4);

        printf("Subject 5:\n");
        scanf("%d", &sub5);

        newStudent->sub1 = sub1;
        newStudent->sub2 = sub2;
        newStudent->sub3 = sub3;
        newStudent->sub4 = sub4;
        newStudent->sub5 = sub5;

        newStudent->next = NULL;

        temp->next = newStudent;
        temp = newStudent;

    }


    int SelectStu, avg;
    printf("Select Particular Student for Marks: ");
    scanf("%d", &SelectStu);

    i = 1;
    printf("\n\n<<<<<<< Student Database >>>>>>>\n");
    while (head != NULL)
    {
        if (i == SelectStu)
        {
            printf("Marks for student %d \n", i);
            printf("Subject 1 : %d \n", head->sub1);
            printf("Subject 2 : %d \n", head->sub2);
            printf("Subject 3 : %d \n", head->sub3);
            printf("Subject 4 : %d \n", head->sub4);
            printf("Subject 5 : %d \n", head->sub5);
            avg = (head->sub1 + head->sub2 + head->sub3 + head->sub4 + head->sub5) / 5;
            break;
        }
        i++;
        head = head->next;
    }
    printf("\nAverage Marks of Student %d = %d\n", SelectStu, avg);


    int selectSub, subavg;
    printf("Select the Particular Student For Marks :\n ");
    scanf("%d", &selectSub);

    i = 1;
    subavg = 0;
    while (head != NULL)
    {
        printf("\t\t\t***Student %d***\t\t\t\n", i);
        if (selectSub == 1)
        {
            printf("Subject 1:%d ", head->sub1);
            avg += head->sub1;
        }
        else if (selectSub == 2)
        {
            printf("Subject 2:%d ", head->sub2);
            avg += head->sub2;
        }
        else if (selectSub == 3)
        {
            printf("Subject 3:%d ", head->sub3);
            avg += head->sub3;
        }
        else if (selectSub == 4)
        {
            printf("Subject 4:%d ", head->sub4);
            avg += head->sub4;
        }
        else if (selectSub == 5)
        {
            printf("Subject 5:%d ", head->sub5);
            avg += head->sub5;
        }
        head = head->next;
        i++;
    }
    subavg = subavg / n;
    printf("Average Mark of Student %d = %0.2f\n", i, subavg);

}
