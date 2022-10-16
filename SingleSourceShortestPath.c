#include<stdio.h>
int d[50];
int x[50][50];
void sssp(int i,int n)
{
	int j,m,k,q,l;
	for(m=1;m<=n;m++)
	{
		d[m]=x[i][m];
	}
	for(k=2;k<n;k++)
	{
		for(j=1;j<=n;j++)
		{
			for(m=1;m<=n;m++)
			{
				if(m!=j)
				{
					q=d[m]+x[m][j];
					if(q<d[j])
					d[j]=q;
				}
			}
		}
	}
	for(l=1;l<=n;l++)
	{
		printf("\n Shortest distance from source node %d to node %d= ",i,l);
		printf("%d\t",d[l]);
	}
}
int main()
{
	int l,j,n,i;
	printf("\n Enter Total no. of node: ");
	scanf("%d",&n);
	for(l=1;l<=n;l++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\n x[%d][%d] :" ,l,j);
			scanf("%d",&x[l][j]);
		}
	}
	printf("\n Please enter source node:- ");
	scanf("%d",&i);
	sssp(i,n);
}