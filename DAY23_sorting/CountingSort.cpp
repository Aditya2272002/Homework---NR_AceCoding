#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n){
   for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }
   cout<<"\n";
}


void countingSort(int arr[],int n){
   printArray(arr,n);
   //freq array
   int h = 8;
   int freq[h];
   memset(freq,0,sizeof(freq));
   for(int i=0;i<n;i++){
      freq[arr[i]] += 1;
   }

   //prefix_array
   int prefix_arr[h];
   memset(prefix_arr,0,sizeof(prefix_arr));
   prefix_arr[0] = freq[0];
   for(int i=1;i<h;i++){
      prefix_arr[i] = prefix_arr[i-1] + freq[i];
   }

   //sorting
   int temp[n];
   memset(temp,0,sizeof(temp));
   for(int i=n-1;i>=0;i--){
      temp[prefix_arr[arr[i]] - 1] = arr[i];
      int t = prefix_arr[arr[i]] - 1;
      prefix_arr[arr[i]] = t;
   }
   printArray(temp,n);
   
   cout<<"\n";
}


int main()
{
   int arr[] = {6,6,5,7,7,3,2,1,1,1,1};
   int n = sizeof(arr)/sizeof(arr[0]);
   countingSort(arr,n);
   return 0;
}