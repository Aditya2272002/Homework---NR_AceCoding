#include<bits/stdc++.h>
using namespace std;
// 1.
// Finding the maximum/minimum element of the array using recursion.

int Min(int arr[],int i,int n){
   if(i==n-1)
   return arr[i]; 
   return min(arr[i],Min(arr,i+1,n));
}


int Max(int arr[],int i,int n){
   if(i==n-1)
   return arr[i]; 
   return max(arr[i],Max(arr,i+1,n));
}

int main()
{

   int arr[] = {5,15,10,2,60,10,600};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout<<Min(arr,0,n)<<" ";
   cout<<Max(arr,0,n)<<" ";
   return 0;
}