/*Write a C Program to perform following operations on a Linked List with a Single Pointer :
1. Insert some integers in sorted order.
2. Display the content of the list in reverse order. */
#include<stdio.h>
#include<stdlib.h>
typedef struct s
{
    int data;
    struct s* next;
}node;
node* createnode(int inp)
{
    node* newnode=malloc(sizeof(node));
    newnode->data=inp;
    newnode->next=NULL;
    return newnode;
}
node* insert(node** head, int inp)
{
    node* newnode=createnode(inp);
    if(*head==NULL||newnode->data < (*head)->data)
    {
        newnode->next=*head;
        *head=newnode;
        printf("%d inserted\n",(*head)->data);
    }
    else
    {
        node* temp=*head;
        while(temp->next!=NULL&&temp->next->data < newnode->data)
            temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
        printf("%d inserted\n",temp->next->data);
    }
}
node* reverse(node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    node* revHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL; 
    return revHead;
}
node* print(node* head)
{
    if(head==NULL)
        return NULL;
    else if(head->next==NULL)
    {
        printf("\n      STACK      \n");
        return head;
    }
    else
    {
        printf("\t%d\n",(print(head->next))->data);
        return head;
    }
}
int main()
{
    int ch;
    node* head=NULL;
    while(1)
    {
        printf("\n");
        printf("1. INSERT\n");
        printf("2. REVERSE\n");
        printf("3. PRINT\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if (ch==1)
        {
            int inp;
            printf("Enter the element: ");
            scanf("%d",&inp);
            insert(&head, inp);
        }
        else if (ch==2)
        {
            if(head==NULL)
                printf("Oops!, Can't REVERSE, STACK EMPTY\n");
            else
            {
                head=reverse(head);
                printf("Link-List Reversed\n");
            }
        }
        else if (ch==3)
        {
            node* temp=print(head);
            if(temp==NULL)
                printf("CAN'T PRINT, STACK EMPTY\n");
            else
                printf("\t%d\n",temp->data);
        }
        else if (ch==4)
        {
            printf("Exitting program, Thank you.\n");
            break;
        }
        else
            printf("Invalid, choice try again.\n");
    }
    return 0;
}