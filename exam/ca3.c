#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct bs_tree{
    int data;
    struct bs_tree *left, *right;
}BS_TREE; 
typedef struct queue{
   BS_TREE *elements[MAX];
    int front, rear; 
}QUEUE;
void initialiseQueue (QUEUE *aq){
    aq->front =-1; 
    aq->rear =-1;
}
void addQueue (BS_TREE * at, QUEUE *aq){
/*There is no space in Queue for the new Item. Item can not be added in the Queue.*/
    if (aq->rear == MAX-1)
        exit(0); /* Unsuccessful Addition*/
 /* Spaces are available in Queue for the new Item. */
    else
        aq->elements [++(aq->rear)]=at;
/* Successful Addition*/
}
BS_TREE* deleteQueue (QUEUE *aq){
     BS_TREE *p;
    /* Non-empty Queue*/
    if (aq->front != aq->rear){
        p= aq->elements [++(aq->front)];
        if (aq->front == aq->rear)
        /* Queue is empty*/
        initialiseQueue (aq);
        return p; /* Successful retrieval of data*/
    }
    else /* Empty Queue*/
        return NULL; /* Empty Queue*/
}
int  isEmptyQueue (QUEUE q) {
    return (q.front == -1);
}
void initialise_tree (BS_TREE **aar){
        *aar = NULL;
}
void rec_insert (BS_TREE **aar, int n){
    if (*aar == NULL){
       *aar=(BS_TREE *)malloc(sizeof(BS_TREE));
        (*aar)->data=n;
        (*aar)->left=(*aar)->right=NULL;
    } 
    else if (n<(*aar)->data)
        rec_insert(&((*aar)->left), n); 
    else
        rec_insert(&((*aar)->right), n); 
}
void level_order_Traversal (BS_TREE *ar){
    QUEUE q;
    BS_TREE *ptr;
    /*Initialisation of Queue*/
    initialiseQueue (&q);
    /*Insert the Root of the tree in the Queue.*/
    addQueue (ar, &q);
    /*Continue until Queue is empty.*/    
    while (! isEmpty(q)){
        /*Remove the first address from the    Queue to a ptr.*/    
        ptr = deleteQueue (&q);
        /*Insert the left child of a ptr in the Queue.*/    
        if ( ptr->left != NULL ) 
            addQueue (ptr->left, &q);
        /* Insert the right child of a ptr in the Queue.*/    
        if ( ptr->right != NULL ) 
            addQueue (ptr->right, &q);
        printf("\t %d", ptr->data);            
    }
}