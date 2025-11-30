#include<stdio.h>
#include<stdlib.h>
#define N 10
#define MAXLEN 30
int main()
{
int **p;
p=(int **)malloc(N*sizeof(int *));
for(int i=0;i<N;i++)
{
    p[i] = (int *)malloc(MAXLEN * sizeof(int));
    for(int j=0;j<MAXLEN;j++)
    {
        p[i][j]=30*i+j;
    }
}
for(int i=0;i<N;i++)
{
    printf("\n");
    for(int j=0;j<MAXLEN;j++)
    {
        printf("%03d ",p[i][j]);
    }
}
}