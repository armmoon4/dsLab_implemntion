#include<stdio.h>
#include<stdlib.h>

struct node{

    int data ;
    struct node *next ;

}*head;

void createList(int n);
void display();
void search() ;
void frequency();
void oddeven();

void minNode() {
    struct node *current = head;
    int min;

    if(head == NULL) {
        printf("List is empty \n");
    }
    else {

        min = head->data;

        while(current != NULL){
            if(min > current->data) {
                min = current->data;
            }
            current= current->next;
        }
        printf("Minimum value: %d\n", min);
    }
}


void maxNode() {
    struct node *current = head;
    int max;

    if(head == NULL) {
        printf("List is empty \n");
    }
    else {

        max = head->data;

        while(current != NULL){

            if(max < current->data) {
                max = current->data;
            }
            current = current->next;
        }
        printf("Maximum value: %d\n", max);
    }
}


int main () {
    int n ;
    printf("Enter the Numbers of Node: ");
    scanf("%d" , &n);
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


}

void createList(int n) {
    struct node *NewNode ,  *temp;
    int data , i ;

    head = malloc(sizeof (struct node));
    printf("Enter The data Node 1:");
    scanf("%d" , &data );

    head->data = data ;
    head->next = NULL  ;

    temp = head ;

    for (i = 2 ; i <= n ; i++ ){
        NewNode = malloc(sizeof (struct node));
        printf("Enter The Data Node %d:" , i );
        scanf("%d" , &data);
        NewNode->data = data  ;
        NewNode->next = NULL ;


        temp->next = NewNode ;
        temp = temp->next  ;

    }

}

void display() {

    struct node *temp ;

    temp = head ;

    while (temp != NULL) {

        printf(" %d " , temp->data);
        temp = temp->next ;
    }

}

void search() {
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL) {
        printf("Empty List\n");
    } else {
        printf("Enter item which you want to search?\n");
        scanf("%d", &item);
        while (ptr != NULL) {
            if (ptr->data == item) {
                printf("item found at location %d ", i + 1);
                flag = 0;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1) {
            printf("Item not found\n");
        }
    }
}

void frequency() {
    struct node *ptr2;
    int item,  count = 0 ;
    ptr2 = head;
    if (ptr2 == NULL) {
        printf("Empty List\n");
    } else {
        printf("Enter item to count the Frequency:\n");
        scanf("%d", &item);
        while (ptr2 != NULL) {
            if (ptr2->data == item) {
                count++ ;
            }
            ptr2 = ptr2->next;
        }
        printf("Frequency is: %d ", count);
    }
}

void oddeven() {

    struct node *ptr3 ;
    ptr3 = head ;
    printf("Even Numbers: " );
        while (ptr3 != NULL) {
            if(ptr3->data % 2 == 0 ) {
                printf("%d " , ptr3->data);
            }
            ptr3  = ptr3->next ;
        }
        printf("\nOdd Numbers: ");
    ptr3 = head ;
    while (ptr3 != NULL) {
          if(ptr3->data % 2!= 0 ) {
            printf("%d ", ptr3->data);
        }
        ptr3  = ptr3->next ;
    }

}

