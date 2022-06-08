#include<bits/stdc++.h>
using namespace std;

void insertBottom(stack<int>& st,int x){
   if(st.size()==0){
      st.push(x);
      return;
   }
   int t = st.top();
   st.pop();
   insertBottom(st,x);
   st.push(t);
}

void reverseStack(stack<int>& st){
   if(st.size()==0){
      return;
   }
   int t = st.top();
   st.pop();
   reverseStack(st);
   insertBottom(st,t);
}

int main()
{
   stack<int> st;
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);
   // cout<<st.size()<<" ";
   //insertBottom(st,10);
   reverseStack(st);
   while(!st.empty()){
      cout<<st.top()<<" ";
      st.pop();
   }

   return 0;
}