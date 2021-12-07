#include<bits/stdc++.h>
using namespace std;

int main()
{
   forward_list<int> l;
   l.push_front(1);
   l.push_front(2);
   l.assign({3,4,5,5,7,1,5});
   l.remove(5);

   for(auto i=l.begin();i!=l.end();i++){
      cout<<(*i)<<" ";
   }
   cout<<"\n";

   forward_list<int> l2;
   l2.assign(l.begin(),l.end());
   for(auto i=l2.begin();i!=l2.end();i++){
      cout<<(*i)<<" ";
   }
   cout<<"\n";
   return  0;
}