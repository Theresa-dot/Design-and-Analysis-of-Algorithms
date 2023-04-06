#include <stdio.h>

void print_path(int l1[], int l2[], int f1[], int f2[], int n, int e1, int e2, int x1, int x2) {
    // Determine which line to end on based on the final costs
    int min_cost, end_line;
    if (f1[n-1] + x1 < f2[n-1] + x2) {
        min_cost = f1[n-1] + x1;
        end_line = 1;
    }
    else {
        min_cost = f2[n-1] + x2;
        end_line = 2;
    }

    // Follow the path backwards from the end line
    printf("Optimal Path:\n");
    int current_line = end_line;
    int current_station = n;
    printf("Line %d, Station %d <--", current_line, current_station);
    for (int i = n-1; i > 0; i--) {
        if (current_line == 1) {
            current_line = l1[i];
        }
        else {
            current_line = l2[i];
        }
        printf("Line %d Station %d <--", current_line, i);
    }
    printf("Minimum cost: %d\n", min_cost);
}


int main(){
    int n=6;
    int a1[]={7,9,3,4,8,4};
    int a2[]={8,5,6,4,5,7};
    int l1[n];
    int l2[n];
    int t1[]={2,3,1,3,4};
    int t2[]={2,1,2,2,1};
    int e1=2,e2=4,x1=3,x2=2;
    l1[0]=1;l2[0]=2;
    int f1[n],f2[n];
    f1[0]=e1+a1[0];
    f2[0]=e2+a2[0];
    for(int i=1;i<n;i++){
        if(f1[i-1]+a1[i]<f2[i-1]+t2[i-1]+a1[i]){
            f1[i]=f1[i-1]+a1[i];
            l1[i]=1;
        }
        else{
            f1[i]=f2[i-1]+t2[i-1]+a1[i];
            l1[i]=2;
        }
        if(f2[i-1]+a2[i]<f1[i-1]+t1[i-1]+a2[i]){
            f2[i]=f2[i-1]+a2[i];
            l2[i]=2;
        }
        else{
            f2[i]=f1[i-1]+t1[i-1]+a2[i];
            l2[i]=1;
        }
    }
    printf("f1 f2\n");
    for(int i=0;i<n;i++) printf("%d %d\n",f1[i],f2[i]);
    printf("l1 l2\n");
    for(int i=0;i<n;i++) printf("%d %d\n",l1[i],l2[i]);
    print_path(l1, l2, f1, f2, n, e1, e2, x1, x2);
    return 0;
}
