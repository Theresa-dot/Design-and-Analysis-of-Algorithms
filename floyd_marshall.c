#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
#define N 4

int main(){
    int G[N][N]={{0,3,5,7},{8,0,2,INF},{INF,INF,0,1},{2,INF,INF,0}};
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j && G[i][k]!=INF && G[k][j]!=INF){
                    if(G[i][j]>G[i][k]+G[k][j]) G[i][j]=G[i][k]+G[k][j];
                }
            }
        }
    }
    printf("\nFINAL GRAPH:");
    for(int i=0;i<N;i++){
        printf("\n");
        for(int j=0;j<N;j++){
            printf("%d ",G[i][j]);
        }
    }
}