#include <stdio.h>
int x [50][50];
int y [50][50];
int apsp(int n)
{
    int i,j,k,q;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            x[i][j]=y[i][j];//coping the matrix
        }
    }
    printf("\n X0 :\t");
    for(i=0;i<n;i++)
    {
        printf(" %d\t",i+1);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %d\t",i+1);
        for(j=0;j<n;j++)
        {
            printf(" %d\t",x[i][j]);
        }
        printf("\n");
    }
    for(k=0;k<n;k++)
    {
        printf(" \n X%d : \n",k+1);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                q=x[i][k]+x[k][j];
                if(q<x[i][j])
                x[i][j]=q;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf(" %d\t",x[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
int main()
{
    int n,i,j;
    printf("\n Enter the number of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\n y[%d][%d] = ",i,j);
            scanf("%d",&y[i][j]);
        }
    }
    return apsp(n);
}