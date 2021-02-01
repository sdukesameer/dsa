/*Write a C Program to perform following operations on a Binary Search Tree :
1. Insert some integers .
2. Display the content of the Binary Search Tree in sorted order.
3.Determine the height of the Binary Search Tree. */
#include<stdio.h>
#include<stdlib.h>
typedef struct x{
    int data;
    struct x* left;
    struct x* right;
}node;
node* createNode(int n){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=n;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
node* insertion(node* root, int n){
    if(root==NULL) return createNode(n);
    else if(n < root->data) root->left=insertion(root->left,n);
    else if(n > root->data) root->right=insertion(root->right,n);
    return root; 
}
int nodes(node* root){
    if(root==NULL)
        return 0;
    else
        return 1 + nodes(root->left) + nodes(root->right);
}
void inorder(node* root){
    node* stack[nodes(root)];
    int c=-1;
    node* cur=root;
    while(1){
        while (cur){
            stack[++c]=cur;
            cur=cur->left;
        }
        if (c!=-1){
            printf("\t%d\n",stack[c--]->data);
            cur=stack[c+1]->right;
        }
        else
            break;
    }
}
int height(node* root){
    if(root==NULL)
        return 0;
    else{
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}
void display(node* root,int n){
    if (root==NULL){
        for (int i = 0; i < n-2; i++)
            printf(" ");
        printf("NULL\n");
    }
    else{
        display(root->right,n+5);
        for (int i = 0; i < n+2; i++)
            printf(" ");
        printf("/\n");
        for (int i = 0; i < n; i++)
            printf(" ");
        printf("%d\n",root->data);
        for (int i = 0; i < n+2; i++)
            printf(" ");
        printf("\\\n");
        display(root->left,n+5);
    }
}
void deallocate_tree(node* root){
    if((root)!=NULL){
        deallocate_tree(root->left);
        deallocate_tree(root->right);
        //printf("\nDeallocating space occupied by element: %d",root->data);
        free(root);
    }
}
int main(){
    int ch;
    node* root=NULL;
    while (1){
        printf("\n1. INSERTION OF INTEGER\n");
        printf("2. CONTENTS IN SORTED ORDER\n");
        printf("3. HEIGHT OF THE TREE\n");
        printf("4. DISPLAY TREE\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if(ch==1){
            int n;
            printf("Please enter an element: ");
            scanf("%d",&n);
            root=insertion(root,n);
            printf("%d inserted in BINARY SEARCH TREE.\n",n);
        }
        
        else if(ch==2){
            if(root==NULL)
                printf("\tTREE EMPTY\n");
            else{
                printf("\nTREE IN SORTED ORDER\n");
                inorder(root);
            }
        }
        else if(ch==3)
            printf("\nHeight of the tree: %d\n",height(root));
        else if(ch==4){
            printf("\n");
            display(root,1);
        }
        else if(ch==5){
            deallocate_tree(root);
            root=NULL;
            printf("\nExitting Program, Thank You.\n");
            break;
        }
        else
            printf("INVALID CHOICE! TRY AGAIN\n");
    }
    return 0;
}