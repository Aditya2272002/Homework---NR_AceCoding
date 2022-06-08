#include<bits/stdc++.h>
using namespace std;

int printing(vector<int>& c,vector<int>& pro){
   int ans = 0;
   for(int i:c){
      ans = ans + pro[i-1];
   }
   return ans;
}

void dfs(int src,vector<int> adj[],bool visited[],vector<int>& cur){
   if(visited[src]) return;

   cur.push_back(src);
   visited[src] = true;
   for(int nbr:adj[src]){
      dfs(nbr,adj,visited,cur);
   }
}

int main()
{
   int n,e;
   cout<<"Enter nodes and edges :- \n";
   cin>>n>>e;

   vector<int> adj[n+1];

   cout<<"Enter edges : -\n";
   for(int i=1;i<=e;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   cout<<"\n";

   bool visited1[n+1];
   memset(visited1,false,sizeof(visited1));

   vector<int> cur;
   vector<int> pro;
   cout<<"Enter profit \n";
   for(int i=0;i<n;i++){
      int p;
      cin>>p;
      pro.push_back(p);
   }

   int res = INT_MIN;

   for(int i=1;i<=n;i++){
      if(visited1[i]==false){
         dfs(i,adj,visited1,cur);
         res = max(res,printing(cur,pro));
         cur.clear();
      }
   }
 
  
   cout<<"\n"<<res<<" ";
   return 0;
}


