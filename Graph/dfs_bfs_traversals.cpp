#include<bits/stdc++.h>
using namespace std;

//like : preorder traversal
void dfs(int src,vector<int> adj[],bool visited[]){
   if(visited[src]) return;

   cout<<src<<" ";
   visited[src] = true;
   for(int nbr:adj[src]){
      dfs(nbr,adj,visited);
   }
}


//like : levelorder traversal
void bfs(int src,vector<int> adj[],int n){
   queue<int> q;
   q.push(src);
   bool visited2[n];
   memset(visited2,false,sizeof(visited2));

   while(!q.empty()){
      int cur = q.front();
      q.pop();
      if(visited2[cur] == true) 
         continue;

      cout<<cur<<" ";
      visited2[cur] = true;

      for(int nbr:adj[cur]){
         q.push(nbr);
      }
   }
}

int main()
{
   int n,e;
   cout<<"Enter nodes and edges :- \n";
   cin>>n>>e;

   vector<int> adj[n];

   cout<<"Enter edges : -\n";
   for(int i=0;i<e;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   // bool visited1[n];
   // memset(visited1,false,sizeof(visited1));

   // cout<<"DFS travesal :- \n";
   // dfs(0,adj,visited1);
   // cout<<"\n";

  
   cout<<"BFS travesal :- \n";
   bfs(0,adj,n);
   cout<<"\n";


   return 0;
}


/*
6 6

0 1
0 3
1 3
1 2
3 4
3 5



*/