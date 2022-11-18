#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
# define MAX 100
#define N 100
# define SIZE 100
char stack[MAX];
int stack_array[N] ;
int top = -1 ;
int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;
void enqueue();
void dequeue();
void show();

struct node
{
    int val;
    struct node *next;
};
struct node *head;

void pushl()
{
    int val;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("not able to push the element");
    }
    else
    {
        printf("Enter the value");
        scanf("%d",&val);
        if(head==NULL)
        {
            ptr->val = val;
            ptr -> next = NULL;
            head=ptr;
        }
        else
        {
            ptr->val = val;
            ptr->next = head;
            head=ptr;

        }
        printf("Item pushed");

    }
}

void popl()
{
    int item;
    struct node *ptr;
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped");

    }
}
void displayl()
{
    struct node *ptr;
    ptr=head;
    if(ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->val);
            ptr = ptr->next;
        }
    }
}

void push()
{

    int x[10] ;
    printf("Enter the value in Stack: ");
    scanf("%d", &x[10]);

    if(top == N-1)
    {
        printf("Stack is Overflow");
    }
    else
    {

        top++ ;
        stack_array[top] = x[10] ;

    }
}

void pop()
{

    int value ;
    if(top == -1)
    {
        printf("Stack is Underflow");
    }
    else
    {
        value = stack_array[top] ;
        top-- ;
        printf(" %d ", value);

    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is Empty ");
    }
    else
        printf(" %d ", stack_array[top]);
}
void display()
{
    int i ;

    for (i = top ; i >= 0 ; i--)
    {
        printf(" %d ", stack_array[i]);
    }

}

int isFull()
{
    return top == MAX - 1;
}

// checking is stack is empty
int isEmpty()
{
    return top == -1;
}

// Push function here, inserts value in stack and increments stack top by 1
void pushp(char item)
{
    if (isFull())
        return;
    top++;
    stack[top] = item;
}


int popp()
{
    if (isEmpty())
        return INT_MIN;

    return stack[top--];
}

int peekp()
{
    if (isEmpty())
        return INT_MIN;
    return stack[top];
}

int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

int getPostfix(char* expression)
{
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i)
    {

        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];

        else if (expression[i] == '(')
            push(expression[i]);

        else if (expression[i] == ')')
        {
            while (!isEmpty(stack) && peekp(stack) != '(')
                expression[++j] = popp(stack);
            if (!isEmpty(stack) && peekp(stack) != '(')
                return -1;
            else
                pop(stack);
        }
        else
        {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peekp(stack)))
                expression[++j] = popp(stack);
            push(expression[i]);
        }

    }

    while (!isEmpty(stack))
        expression[++j] = popp(stack);

    expression[++j] = '\0';

}

void reverse(char *exp)
{

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void brackets(char* exp)
{
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}
void InfixtoPrefix(char *exp)
{

    int size = strlen(exp);
    reverse(exp);
    brackets(exp);
    getPostfix(exp);
    reverse(exp);
}


int main ()
{

    int ch;

    do
    {
        printf("Enter Your Choise: \n");
        printf("1 >> PUSH \n");
        printf("2 >> POP\n");
        printf("3 >> PEEK\n");
        printf("4 >> Display\n");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;

        default:
            printf("Invalid Choice");
            break;
        }

    }
    while (ch != 4);

    printf("\n");

    //using linked list
    int choice=0;
    printf("\n*********Stack operations using linked list*********\n");
    printf("\n----------------------------------------------\n");
    while(choice != 4)
    {
        printf("Enter Your Choise: \n");
        printf("1 >> PUSH \n");
        printf("2 >> POP\n");
        printf("3 >> PEEK\n");
        printf("4 >> Display\n");

        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            pushl();
            break;
        }
        case 2:
        {
            popl();
            break;
        }
        case 3:
        {
            displayl();
            break;
        }
        case 4:
        {
            printf("Exiting....");
            break;
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        }
    }

    printf("\n");     // infix prefix pos


    printf("The infix is: ");

    char expression[] = "(A+B)+C";
    printf("%s\n",expression);

    getPostfix(expression);
    printf("The postfix is: ");
    printf("%s\n", expression);



    InfixtoPrefix(expression);
    printf("The prefix is: ");
    printf("%s\n",expression);


    printf("\n");            //queue

    int ch2;
    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch2);
        switch (ch2)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("Incorrect choice \n");
        }
    }
    return 0 ;
}

void enqueue()
{
    int insert_item;
    if (Rear == SIZE - 1)
        printf("Overflow \n");
    else
    {
        if (Front == - 1)

            Front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        inp_arr[Rear] = insert_item;
    }
}

void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
}

void show()
{

    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}


