#include<bits/stdc++.h>
using namespace std;

void nextSmaller(int arr[],int ns[],int n){
   stack<int> st;
   for(int i=n-1;i>=0;i--){
      while(!st.empty() && arr[st.top()] >= arr[i]){
         st.pop();
      }
      if(st.empty()){
         ns[i] = n;
      }else{
         ns[i] = st.top();
      }
      st.push(i);
   }
}

int main()
{
   int arr[] = {6,2,5,4,5,1,6};
   int n = 7;
   int ns[n];

   nextSmaller(arr,ns,n);

   for(int i:ns){
      cout<<i<<" ";
   }

   return 0;
}