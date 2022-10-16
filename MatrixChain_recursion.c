// matrix chain using recursion
#include <stdio.h>
int MatrixChainMultiplication(int p[],int i,int j){
    int count,min=9999;
    if(i==j)
    return 0;
    for(int k=i;k<j;k++){
        count=MatrixChainMultiplication(p,i,k)+MatrixChainMultiplication(p,k+1,j)+p[i-1]*p[k]*p[j];
        if(count<min)
        min=count;
    }
    return min;
}
int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array \n");
    for (int i = 0; i < size; i++)
    {
        printf("Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Total Multiplication : %d \n", MatrixChainMultiplication(arr,1,size-1));
    return 0;
}