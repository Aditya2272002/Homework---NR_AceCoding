#include<bits/stdc++.h>
using namespace std;

set<int> s;

void inserting(int data){
   s.insert(data);
}

bool searching(int key){
   set<int> ::iterator it = s.find(key);
   if(it!=s.end()){
      return true;
   }else{
      return false;
   } 
}

void deleting(int data){
   bool ans = searching(data);
   if(ans!=false){
      auto it = s.find(data);
      s.erase(it);
   }  
}

int getFloor(int x){
   auto it = s.lower_bound(x);
   if((*it)==x)
      return (*it);
   it--;
   return (*it);
}

int getCeiling(int x){
   auto it = s.lower_bound(x);
   return (*it);
}



int main()
{
   // inserting(10);
   // inserting(20);
   // inserting(5);
   // inserting(25);

   // cout<<getFloor(6)<<" ";
   // cout<<getFloor(5)<<" ";
   // cout<<getCeiling(6)<<" ";

   set<int> s;
   s.insert(10);
   s.insert(20);
   s.insert(30);
   
   s.

}