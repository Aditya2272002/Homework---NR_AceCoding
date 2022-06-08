#include<bits/stdc++.h>
using namespace std;

void subSet(int i,vector<int>& v,int n,int target,vector<int> cur,vector<vector<int>>& ans){
   if(i==n){
      int s = 0;
      for(int i:cur){
         s += i;
      }
      if(s==target){
         ans.push_back(cur);
      }
      return;
   }

   subSet(i+1,v,n,target,cur,ans);

   cur.push_back(v[i]);
   subSet(i+1,v,n,target,cur,ans);

   cur.pop_back();
}


int main(){
   vector<int> array = {2,2,3,6,7};
   int n = array.size();
   int target = 7;
   vector<int> cur;
   vector<vector<int>> ans;

   subSet(0,array,n,target,cur,ans);

   for(auto i: ans){
      for(int j:i){
         cout<<j<<" ";
      }
      cout<<"\n";
   }
   
   return 0;
}