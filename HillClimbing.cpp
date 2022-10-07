//hill climbing is a mathematical optimization technique which belongs to the family of local search. 
//It is an iterative algorithm that starts with an arbitrary solution to a problem, then attempts to find a better solution by making an incremental change to the solution. 
//If the change produces a better solution, another incremental change is made to the new solution, and so on until no further improvements can be found. 


#include<iostream> 
#include<cstdio> 
using namespace std; 
//Calculate the cost to analyze
int calcCost(int arr[],int N)
{ 
  int c=0; 
  for(int i=0;i<N;i++)
  { 
    for(int j=i+1;j<N;j++) if(arr[j]<arr[i]) c++; 
  } 
  return c; 
} 
//Swap elements
void swap(int arr[],int i,int j)
{ 
  int tmp=arr[i]; 
  arr[i]=arr[j]; 
  arr[j]=tmp; 
} 
int main()
{ 
  int N; 
  cin>>N; 
  int arr[N]; 
  for(int i=0;i<N;i++) 
    cin>>arr[i];
  int bestCost=calcCost(arr,N),newCost,swaps=0;; 
  while(bestCost>0)
  { 
    for(int i=0;i<N-1;i++)
    { 
      swap(arr,i,i+1); 
      newCost=calcCost(arr,N); 
      if(bestCost>newCost)
      {
        cout<<"After swap: "<<++swaps<<endl; 
        for(int i=0;i<N;i++) 
          cout<<arr[i]<<endl;  
          bestCost=newCost; 
      } 
      else swap(arr,i,i+1); 
    } 
  } 
  cout<<"Final Ans"<<endl; 
  for(int i=0;i<N;i++) 
    cout<<arr[i]<<endl;
  return 0;
} 
