#include<bits/stdc++.h>
using namespace std;

class Cmp{
   public:
      //function name must be "operator()"
      bool operator() (pair<int,int> a,pair<int,int> b){
         return a.first > b.first;
      }
};


bool cmp(pair<int,int>& a,pair<int,int>& b){
   return a.first < b.first;
}

int main()
{
   priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp> pq;
   vector<pair<int,int>> ans = {{40,5},{20,3},{30,6}};
   
   for(auto x:ans){
      pq.push(x);
   }

   while(!pq.empty()){
      cout<<"("<<pq.top().first<<","<<pq.top().second<<") ";
      pq.pop();
   }
   
   return 0;
}