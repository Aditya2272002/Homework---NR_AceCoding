#include<bits/stdc++.h>
using namespace std;

//Cycle Detectection
void dfs(int src,vector<int> adj[],bool visited[],int& flag){
   if(visited[src]){
      flag = 1;
      return; 
   }
   
   visited[src] = true;
   for(int nbr:adj[src]){
      dfs(nbr,adj,visited,flag);
   }
}


int main()
{
   int n,e;
   cout<<"Enter nodes, edges :- \n";
   cin>>n>>e;

   vector<int> adj[n];
   cout<<"Enter edges :- \n";
   for(int i=0;i<e;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
   }

   bool visited[n];
   memset(visited,false,sizeof(visited));
   int flag = 0;
   dfs(0,adj,visited,flag);

   cout<<flag;

   return 0;
}


/*

Cycle:-
6 6


0 1
1 2
2 3
3 5
3 4
4 4


No Cycle:-
6 5


0 1
1 2
2 3
3 5
3 4



11 11

7 0
0 4
4 5
5 6
6 8
8 9
9 3
3 2
2 1
1 10
4 6



*/