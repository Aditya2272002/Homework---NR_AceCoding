#include<bits/stdc++.h>
using namespace std;

void placeInSortedStack(stack<int> &s,int item){
    if(s.top() < item || s.empty()){
        s.push(item);
    }else{
        int temp = s.top();
        s.pop();
        placeInSortedStack(s,item);
        s.push(temp);
    }
}

void sortStack(stack<int> &s){
    if(!s.empty()){
        int temp = s.top();
        s.pop();
        sortStack(s);
        placeInSortedStack(s,temp);   
    }
}
void SortedStack(stack<int>& s)
{
   //Your code here
   sortStack(s);
}

int main(){
   stack<int> s;
   s.push(4);
   s.push(1);
   s.push(3);
   s.push(2);

   SortedStack(s);

   while(!s.empty()){
      cout<<s.top()<<" ";
      s.pop();
   }

   return 0;

}