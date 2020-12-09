#include<stdio.h>
#include<stdlib.h>
typedef struct a
{
    int data;
    struct a* next;
}node;
node* createnode(int inp)
{
    node* newnode=malloc(sizeof(node));
    newnode->data=inp;
    newnode->next=NULL;
    return newnode;
}
void sorted_insert(node** head, int inp)
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
void print(node** head)
{
    if(*head==NULL)
        printf("STACK EMPTY\n");
    else
    {
        node* h=*head;
        printf("      STACK      \n");
        while(h!=NULL)
        {
            printf("\t%d\n",h->data);
            h=h->next;
        }
    }
}
int main()
{
        printf(" Inserting in sorted order\n");
        int n;
        node* head=NULL;
        while(1)
        {
                printf("\n1. INSERT\n");
                printf("2. PRINT\n");
                printf("3. EXIT\n");
                printf("Enter choice: ");
                scanf("%d",&n);
                if (n==1)
                {
                    int inp;
                    printf("Enter the element: ");
                    scanf("%d",&inp);
                    sorted_insert(&head,inp);;
                }
                else if (n==2)
                {
                    print(&head);
                }
                else if (n==3)
                {
                    printf("Exitting program, Thank you.\n");
                    break;
                }
                else
                    printf("INVALID CHOICE, TRY AGAIN\n");
        }
        return 0;
}