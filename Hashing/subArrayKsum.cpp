#include<bits/stdc++.h>
using namespace std;

/*
In previous sum with zero exist or not :- we were finding (prefixSum - 0) exist or not;
                                          Here we will find (prefixSum - sum) exist already or not.
*/

bool isSumK(int arr[],int n,int k){
   int prefixSum = 0;
   unordered_set<int> s;
   for(int i=0;i<n;i++){
      prefixSum = prefixSum + arr[i];
      
      if(prefixSum == k)
         return true;
      if(s.find(prefixSum - k) != s.end()){
         return true;
      }
      s.insert(prefixSum);
   }
   return false;
}

void isSumKwithIndex(int arr[],int n,int k,int &startMax,int &endMax){
   int prefixSum = 0;
   unordered_map<int,int> mp;
   int start = 0;
   int end = 0;
   int res = INT_MIN;

   for(int i=0;i<n;i++){
      prefixSum = prefixSum + arr[i];
      if(mp.find(prefixSum - k) != mp.end()){
         start = mp[prefixSum-k] + 1;
         end = i;
                  
         if((end - start + 1) > res){
            startMax = start;
            endMax = end;
            res = end - start + 1;
         }
      }

      if(prefixSum == k){
         start = 0;
         end = i;
         if((end - start + 1) > res){
            startMax = start;
            endMax = end;
            res = end - start + 1;
         }
      }

      //cout<<start<<" "<<end<<"\n";

      mp.insert({prefixSum,i});
   }
}

int main()  
{
   int arr[] = {3,1,0,1,8,2,3,6};
   int n = 8;
   int start = -1;
   int end = -1;

   //cout<<isSumK(arr,n,22);
   isSumKwithIndex(arr,n,5,start,end);
   for(int i=start;i<=end;i++){
      cout<<arr[i]<<" ";
   }

   return 0;
}