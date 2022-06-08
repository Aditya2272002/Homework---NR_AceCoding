#include<bits/stdc++.h>
using namespace std;

pair<int,int> getPair(int arr[],int n,int sum){
   int p1 = 0,p2 = 0;
   unordered_map<int,int> mp;
   for(int i=0;i<n;i++){
      mp[arr[i]]++;
   }

   for(int i=0;i<n;i++){
      int s = sum - arr[i];
      auto t = mp.find(s);
      if(t != mp.end()){
         if(s == arr[i] && mp[s] > 1){
            p2 = p1 = t->first;
         }else if(s != arr[i]){
            p1 = arr[i];
            p2 = s;
         }
      }
   }
   return {p1,p2};
}

pair<int,int> getPair2(int arr[],int n,int sum){
   unordered_set<int> s;
   for(int i=0;i<n;i++){
      int t = sum - arr[i];
      auto x = s.find(t);
      if(x != s.end()){
         return {arr[i],*x};
      }else{
         s.insert(arr[i]);
      }
   }
   return {-1,-1};
}

int main()
{
   int arr[] = {3,2,8,15,-8};
   int n = 5;
   int sum = 17;

   pair<int,int> t = getPair2(arr,n,sum);
   cout<<t.first<<","<<t.second;

   return 0;
}