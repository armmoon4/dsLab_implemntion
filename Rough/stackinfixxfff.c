#include<stdio.h>
#include<string.h>
#include<limits.h>
# define MAX 100
int top = -1;
char stack[MAX];

int isFull() {       //checking
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(char item) {
    if (isFull())     //push operation
        return;
    top++;
    stack[top] = item;
}

int pop() {
    if (isEmpty())
        return INT_MIN;      //pop operation

    return stack[top--];
}

int peek(){
    if (isEmpty())
        return INT_MIN;
    return stack[top];
}


int checkIfOperand(char ch) {                       //checking operand
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;   //checking precedence

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}

int infixtoPostfix(char* expre)
{
    int i, j;

    for (i = 0, j = -1; expre[i]; ++i)
    {

        if (checkIfOperand(expre[i]))    //postfix operation
            expre[++j] = expre[i];


        else if (expre[i] == '(')
            push(expre[i]);


        else if (expre[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                expre[++j] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;
                pop(stack);
        }
        else
        {
            while (!isEmpty(stack) && precedence(expre[i]) <= precedence(peek(stack)))
                expre[++j] = pop(stack);
            push(expre[i]);
        }

    }

    while (!isEmpty(stack))
        expre[++j] = pop(stack);

    expre[++j] = '\0';

}

void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];                 //reverse
    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0')    //braces
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}
void InfixtoPrefix(char *exp){

    int size = strlen(exp);    //prefix conversion

    reverse(exp);
    brackets(exp);
    infixtoPostfix(exp);
    reverse(exp);
}

int main()
{
    int i ;
    char expression[100] ;
    printf("Enter The infix Expression: ");
    scanf("%s" , &expression[i]);
    printf("The infix is: ");
    printf("%s\n",expression);
    infixtoPostfix(expression);
    printf("The postfix is: ");
    printf("%s\n", expression);
    InfixtoPrefix(expression);
    printf("The prefix is: ");
    printf("%s\n",expression);



    return 0;
}
