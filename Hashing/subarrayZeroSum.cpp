#include<bits/stdc++.h>
using namespace std;

/* 
   -> If an Array contains any subset with sum zero then in prefixSum array a particular element will be repeated,
      The index that element occured (first time + 1) is starting index and second time that element occured in prefixSum array 
      is the ending index of that subarray with sum zero.

   -> If at any point prefixSum is zero then subset from index 0 to the index of prefixSum is zero will be the subset with sum zero.


*/

bool isSumZero(int arr[],int n,int &start,int &end){
   int prefixSum = 0;
   unordered_map<int,int> myHash;
   
   for(int i=0;i<n;i++){
      prefixSum = prefixSum + arr[i];
      if(myHash.find(prefixSum) != myHash.end()){
         start = myHash[prefixSum]+1;
         end = i;
         return true;
      }
      if(prefixSum==0){
         start = 0;
         end = i;
         return true;
      }
      myHash.insert({prefixSum,i});
   }
   return false;
}

int main()
{
   // int arr[] = {1,4,13,-3,-10,5};
   int arr[] = {3,-2,-1,5};
   int n = 4;
   int start = 0,end = 0;
   cout<<isSumZero(arr,n,start,end)<<"\n";
   
   for(int i=start;i<=end;i++){
      cout<<arr[i]<<" ";
   }

}