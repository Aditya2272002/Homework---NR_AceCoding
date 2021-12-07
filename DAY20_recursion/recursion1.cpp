#include<bits/stdc++.h>
using namespace std;
// 1.
// Finding the maximum/minimum element of the array using recursion.


int goMin(int arr[],int n,int mini){
   static int i = 1;
   if(i>n){
      return mini;
   }
   if(arr[i] < mini){
      mini = arr[i];
   }
   i++;
   goMin(arr,n,mini);
}

int goMax(int arr[],int n,int maxi){
    static int i = 1;
   if(i>n){
      return maxi;
   }
   if(arr[i] > maxi){
      maxi = arr[i];
   }
   i++;
   goMax(arr,n,maxi);
}

int main()
{

   int arr[] = {5,15,10,2,60,1,600};
   int n = sizeof(arr)/sizeof(arr[0]);
   int mini = arr[0];
   int maxi = arr[0];
   cout<<goMin(arr,n-1,mini)<<" ";
   cout<<goMax(arr,n-1,maxi)<<" ";
   // cout<<Min(arr,0,n)<<" ";
   return 0;
}