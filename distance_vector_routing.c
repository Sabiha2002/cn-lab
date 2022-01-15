#include <stdio.h>
struct router{
    int dist[20];
    int from[20];
};
int main(){
    int n;
    printf("Enter the number of routers: ");
    scanf("%d", &n);
    struct router rt[n+1];
    int d[n+1][n+1];
    printf("Enter the distance matrix: \n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &d[i][j]);
            rt[i].dist[j] = d[i][j];
            rt[i].from[j] = j;
        }
    }
    int count = 0;
    do{
        count = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <= n; k++){
                    if(rt[i].dist[j] > rt[i].dist[k]+rt[k].dist[j]){
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    }while(count != 0);
    for(int i = 1; i <= n; i++){
        printf("For router %d\n", i);
        for(int j = 1; j <= n; j++){
            printf("router %d via %d dist %d\n", j, rt[i].from[j], rt[i].dist[j]);
        }
        printf("\n");
    }
    return 0;
}