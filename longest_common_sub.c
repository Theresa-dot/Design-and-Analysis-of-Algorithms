#include <stdio.h>
#include <string.h>

int max(int a,int b){
    return (a>b)?a:b;
}

int min(int a,int b){
    return (a<b)?a:b;
}

void lcs(char c1[], char c2[], int n, int m,int t[m+1][n+1]) {
    char result[min(n,m)];
    int i = m, j = n, index = 0;
    while (i > 0 && j > 0) {
        if (c2[i-1] == c1[j-1]) {
            result[index++] = c2[i-1];
            i--;
            j--;
        }
        else if (t[i-1][j] > t[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    printf("\nLargest Common Subsequence: ");
    for (int k = index - 1; k >= 0; k--) {
        printf("%c", result[k]);
    }
}



int main(){
    char c1[]="ABAABA";
    char c2[]="BABBAB";
    int n=strlen(c1);
    int m=strlen(c2);
    int t[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            t[i][j]=0;
        }
    }
    for(int i=0,k=1;i<m;i++,k++){
        for(int j=0,l=1;j<n;j++,l++){
            if(c2[i]==c1[j]) t[k][l]=t[k-1][l-1]+1;
            else t[k][l]=max(t[k][l-1],t[k-1][l]);
        }
    }
    printf("FINAL TABLE");
    for(int i=0;i<=m;i++){
        printf("\n");
        for(int j=0;j<=n;j++){
            printf("%d  ",t[i][j]);
        }
    }
    lcs(c1,c2,n,m,t);
}