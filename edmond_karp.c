#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 9

char ch[] = {'S', 'A', 'B', 'C', 'D', 't'};

struct Queue {
    int q[100];
    int f;
    int r;
} Q;

int isEmpty() {
    if ((Q.r == -1) || (Q.f == Q.r + 1)) {
        return 1;
    }
    else {
        return 0;
    }
}

void initQueue() {
    Q.f = Q.r = -1;
}

void enqueue(int value) {
    Q.q[++Q.r] = value;
}

int dequeue() {
    if (!isEmpty()) {
        return Q.q[Q.f++];
    }
}

struct BFSTable {
    int color;
    int d;
    int pi;
} V[N];

void init() {
    for (int v = 0; v < N; v++) {
        V[v].color = WHITE;
        V[v].d = INF;
        V[v].pi = -1;
    }
}

void BFS(int G[N][N], int s, int t, int R[N][N]) {
    init();
    V[s].d = 0;
    V[s].pi = -1;
    V[s].color = GRAY;
    enqueue(s);
    while (!isEmpty()) {
        int u = dequeue();
        for (int v = 0; v < N; v++) {
            if (R[u][v] > 0 && V[v].color == WHITE) {
                V[v].color = GRAY;
                V[v].d = V[u].d + 1;
                V[v].pi = u;
                enqueue(v);
            }
        }
        V[u].color = BLACK;
    }
}

int push(int G[N][N], int u, int t, int R[N][N], int f) {
    if (u == t) {
        return f;
    }
    for (int v = 0; v < N; v++) {
        if (R[u][v] > 0 && V[v].d == V[u].d + 1) {
            int df = push(G, v, t, R, (f < R[u][v]) ? f : R[u][v]);
            if (df > 0) {
                R[u][v] -= df;
                R[v][u] += df;
                return df;
            }
        }
    }
    return 0;
}

int edmondsKarp(int G[N][N], int s, int t) {
    int R[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            R[i][j] = G[i][j];
        }
    }
    int maxflow = 0;
    while (1) {
        BFS(G, s, t, R);
        if (V[t].color == BLACK) {
            int df;
            do {
                df = push(G, s, t, R, INF);
                maxflow += df;
            } while (df > 0);
        }
        else {
            break;
        }
    }
    return maxflow;
}

void main(){
    int G[N][N]={{ 0, 9, 1, 0, 10, 0, 0, 0, 6 },  
     { 0, 0, 5, 3, 4, 0, 0, 7, 0 },  
     { 0, 0, 0, 10, 0, 0, 0, 0, 0 },  
     { 0, 4, 7, 0, 5, 0, 0, 0, 0 },  
     { 0, 4, 0, 10, 0, 0, 0, 0, 7 },  
     { 0, 0, 5, 0, 0, 0, 9, 1, 0 },  
     { 0, 1, 0, 4, 0, 0, 0, 5, 0 },  
     { 0, 1, 6, 1, 5, 0, 0, 0, 5 },  
     { 0, 0, 0, 0, 0, 0, 0, 0, 0 }};  
    int s=0, t=8;
    int maxFlow = edmondsKarp(G, s, t);
    printf("Maximum flow is %d\n", maxFlow);
}