#include<bits/stdc++.h>
using namespace std;

stack<int> rs;
stack<int> ax;

int getMini(){
   cout<<ax.top()<<"\n";
}

void pushing(int x){
   if(rs.size()==0 && ax.size()==0){
      rs.push(x);
      ax.push(x);
   }
   else if(ax.top() >= x){
      ax.push(x);
   }else
      rs.push(x);
}

void poping(){
   if(rs.size()!=0){
      if(rs.top() == ax.top()){
         ax.pop();
      }
      rs.pop();
   }
}

int main()
{
   
   pushing(10);
   pushing(9);
   pushing(23);
   pushing(42);
  
   
   pushing(30);
  
   pushing(90);
   
   while(!rs.empty()){
      cout<<rs.top()<<" ";
      rs.pop();
   }
   cout<<"\n";
   while(!ax.empty()){
      cout<<ax.top()<<" ";
      ax.pop();
   }
  



   return 0;
}