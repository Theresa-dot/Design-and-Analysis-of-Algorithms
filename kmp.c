#include<stdio.h>
#include<string.h>
int **findLPS(char *pat,int *lps,int m)
{
    int count,i;
    lps[0]=0;
    i=1;
    count=0;
    while(i<m)
    {
        if(pat[i]==pat[count])
        {
            lps[i++]=++count;
        }
        else
        {
            lps[i++]=0;
            count=0;
        }
    }
    return &lps;
}
void kmpAlgo(char *txt,char *pat)
{
    int n,m,i,j;
    n=strlen(txt);
    m=strlen(pat);
    int lps[m];
    for(i=0;i<m;i++)
        lps[i]=0;
    *lps=findLPS(pat,lps,m);
    printf("LPS Array is ");
    for(i=0;i<m;i++)
        printf("%d ",lps[i]);
    i=0;
    j=0;
    while((i<n) && (j<=m))
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j==0) i++;
            else j=lps[j-1];
        }
        if(j==m)
        {
            printf("\nFound the pattern at index %d",(i-j));
            j=0;
        }
    }
}
int main()
{
    char txt[]="aaacdfgeacbmaacabb";
    char pat[]="acabb";
    kmpAlgo(txt,pat);
}
