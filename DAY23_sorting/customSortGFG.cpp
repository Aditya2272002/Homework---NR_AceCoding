#include<bits/stdc++.h>
using namespace std;

bool sortbysecdesc(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second > b.second;
}

vector<pair<int,int>> sortBySecond(vector<pair<int,int>>& v)
{
   sort(v.begin(),v.end(),sortbysecdesc);
   return v;
}

int main()
{
   vector<pair<int,int>> v = {{6,8},{1,9}};
   sortBySecond(v);
   for(auto i :v){
      cout<<i.first<<" "<<i.second<<"\n";
   }
   return 0;
}