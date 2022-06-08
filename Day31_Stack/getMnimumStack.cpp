#include<bits/stdc++.h>
using namespace std;
int ans = INT_MAX;

void getMinimum(stack<int>& st){
   if(st.empty()) return;

   int t = st.top();
   ans = min(ans,t);
   st.pop();
   getMinimum(st);
   st.push(t);   
}

int main()
{
   stack<int> st;
   st.push(16);
   st.push(15);
   st.push(29);
   st.push(19);
   st.push(18);

   getMinimum(st);
   cout<<ans<<"\n";

   return 0;
}