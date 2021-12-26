#include<bits/stdc++.h>
using namespace std;

void printing(map<int,int> m){
   for(pair<int,int>i:m){
      cout<<i.first<<" "<<i.second<<" ";
   }
   cout<<"\n";
}

int main()
{
   map<int,int> m;
   m.insert({10,200});
   m[20] = 400;
   printing(m);
   m.insert({10,900});
   printing(m);
   m[10] = 656;
   printing(m);
   return 0;
}