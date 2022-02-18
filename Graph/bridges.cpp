#include<bits/stdc++.h>
using namespace std;
void fun(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("input_test.txt","r",stdin);
   freopen("output_test.txt","w",stdout);
   #endif
   
}

#define mSize 1000

int parent[mSize];
int disc[mSize];
int low[mSize];
bool visited[mSize];
int curTime = 1;

//Sir CODE
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
            cout<<"Bridge : ("<<u<<","<<v<<")\n";
         }
      }
   }
}

//Self CODE
void dfs2(int u,vector<int> adj[]){
   disc[u] = low[u] = curTime++;
   visited[u] = true;

   for(int v:adj[u]){
      if(!visited[v]){

         parent[v] = u;
         dfs2(v,adj);

         low[u] = min(low[u],low[v]);

         if(low[v] > disc[u]){
            cout<<"Bridge : ("<<u<<","<<v<<")\n";
         }
      }
      else if(visited[v] && v!=parent[u]){
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
      }

      dfs2(1,adj);
      cout<<"\n\n";
   }
   
   return 0;
}