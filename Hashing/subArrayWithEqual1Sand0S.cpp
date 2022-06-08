#include<bits/stdc++.h>
using namespace std;

void subArrayEqualOneandZero(int arr[],int n,int &maxStart,int &maxEnd){
   int prefixSum = arr[0];
   int previousPrefixSum = 0;

   unordered_map<int,int> mp;
   int c0 = 0,c1 = 0;
   mp.insert({arr[0],0});
   
   for(int i=1;i<n;i++){
      
      previousPrefixSum = prefixSum;
      prefixSum = prefixSum + arr[i];

      if(prefixSum - previousPrefixSum == 0){
         c0 += 1;
      }else{
         c1 += 1;
      }

      if(c0==c1){
         
      }
     
   }

}

int main()
{
   int arr[] = {1,0,1,1,1,0,0};
   int n = 7;
   int start = -1,end = -1;

   subArrayEqualOneandZero(arr,n,start,end);

   for(int i=start;i<=end;i++){
      cout<<arr[i]<<" ";
   }

   return 0;
}