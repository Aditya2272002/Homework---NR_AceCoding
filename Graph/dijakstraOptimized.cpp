#include<bits/stdc++.h>
using namespace std;



void dijakstra(int src,vector<pair<int,int>> adj[],bool visited[],int distance[]){

   distance[src] = 0;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   pq.push({0,src});

   while(!pq.empty()){
      pair<int,int> x = pq.top();
      pq.pop();
      
      int cost = x.first;
      int cur = x.second;

      if(visited[cur]){
         continue;
      }
      visited[cur] = true;
   
      for(pair<int,int> j:adj[cur]){
         if(visited[j.first]==false && distance[cur] + j.second < distance[j.first]){
            distance[j.first] = distance[cur]+j.second;
            pq.push({distance[j.first],j.first});
         }
      }
   }
}

int main()
{
   int n,e;
   cout<<"\nEnter nodes,edges :- \n";
   cin>>n>>e;

   vector<pair<int,int>> adj[n];

   cout<<"Enter Edges :- \n";
   for(int i=0;i<e;i++){
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].push_back({w,v});
      adj[v].push_back({w,u});
   }

   bool visited[n];
   memset(visited,false,sizeof(visited));

   int distance[n];
   for(int i=0;i<n;i++){
      distance[i] = 10000;
   }
  

   dijakstra(0,adj,visited,distance);

   cout<<"\nDistance  :- \n";
   for(int i=0;i<n;i++){
      cout<<distance[i]<<" ";
   }

   return 0;
}

