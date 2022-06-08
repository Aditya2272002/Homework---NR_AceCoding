#include<bits/stdc++.h>
using namespace std;

void getLongestSubarrayWithSumZero(int arr[],int n,int &startMax,int &endMax){
   int prefixSum = 0;
   int start = 0,end = 0;
   int res = INT_MIN;
   unordered_map<int,int> mp;

   for(int i=0;i<n;i++){
      prefixSum += arr[i];
      if(mp.find(prefixSum) != mp.end()){
         start = mp[prefixSum] + 1;
         end = i;
         if(res < (end-start+1)){
            res = end-start+1;
            startMax = start;
            endMax = end;
         }
      }

      if(prefixSum == 0){
         start = 0;
         end = i;

         if(res < (end-start+1)){
            res = end-start+1;
            startMax = start;
            endMax = end;
         }
      }

      mp.insert({prefixSum,i});
   }
}

void getLongestSubarray(int arr1[],int arr2[],int n){
   // Contains Difference of both arrays  
   int temp[n];
   for(int i=0;i<n;i++){
      temp[i] = arr2[i] - arr1[i];
   }

   int startMax = 0;
   int endMax = 0;
   getLongestSubarrayWithSumZero(temp,n,startMax,endMax);

   for(int i=startMax;i<=endMax;i++){
      cout<<arr1[i]<<" ";
   }cout<<"\n";

   for(int i=startMax;i<=endMax;i++){
      cout<<arr2[i]<<" ";
   }

}

int main()
{
   int arr1[] = {0,1,0,0,0,0};
   int arr2[] = {1,0,1,0,0,1};
   int n = 6;

   getLongestSubarray(arr1,arr2,n);


   return 0;
}