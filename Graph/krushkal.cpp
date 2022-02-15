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
      int *captain;
      int *rank;
   
   public:
      DSU(int n){
         captain = new int[n];
         rank = new int[n];

         for(int i=0;i<n;i++){
            captain[i] = -1;
            rank[i] = 1;
         }
      }

      int find(int x){
         if(captain[x]==-1){
            return x;
         }else{
            return captain[x] = find(captain[x]);
         }
      }

      void Union(int a,int b){
         int A = find(a);
         int B = find(b);

         if(A != B){
            if(rank[A] >= rank[B]){
               captain[B] = A;
               rank[A] += rank[B];
            }else{
                captain[A] = B;
               rank[B] += rank[A];
            }
         }
      }

      void printing(int n){
         for(int i=0;i<n;i++){
            cout<<"Node "<<i<<" captain of "<<captain[i]<<" & rank "<<rank[i]<<"\n";
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

   dsu.printing(n);
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