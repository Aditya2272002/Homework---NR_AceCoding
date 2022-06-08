#include<bits/stdc++.h>
using namespace std;

//counting frequencies of all elements in array having elements 0 to n-1 
void countFreq(int arr[],int n,int p){ 
   int t = n;
   for(int i=0;i<n;i++){
      int index = arr[i]%t;
      arr[index] += t;
   }

   for(int i=0;i<n;i++){
      int count = arr[i]/t;
      //arr[i] = arr[i] - count*n; // making array back to original array 
      //cout<<i<<":"<<count<<" ";
      arr[i] = count;
   }
}


int main()
{
   //int arr[] = {2,4,5,6,8};
   int arr[] = {2 ,3 ,1 , 2 ,3};
   // int arr[] = {2,7,1,4,1,7,8,2,8};

   int n = sizeof(arr)/sizeof(arr[0]);
   int p = 10;

   // for range (1-n)
   // for(int i=0;i<n;i++){
   //    arr[i] = arr[i] - 1;
   // }

   countFreq(arr,n,n);

   for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }

   return 0;
}