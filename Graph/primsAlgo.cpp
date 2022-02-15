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

int getMiniNotInMST(int dist[],bool mst[],int n){
   int mini_index = 0,mini_val=INT_MAX;

   for(int i=0;i<n;i++){
      if(mst[i]==false && dist[i] < mini_val){
         mini_val = dist[i];
         mini_index = i;
      }
   }
   return mini_index;
}

void primsAlgo( vector<pair<int,int>> adj[],int n,int src){
   int dist[n];
   bool mst[n];
   int parent[n];

   for(int i=0;i<n;i++){
      dist[i] = INT_MAX;
      mst[i] = false;
      parent[i] = -1;
   }
   //Source 
   dist[src] = 0;

   for(int i=0;i<n-1;i++){
      int node = getMiniNotInMST(dist,mst,n);
      mst[node] = true;

      for(pair<int,int> p:adj[node]){
         int nbr = p.first;
         int cost = p.second;

         if(mst[nbr]==false && dist[nbr] > cost){
            dist[nbr] = cost;
            parent[nbr] = node;
         }
      }
   }

   for(int i=0;i<n;i++){
      cout<<"Node : "<<i<<" has Parent : "<<parent[i]<<"\n";
   }

}


int main()
{
   fun();
   
   int n,e;
   cin>>n>>e;

   vector<pair<int,int>> adj[n];
 
   for(int i=0;i<e;i++){
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
   }

   primsAlgo(adj,n,0);
   

   return 0;
}