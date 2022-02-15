#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adjList[],bool visited[],int n,int e,int src){

   queue<int> q;
   q.push(src);
   visited[src] = true;

   while(!q.empty()){
      int cur = q.front();
      q.pop();

      cout<<cur<<" ";
      for(int x:adjList[cur]){
         if(visited[x]==false){
            visited[x] = true;
            q.push(x);
         }
      }
   }
}

void dfs(vector<int> adjList[],bool visited[],int n,int e,int src){
   if(visited[src]==true)
      return;

   visited[src] = true;
   cout<<src<<" ";
   for(int x:adjList[src]){
      if(visited[x]==false){
         dfs(adjList,visited,n,e,x);
      }
   }
}

int main()
{
   int n,e;
   cout<<"Enter nodes and edges :- \n";
   cin>>n>>e;
   vector<int> adjList[n];

   cout<<"Enter edges from u to v :- \n";
   for(int i=0;i<e;i++){
      int u,v;
      cin>>u>>v;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
   }


   //visited array purpose :-  It tells what nodes we have pushed in queue.
   // bool visited1[n];
   // memset(visited1,false,sizeof(visited1));
   // bfs(adjList,visited1,n,e,0);


   cout<<"\n";

   //visited array purpose :-  It tells what nodes we have pushed in queue.
   bool visited2[n];
   memset(visited2,false,sizeof(visited2));
   dfs(adjList,visited2,n,e,0);

   return 0;
}