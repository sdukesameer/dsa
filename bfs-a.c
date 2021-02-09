#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int n;//number of vertices
    int** mat;//array of pointers
}gph;
typedef struct{
    int end;//endmost filled index
    int* items;//queue for bfs
}que;
void input(gph* g){
    int i,j,f,x=1;
    while(x){
        printf("\nEnter the number of vertices: ");
        scanf("%d",&g->n);
        if(g->n>0)
            x=0;
        else
            printf("Invalid input.\n");
    }
    g->mat=(int**) malloc(sizeof(int*)*g->n);
    for(i=0;i<g->n;i++)
        g->mat[i]=(int*)malloc(sizeof(int)*g->n);
    for(i=0;i<g->n;i++)
        for(j=0;j<g->n;j++)
            g->mat[i][j]=-1;
    for(i=0;i<g->n;i++)
        for(j=0;j<g->n;j++){
            if(g->mat[i][j]==1 || g->mat[i][j]==0)
                continue;
            if(i==j){
                g->mat[i][j]=0;
                continue;
            }
            x=1;
            while(x){
                printf("Is there an edge between %c and %c (Yes=1 & No=0): ",'A'+i,'A'+j);
                scanf("%d",&f);
                if(f==0 || f==1){
                    g->mat[i][j]=f;
                    g->mat[j][i]=f;
                    x=0;
                }
                else
                    printf("Invalid input.\n");
            }
        }
}
void initialiseQueue(que* q, int n){
    q->end=-1;
    q->items=(int*) malloc(sizeof(int)*n);
}
void enqueue(que* q, int n){
    q->items[++(q->end)]=n;
}
int dequeue(que* q){
    int ret=q->items[0];
    for(int i=0; i<q->end; i++)
        q->items[i]=q->items[i+1];
    q->end--;
    return ret;
}
void bfs(gph g, int s){
    que q;
    initialiseQueue(&q,g.n);
    int visited[g.n],i,f;
    for(i=0;i<g.n;i++)
        visited[i]=0;
    visited[s]=1;
    enqueue(&q,s);
    printf("\nFollowing is the BFS Traversal (starting from %c): \n",'A'+s);
    while(q.end!=-1){
        f=dequeue(&q);
        printf("%c\t",'A'+f);
        for (i = 0; i < g.n; i++)
            if(g.mat[f][i])
                if(!visited[i]){
                    visited[i]=1;
                    enqueue(&q,i);//add all vertexes in queue
                }
    }
}
void free_graph(gph* g){
    for(int i=0; i<g->n; i++)
        free(g->mat[i]);
    free(g->mat);
}
int main(){
    gph g;
    int f=1,s;
    input(&g);
    printf("\n\' If");
    for(int i=0; i<g.n;i++)
        printf(" %c=%d",'A'+i,i+1);
    printf(" \'\nEnter the initial vertex: ");
    while(f){
        scanf("%d",&s);
        if(s>0 && s<g.n+1)
            f=0;
        else
            printf("Invalid input.\n");
    }
    bfs(g,s-1);
    free_graph(&g);
}