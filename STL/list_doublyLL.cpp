#include<bits/stdc++.h>
using namespace std;

//Johesp Problem using list (Doubly Linked List)

int main()
{

   list<int> l = {0,1,2,3,4,5,6};
   int k = 3;
   int count = l.size();
   list<int>::iterator cur = l.begin();

   while(count!=1){
      int t = k-1;
      while(t>0){
         cur++;
         if(cur==l.end()){
            cur = l.begin();
         }
         t--;
      }
      cur = l.erase(cur);
      if(cur==l.end()){
         cur = l.begin();
      }
      count--;
   }

   for(auto x:l){
      cout<<x<<" ";
   }


   return 0;
}