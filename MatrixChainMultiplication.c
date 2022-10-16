#include <stdio.h>

// Matrix Chain Multiplication
long m[10][10];
long MatrixChainMultiplication(long p[], long n);

int main()
{
    long size;
    printf("Enter the size of the array : ");
    scanf("%ld", &size);
    long arr[size];
    printf("Enter the elements of the array \n");
    for (int i = 0; i < size; i++)
    {
        printf("Element %d : ", i + 1);
        scanf("%ld", &arr[i]);
    }
    printf("Total Multiplication : %ld \n", MatrixChainMultiplication(arr, size));
    return 0;
}

long MatrixChainMultiplication(long p[], long n){
    long q,j;
    for(long i=1;i<n;i++)
        m[i][i]=0;
        for(long d=1;d<n-1;d++){
            for(long i=1;i<n-d;i++){
                j=i+d;
                m[i][j]=9999;
                for(long k=i;k<j;k++){
                    q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    if(q<m[i][j])
                    m[i][j]=q;
                }
            }
        }
    return m[1][n-1];
}