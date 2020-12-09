#include<stdio.h>
#include<stdlib.h>
/*void p(int** head)
{
    printf("1. %d 2. %d",*head,**head);
}
*/
int main()
{
    int n=7;
    int* head;
    head=&n;
    printf("3. %d 4. %d",&head,*head);
    //p(&head);
    return 0;
}