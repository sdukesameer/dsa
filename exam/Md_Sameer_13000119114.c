#include<stdio.h> 
#include<stdlib.h> 
typedef struct n{//structure of tree
	int key;//data in the tree
	struct n *left, *right;//left and right node
}list;
typedef struct{//structure of stack
    int top;//stack top
    unsigned int size;//stack size
    int* arr;//stack using array
}stack;
list* initialise_tree(list* root){//initialised the tree
    root=NULL;//root is assigned as null
    return root;
}
stack* initialise_stack(unsigned int x){//initialised the stack
    stack* ret=(stack*) malloc(sizeof(stack));//memory is allocated to stack of structure stack size
    ret->top=-1;//put top to -1
    ret->size=x;//size enter is put to size in structure
    ret->arr=(int*)malloc(x * sizeof(int));//memory is allocated to arr used to create the stack
    return ret;
}
list *newNode(int item){//new node for tree is created using this function
	list *temp = (list*)malloc(sizeof(list));//a new node is created
	temp->key = item;//item entered by used is put in the node 
	temp->left = temp->right = NULL;//left and right pointer in the node is set as null
	return temp; 
}
list* insert(list* node, int key){//element entered by used is put to desired location in tree using this function
	if (node == NULL)// if surfed node is empty
	return newNode(key); //using newNode function a node is added
	if (key < node->key) // if entered key is smaller than current node key
		node->left = insert(node->left, key);//left branch is surfed
	else if (key > node->key) // if entered key is greater than current node key
		node->right = insert(node->right, key); //left branch is surfed
	return node;
}
int is_full(stack* stk){//to check if stack is full
    if(stk->top==(stk->size-1))//if stack is full return 1
        return 1;
    else//if not full return 0
        return 0;
}
void push(stack* stk, int n){//push an element to the stack
    if(is_full(stk))//if stack if full display overflow warning
        printf("OVERFLOW OCCURRED!\n");
    else{//else enter the element in array
        stk->arr[++stk->top]=n;
        printf("%d pushed to stack.\n",stk->arr[stk->top]);//print a confirmation text
    }
}
int is_empty(stack* stk){//to check if stack is empty
    if(stk->top==-1)//if stack is empty return 1
        return 1;
    else//if not return 0
        return 0;
}
list* minValNode(list* node){//to return min value from the node
    list* curr=node;
    while(curr && curr->left!=NULL)//if curr isn't null or its next is not null
        curr=curr->left;
    return curr;//when we find the smallest value
}
int find(list* root, int n){//to check if the integer exists in the tree
    if (root==NULL)
        return 0;//if not found
    else{
        if (n<root->key)//surf left
            find(root->left,n);
        else if(n>root->key)//surf right
            find(root->right,n);
        else
            return 1;//of found
    }
}
list* del_Node(list* node, int n){//delete an integer from tree
    if(node==NULL)//if node is empty return NULL or just the node
        return node;
    if(n<node->key)//if entered integer is to left of tree
        node->left=del_Node(node->left,n);
    else if(n>node->key)//if entered integer is to left of tree
        node->right=del_Node(node->right,n);
    else{//if integer is found
        if(node->left==NULL){//if it has no nodes to left node
            list*temp=node->right;
            free(node);//just free it
            return temp;
        }
        else if (node->right==NULL){//if it has no nodes to right
            list* temp=node->left;
            free(node);//free it 
            return temp;
        }
        list* temp=minValNode(node->right);//temp has the lowest value from the node
        node->key=temp->key;//in deleted key smallest is allocated
        node->right=del_Node(node->right,temp->key);
    }
    return node;
}//end of function
void pop(stack* stk){//pop an element from the stack
    if(is_empty(stk))//if stack already empty display stack empty waring
        printf("STACK EMPTY!\n");
    else//else pop an element from the top
        printf("%d popped from stack.\n",stk->arr[stk->top--]);//print a confirmation text
}
void preorder(list* node){//display preorder traversal of the tree
    int top=-1;//top is set as -1
    list *s[50];//array of structure list
    while(1){
        while(node!=NULL){//till tree isn't empty surf to the left-left for preorder
            printf(" %d",node->key);
			s[++top]=node;
			node=node->left;
		}
		if(top==-1)//if top comes to -1 means stack empty exit loop
			break;
		node=s[top]->right;
		top=top-1;
    }
    printf("\n");
}
void display(stack* stk){//display contents of stack
	if(stk->top==-1)// if stack is empty
		printf("STACK EMPTY\n");
	else{
        printf("  STACK\n");
		for(int i=stk->top; i>=0; i--)
			printf("    %d\n",stk->arr[i]);//display contents of the stack
	}
}
void display_tree(list* root, int n){//display tree graphically
    if (root==NULL){
        for (int i = 0; i < n-2; i++)
            printf(" ");
        printf("NULL\n");//if has null print null
    }
    else{
        display_tree(root->right,n+5);
        for (int i = 0; i < n+2; i++)
            printf(" ");
        printf("/\n");
        for (int i = 0; i < n; i++)
            printf(" ");
        printf("%d\n",root->key);//print the node
        for (int i = 0; i < n+2; i++)
            printf(" ");
        printf("\\\n");
        display_tree(root->left,n+5);
    }
}//end of function
int main(){// main function
    int ch,d,x;
    stack *stk;
    list *T, *root;
    while(1){//for infinite times of menudriven input till user puts choice of exit program
        printf("\n");//menudriven options
        printf("1. Initialise Binary Search Tree \n");
        printf("2. Initialise the stack \n");
        printf("3. Insert in Tree \n");
        printf("4. Push in stack \n");
        printf("5. Delete an element from tree \n");
        printf("6. Pop from stack \n");
        printf("7. Pre-Order Traversal of Tree \n");
        printf("8. Display the stack \n");
        printf("9. Display Graphical Tree \n");
        printf("10. Exit Program \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if(ch==1){
            root=initialise_tree(root);//initialise tree
            printf("Binary Search Tree Initialised. \n");
        }
        else if(ch==2){
            printf("Enter size of the working Stack:\n");
            scanf("%d",&x);//size of stack is inputted
            stk=initialise_stack(x);
            printf("Stack initialised. \n");//confirmation 
        }
        else if (ch==3){
            int n;
            printf("Enter the element: ");
            scanf("%d",&n);//asked for the element to be entered in tree
            root=insert(root,n);
            printf("%d inserted in Binary Tree\n",n);//confirmation output
        }
        else if (ch==4){
            int n;
            printf("Enter the element: ");
            scanf("%d",&n);//enter the element to be entered in stack
            push(stk,n);
        }
        else if (ch==5){
            int d;
            printf("Enter No.to be deleted: ");
            scanf("%d",&d);//integer to be deleted
            if(find(root,d)==1){//if it exits
                root=del_Node(root,d);//if yes deleted it
                printf("%d has been Deleted \n",d);
            }
            else//else print not found
                printf("%d not found in tree.\n");
        }
        else if(ch==6)
            pop(stk);//pop from the top
        else if(ch==7){
            if(root==NULL)//tree is empty
                printf("SORRY, TREE EMPTY\n");
            else{//print pre order
                printf("\nPRE-ORDER:\n");
                preorder(root);
            }
        }
        else if(ch==8)//display the stack
            display(stk);
        else if(ch==9)//graphical tree
            display_tree(root,1);
        else if(ch==10){//program terminated
            printf("Exitting, Thank You.\n");
            break;
        }
        else//invalid choice to try again
            printf("Invalid Choice.\n");
    }
	return 0;
}//end of main