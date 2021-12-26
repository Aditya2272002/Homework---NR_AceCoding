#include<bits/stdc++.h>
using namespace std;

void print(queue<int> q){
   for(int i=0;i<=q.size();i++){
      cout<<q.front()<<" ";
      q.pop();
   }
   cout<<"\n";
}

void reversing(queue<int> &q,int k){
   stack<int> st;
   for(int i=0;i<k;i++){
      int data = q.front();
      q.pop();
      st.push(data);
   }

   while(!st.empty()){
      int data = st.top();
      q.push(data);
      st.pop();
   }

   for(int i=0;i< q.size() - k;i++){
      int data = q.front();
      q.pop();
      q.push(data);
   }
   
}


int main()
{
   queue<int> q;
   q.push(10);
   q.push(20);
   q.push(30);
   q.push(40); 
   q.push(50);
   int k = 3;
   reversing(q,k);

   for(int x = 0;x<q.size();x++){
      cout<<q.front()<<" ";
      q.pop();
   }
   return 0;
}