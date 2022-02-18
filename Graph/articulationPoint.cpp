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
bool articulationPoints[mSize];
int curTime = 1;


void dfs2(int u,vector<int> adj[]){
   disc[u] = low[u] = curTime++;
   visited[u] = true;
   int child = 0;

   for(int v:adj[u]){
      if(!visited[v]){

         child++;
         parent[v] = u;
         dfs2(v,adj);

         low[u] = min(low[u],low[v]);

         //Root Node
         if (parent[u] == -1 && child > 1) 
			   cout<<u<<" ";   // articulationPoints[u] = true;
         //Other Nodes
			if (parent[u]!= -1 && low[v] >= disc[u]) 
			   cout<<u<<" ";   // articulationPoints[u] = true;

      }
      else if(v!=parent[u]){
         low[u] = min(low[u],disc[v]);
      }
   }
}

int main()
{
   fun();
   int t;
   cin>>t;
   for(int i=0;i<t;i++){
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
         articulationPoints[i] = false;
      }

      dfs2(1,adj);
      cout<<"\n";
   }

   return 0;
}