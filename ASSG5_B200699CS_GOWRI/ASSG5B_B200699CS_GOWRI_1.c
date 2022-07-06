#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void RemoveSelfLoop(int n,int A[][n])
{
    for(int i=0;i<n;i++)
    {
        if(A[i][i]==1)
        {
            A[i][i]==0;
        }
    }
}
void RemoveParallel(int n, int A[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==A[j][i])
            {
                int less;
                if(A[i][j]>A[j][i])
                {less=A[j][i];}
                else
                {less=A[i][j];}
                A[i][j]=less;
                A[j][i]=less;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int A[n][n];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",i);
        for(j=0;j<n;j++)
        {
            if(A[i][j]==1)
            {
                printf("%d ",j);
            }
        }
        printf("\n");
    }
    return 0;
}