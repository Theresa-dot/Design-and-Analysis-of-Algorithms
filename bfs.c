#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 6

char ch[]={'S','A','B','C','D','t'};

struct Queue{
    int q[100];
    int f;
    int r;
}Q;

int isEmpty(){
    if((Q.r==-1) || (Q.f==Q.r+1)) return 1;
    else return 0;
}

void initQueue(){
    Q.f=Q.r=-1;
}

void enqueue(int value){
    Q.q[++Q.r]=value;
}

int dequeue(){
    if(!isEmpty()){
        return Q.q[Q.f++];
    }
}

struct BFSTable{
    int color;
    int d;
    int pi;
}V[N];

void init(){
    for(int v=0;v<N;v++){
        V[v].color=WHITE;
        V[v].d=INF;
        V[v].pi=-1;
    }
}

void BFS(int G[N][N],int s){
    init();
    V[s].d=0;
    V[s].pi=-1;
    V[s].color=GRAY;
    enqueue(s);
    while(!isEmpty()){
        int u;
        u=dequeue();
        for(int v=0;v<N;v++)
        {
            if(G[u][v]!=0){
                if(V[v].color==WHITE){
                    V[v].color=GRAY;
                    V[v].d=V[u].d+1;
                    V[v].pi=u;
                    enqueue(v);
                }
            }
        }
        V[u].color=BLACK;
    }
}

void printTable(){
    printf("\n BFS \n");
    printf("\n Node \t Color \t Dist \t Parent \n");
    printf("-------------------------\n");
    for(int v=0;v<N;v++){
        printf("\n%c\t%d\t%d\t%c\n",ch[v],V[v].color,V[v].d,ch[V[v].pi]);
    }
}

void printPath(){
    int t=5;
    int s=0;
    printf("\n Path from %c ---> %c\n",ch[s],ch[t]);
    for(int v=t;v!=-1;v=V[v].pi){
        printf("%c<---",ch[v]);
    }
}

void main(){
    int G[N][N]={{0,7,0,0,4,0},
                 {0,0,5,3,0,0},
                 {0,0,0,0,0,8},
                 {0,0,3,0,0,5},
                 {0,3,0,2,0,0},
                 {0,0,0,0,0,0}};
    int s;
    BFS(G,s);
    printTable();
    printPath();
}


