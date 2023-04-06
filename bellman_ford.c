#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
#define TRUE 1
#define FALSE 0
#define N 4

char ch[]={'A','B','C','D'};

struct Table{
    int d,pi;
}V[N];

void init(int s){
    for(int v=0;v<N;v++){
        V[v].d=INF;
        V[v].pi=-1;
    }
    V[s].d=0;
}

void relax(int u,int v,int w){
    if(V[v].d>V[u].d+w){
        V[v].d=V[u].d+w;
        V[v].pi=u;
    }
}

void bellmanFord(int G[N][N],int s){
    init(s);
    for(int i=1;i<N-1;i++){
        for(int u=0;u<N;u++){
            for(int v=0;v<N;v++){
                if(G[u][v]!=0){
                    relax(u,v,G[u][v]);
                }
            }
        }
    }
}

int main(){
    int G[N][N]={{0,3,5,7},{8,0,2,0},{0,0,0,1},{2,0,0,0}};
    int s=0;
    bellmanFord(G,s);
    printf("Table Values");
    for(int v=0;v<N;v++){
        printf("\n %c \t %d \t %c",ch[v],V[v].d,ch[V[v].pi]);
    }
}