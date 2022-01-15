#include<stdio.h>
int main(){
    int cost[20][20],visited[20],min,mincost,n;
    printf("Enter no of nodes: ");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    visited[0]=1;
    int count = 1;
    while(count<n){
        min = 999;
        int a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j]<min){
                    if(visited[i]!=0){
                        min = cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        if(visited[b]==0){
            visited[b]=1;
            mincost += cost[a][b];
            printf("(%d %d) --> %d\n",a+1,b+1,cost[a][b]);
            count++;
           
        }
        cost[a][b]=999;
    }
    printf("Total cost:%d\n",mincost);
}
