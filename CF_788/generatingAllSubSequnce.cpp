#include<bits/stdc++.h>
using namespace std;

void fun(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("i.txt","r",stdin);
   freopen("o.txt","w",stdout);
   #endif
}


void go(int ind,vector<int> &cur,vector<int> &arr,int n){
   if(ind == n){
      for(int i:cur){
         cout<<i<<" ";
      }

      if(cur.size()==0){
      cout<<"{}"<<" ";
   }
      cout<<"\n";
      return ;
   }else{

      //pick
      cur.push_back(arr[ind]);
      go(ind+1,cur,arr,n);
      cur.pop_back();

      //not pick
      go(ind+1,cur,arr,n);
   }
}

void f(vector<int> &arr,vector<int> &cur,int visited[],vector<vector<int>> &ans){
   if(cur.size() == arr.size()){
      ans.push_back(cur);
      return;
   }

   for(int i=0;i<arr.size();i++){
      if(visited[i]==0){
         cur.push_back(arr[i]);
         visited[i] = 1;
         f(arr,cur,visited,ans);
         visited[i] = 0;
         cur.pop_back();
      }
   }
}

int main(){
   //fun();
   vector<int> arr = {1,2,3};
   int n = arr.size();
   vector<int> cur;
   int visited[n];
   for(int i=0;i<n;i++) visited[i] = 0;
   vector<vector<int>> ans;
   f(arr,cur,visited,ans);

   for(auto i:ans){
      for(int j:i){
         cout<<j<<" ";
      }
      cout<<"\n";
   }

}