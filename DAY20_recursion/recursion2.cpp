#include<bits/stdc++.h>
using namespace std;
// 2.
// Finding the sum of all elements of the array using recursion.

int goSum(int arr[],int n,int sums){
   static int i = 0;
   if(i>n){
      return sums;
   }
   sums = sums + arr[i];
   i++;
   goSum(arr,n,sums);
}

int S(int arr[],int i){
   static int sum = 0;
   if(i==0)return arr[0];
   sum = arr[i] + S(arr,i-1);
   return sum; 
}

int main()
{
   int arr[] = {1,2,3,4,100};   // 19
   int n = sizeof(arr)/sizeof(arr[0]);
   int sums = 0;
   cout<<goSum(arr,n-1,sums)<<" ";
   cout<<S(arr,n-1)<<" ";
   return 0;
}