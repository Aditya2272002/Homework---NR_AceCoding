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


class DSU{
   private:
      int *leader;
      int *rank;
   
   public:
      DSU(int n){
         leader = new int[n];
         rank = new int[n];

         for(int i=0;i<n;i++){
            leader[i] = -1;
            rank[i] = 1;
         }
      }

      int find(int x){
         if(leader[x]==-1){
            return x;
         }else{
            return leader[x] = find(leader[x]);
         }
      }

      void Union(int a,int b){
         int captainA = find(a);
         int captainB = find(b);

         if(captainA != captainB){
            if(rank[captainA] > rank[captainB]){
               leader[captainB] = captainA;
               rank[captainA] += rank[captainB];
            }else{
                leader[captainA] = captainB;
               rank[captainB] += rank[captainA];
            }
         }
      }
};

void krushkal(vector<pair<int,pair<int,int>>>& edges,int n){
   DSU dsu(n);
   vector<pair<int,pair<int,int>>> mstEdges;

   sort(edges.begin(),edges.end());

   for(int i=0;mstEdges.size()< n-1;i++){
      pair<int,pair<int,int>> curEdge = edges[i];
      int w = curEdge.first;
      int u = curEdge.second.first;
      int v = curEdge.second.second;

      if(dsu.find(u) == dsu.find(v)){
         continue;
      }

      mstEdges.push_back(curEdge);
      dsu.Union(u,v);
   }


   for(auto x:mstEdges){
       int w = x.first;
      int u = x.second.first;
      int v = x.second.second;
      cout<<u<<"->"<<v<<" has weight: "<<w<<"\n";
   }

}


int main()
{
   fun();
   
   int n,e;
   cin>>n>>e;

   vector<pair<int,pair<int,int>>> adj;
 
   for(int i=0;i<e;i++){
      int u,v,w;
      cin>>u>>v>>w;
      
      adj.push_back({w,{u,v}});
   }

   krushkal(adj,n);
   

   return 0;
}