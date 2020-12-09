#include<stdio.h>
int N;//no of row col
int safe(int arr[N][N], int row, int col){//to check if the column is safe
    int i,j;
    for ( i = 0; i < col; i++)//if column is filled return 0
        if(arr[row][i])
            return 0;
    for ( i = row, j = col; i >= 0 && j >= 0; i--, j--)//if upper diagonal is filled return 0
        if(arr[i][j])
            return 0;
    for ( i = row, j = col; i < N && j >= 0; i++, j--)//if lower diagonal is filled return 0
        if(arr[i][j])
            return 0;
    return 1;//else id safe 
}
int queens(int arr[N][N],int n){//n is col no, initially its 0
    if(n>=N)//best case, when all queens are well placed
        return 1;
    for (int i = 0; i < N; i++)//surf accross rows
    {
        if(safe(arr,i,n)){
            arr[i][n]=1;//if safe insert a queen
            if(queens(arr,n+1))//then check if at next col its safe to place queen
                return 1;
            arr[i][n]=0;//if on next col queens can't be placed backtrack and remove queen from that location
        }
    }
    return 0;//when solution doesn't exist
}
int main(){
    int n=1;
    while(n){//check for invalid input
        printf("Enter valid N i.e no of rows and columns: ");
        scanf("%d",&N);
        if(N>0)
            n=0;
    }
    int arr[N][N];
    for (int i = 0; i < N; i++)//initiaise all to 0
        for (int j = 0; j < N; j++)
            arr[i][j]=0;
    int ans=queens(arr,0);//queen function call
    if(ans==0)
        printf("\nFor N = %d, solution doesn't exist.\n",N);
    if(N==2){
        printf("Maximum 1 queen can be placed on board.\n");
        arr[0][0]=1;
    }
    if(N==3){
        printf("Maximum 2 queens can be placed on board.\n");
        arr[0][0]=1;
        arr[2][1]=1;
    }
    printf("\n");//graphical representation
    for (int i = 0; i < N; i++){
        if(i==0){
            for (int k = 0; k < N; k++)
                printf(" ---");
            printf("\n");
        }
        printf("|");
        for (int j = 0; j < N; j++){
            if(arr[i][j])
                printf(" Q |");
            else
                printf("   |");
        }
        printf("\n");
        for (int k = 0; k < N; k++)
            printf(" ---");
        printf("\n");
    }
    return 0;
}//end of main function