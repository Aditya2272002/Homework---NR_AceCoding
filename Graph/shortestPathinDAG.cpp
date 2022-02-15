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

vector<int> ans;
void topologicalSort(vector<pair<int,int>> adj[],vector<int> indegree,int n){
   queue<int> q;
   for(int i=0;i<n;i++){
      if(indegree[i]==0){
         q.push(i);
      }
   }

   while(!q.empty()){
      int cur = q.front();
      q.pop();
      ans.push_back(cur);
      cout<<cur<<" ";
      for(pair<int,int> nbr:adj[cur]){
         indegree[nbr.first] = indegree[nbr.first] - 1;
         if(indegree[nbr.first]==0){
            q.push(nbr.first);
         }
      }
   }
   cout<<"\n";
   
}


void shortestPathDAG(vector<pair<int,int>> adj[],vector<int>& dist,int src){

   dist[src] = 0;

   for(int i=0;i<ans.size();i++){
      int cur = ans[i];
      for(pair<int,int> nbr:adj[cur]){
         int u = cur;
         int v = nbr.first;
         int w = nbr.second;

         if(dist[v] > dist[u]+ w){
            dist[v] = dist[u]+ w;
         }
      }
   }

   cout<<"\nShortest from source distance is:-\n";
   for(int i=0;i<dist.size();i++){
      cout<<"("<<src<<","<<i<<")"<<" -> ";
      cout<<dist[i]<<"\n";
   }
   cout<<"\n";
}




/*

STEPS:- 
1. Dist[] = {INF,INF,INF,.....}
2. Dist[0] = 0
3. Topoological Sort
4. Iterate over topological sort array
   4.1   Iterate over each adjacent of elements of topological sorted array
         and Relax that edge if possible, i.e
            if(Dist[v] > Dist[u] + weight(u,v)){
               Dist[v] = Dist[u] + weight(u,v);
            }
*/



int main(){

   fun();

   int n,e;
   cin>>n>>e;

   vector<pair<int,int>> adj[n];
   vector<int> indegree(n,0);
   
   for(int i=0;i<e;i++){
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
      indegree[v] = indegree[v] + 1;
   }


   cout<<"Indegree Array:- \n";
   for(int i=0;i<n;i++){
      cout<<indegree[i]<<" ";
   }
   cout<<"\n";

   cout<<"Topological Sort:- \n";
   topologicalSort(adj,indegree,n);


   vector<int> dist(n,INT_MAX);
   int src = 0;

   shortestPathDAG(adj,dist,src);
   

   return 0;
}


