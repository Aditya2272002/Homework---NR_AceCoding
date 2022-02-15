#include<bits/stdc++.h>
using namespace std;

int mini(int distance[],bool visited[],int n){
   int ans = INT_MAX;
   int index;
   for(int i=0;i<n;i++){
      if(visited[i] == false){
         if(ans > distance[i]){
            ans = distance[i];
            index = i;
         }
      }
   }
   return index;
}

void dijakstra( vector<pair<int,int>> adj[],bool visited[],int distance[],int n){
 
   for(int i=0;i<n;i++){
      int minIndex = mini(distance,visited,n);
      visited[minIndex] = true;
   
      for(pair<int,int> j:adj[minIndex]){
         if(visited[j.first]==false){
            distance[j.first] = min(distance[j.first], j.second + distance[minIndex]);
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
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
   }

   bool visited[n];
   memset(visited,false,sizeof(visited));

   int distance[n];
   for(int i=0;i<n;i++){
      distance[i] = 10000;
   }
   distance[0] = 0;

   dijakstra(adj,visited,distance,n);

   cout<<"\nDistance  :- \n";
   for(int i=0;i<n;i++){
      cout<<distance[i]<<" ";
   }

   return 0;
}

/*
4 5

0 1 5
0 2 3
0 3 6
1 3 2
2 3 1

*/