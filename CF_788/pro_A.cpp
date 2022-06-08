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

int main(){

   fun();

   int t;
   cin>>t;

   while(t--){
      int n,m;
      cin>>n>>m;
      vector<string> v;

      for(int i=0;i<n;i++){
         string s;
         cin>>s;
         v.push_back(s);
      }

      vector<int> ans;
      
      for(string t:v){
         int temp = 0;
         for(auto i:t){
            temp += (i-'a'+1);
         }
         ans.push_back(temp);
      }

      for(int i:ans){
         cout<<i<<" ";
      }
      cout<<"\n";

      sort(ans.begin(),ans.end());
      for(int i:ans){
         cout<<i<<" ";
      }
      cout<<"\n";

      int mini = INT_MAX;
      for(int i=0;i<n-1;i++){
         mini = min(mini,ans[i+1] - ans[i]);
      }

      cout<<mini<<"\n";

   }
}
