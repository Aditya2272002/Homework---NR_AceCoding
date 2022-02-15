#include<bits/stdc++.h>
using namespace std;


//BFS like Sorting
void topologicalSort(vector<int> adj[],vector<int> indegree,int n){
   queue<int> q;
   for(int i=0;i<n;i++){
      if(indegree[i]==0){
         q.push(i);
      }
   }

   while(!q.empty()){
      int cur = q.front();
      q.pop();
      cout<<cur<<" ";
      for(int nbr:adj[cur]){
         indegree[nbr] = indegree[nbr] - 1;
         if(indegree[nbr]==0){
            q.push(nbr);
         }
      }
   }
   cout<<"\n";
   
}


int main(){
   int n,e;
   cout<<"Enter nodes,edges :- \n";
   cin>>n>>e;

   vector<int> adj[n];
   vector<int> indegree(n,0);
   
   
   cout<<"Enter edges :-\n";
   for(int i=0;i<e;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      indegree[v] = indegree[v] + 1;
   }


   cout<<"\n";
   // for(int i=0;i<n;i++){
   //    cout<<indegree[i]<<" ";
   // }

   topologicalSort(adj,indegree,n);

   

   return 0;
}


