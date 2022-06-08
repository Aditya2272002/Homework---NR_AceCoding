#include<bits/stdc++.h>
using namespace std;

void getSubArray(int arr[],int n,int &startMax,int &endMax){
   int prefixSum = 0;
   unordered_map<int,int> mp;
   int res = INT_MIN;
   int start = 0,end = 0;

   for(int i=0;i<n;i++){
      prefixSum = prefixSum + arr[i];

      if(mp.find(prefixSum) != mp.end()){
         start = mp[prefixSum] + 1;
         end = i;
         
         if(res < (end-start+1)){
            res = end - start + 1;
            startMax = start;
            endMax = end; 
         }
      }

      if(prefixSum == 0){
         start = 0;
         end = i;
         if(res < (end-start+1)){
            res = end - start + 1;
            startMax = start;
            endMax = end; 
         }
      }

      mp.insert({prefixSum,i});
   }
}


int main(){
   int arr[] = {1,0,1,1,1,0,0};
   int n = sizeof(arr)/sizeof(arr[0]);

   for(int i=0;i<n;i++){
      if(arr[i] == 0)
         arr[i] = -1;
   }

   int start = 0,end = 0;

   getSubArray(arr,n,start,end);

   for(int i=0;i<n;i++){
      if(arr[i] == -1)
         arr[i] = 0;
   }

   for(int i=start;i<=end;i++){
      cout<<arr[i]<<" ";
   }

   return 0;
}