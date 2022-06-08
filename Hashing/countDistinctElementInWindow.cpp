#include<bits/stdc++.h>
using namespace std;

 void getDistinctInWindow(int arr[],int n,int k){
      unordered_map<int,int> s;
      int l=0,r=k-1;
      int maxAns = INT_MIN;

      //first window
      for(int i=l;i<=r;i++){
            s[arr[i]]++;
      }
      cout<<s.size()<<" ";

      for(int j=1;j<=n-k;j++){
         l++;
         r++;
         s[arr[l-1]]--;
         s[arr[r]]++;

         if(s[arr[l-1]] == 0){
            s.erase(arr[l-1]);
         }
         cout<<s.size()<<" ";
      }
   }

int main(){

   int arr[] = {10,20,20,10,30,40,10};
   int n = sizeof(arr)/sizeof(arr[0]);
   int k = 4;
   getDistinctInWindow(arr,n,k);
  
   
   return 0;
}