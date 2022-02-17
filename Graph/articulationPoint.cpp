#include<bits/stdc++.h>
using namespace std;
#define mSize 1000

void fun(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("input_test.txt","r",stdin);
   freopen("output_test.txt","w",stdout);
   #endif
   
}

int parent[mSize];
int disc[mSize];
int low[mSize];
bool visited[mSize];
int curTime = 1;

void dfs(int u,vector<int> adj[]){
   disc[u] = low[u] = curTime++;
   visited[u] = true;

   for(int v:adj[u]){
      if(v==parent[u]){
         continue;
      }else if(visited[v]){
         low[u] = min(low[u],disc[v]);
      }else{
         parent[v] = u;
         dfs(v,adj);
         low[u] = min(low[u],low[v]);

         if(low[v] > disc[u]){
            cout<<"Articulation Points are : "<<u<<","<<v<<"\n";
         }
      }
   }
}

int main()
{
   fun();
   int n,e;
   
   cin>>n>>e;

   vector<int> adj[n+1];

   for(int i=0;i<e;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   //Initializing
   for(int i=0;i<mSize;i++){
      parent[i] = -1;
      disc[i] = INT_MAX;
      low[i] = INT_MAX;
      visited[i] = false;
   }

   dfs(1,adj);
   

   return 0;
}