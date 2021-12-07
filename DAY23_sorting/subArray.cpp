#include<bits/stdc++.h>
using namespace std;

void subArray(int arr[],int n){
   for(int size=1;size<=n;size++){
      for(int start=0;start<n-size-1;start++){
         for(int i=start;i<size+start;i++){
            cout<<arr[i]<<",";
         }
         cout<<"\n";
      }
   }
}

int main()
{
   int arr[] = {1,2,3};
   int n = sizeof(arr)/sizeof(arr[0]);
   for(int size=1;size<=n;size++){
      for(int start=0;start<=n-size;start++){
         for(int i=start;i<start+size;i++){
            cout<<arr[i]<<" ";
         }
         cout<<"\n";
      }
   }
   return 0;
}