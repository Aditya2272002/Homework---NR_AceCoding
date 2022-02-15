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


//This detect loop when there is one component in GRAPH.
bool cycleDetection(vector<int> adjList[],bool visited[],int src,int parent){
      
   visited[src] = true;
   
   for(int x:adjList[src]){
      if(visited[x]==false){
         if(cycleDetection(adjList,visited,x,src)){
            return true;
         }
      }
      else if(x!=parent){
         return true;
      }
   }
   return false;
}


bool isCycle(int V, vector<int> adj[]) {
   bool visited[V];
   memset(visited,false,sizeof(visited));
        
   //This loop is for covering when graph is Disjoint i.e multiple Graph in ONE.
   for(int i=0;i<V;i++){
      if(visited[i]==false)
         if(cycleDetection(adj,visited,i,-1))
            return true;
   }
   return false;
}




int main()
{
   fun();
   int n,e;
   cin>>n>>e;
   vector<int> adjList[n];
   bool visited2[n];
   memset(visited2,false,sizeof(visited2));

   for(int i=0;i<e;i++){
      int u,v;
      cin>>u>>v;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
   }
   
   
   // cout<<cycleDetection(adjList,visited2,0,-1);
   cout<<isCycle(n,adjList);
   

   return 0;
}