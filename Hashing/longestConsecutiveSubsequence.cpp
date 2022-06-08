#include<bits/stdc++.h>
using namespace std;

void getLongestConsecutiveSubsequence(int arr[],int n){
   unordered_set<int> s;
   int ans = 0;
   int maxAns = 0;
   int begin = -1;

   for(int i=0;i<n;i++){
      if(s.find(arr[i]) == s.end()){
         s.insert(arr[i]);
      }
   }

   for(int i:s){
      if(s.find(i-1) == s.end()){
         begin = i;
      }

      int t = 0;
      while(begin != -1){
         if(s.find(begin + t) != s.end()){
            ans++;
         }else{
            begin = -1;
         }
         t++;
      }
      maxAns = max(maxAns,ans);
      ans = 0;
   }
   cout<<maxAns;  

}

int main()
{
   int arr[] = {1,3,4,3,3,2,9,10};
   int n = sizeof(arr)/sizeof(arr[0]);
   
   getLongestConsecutiveSubsequence(arr,n);

   return 0;
}