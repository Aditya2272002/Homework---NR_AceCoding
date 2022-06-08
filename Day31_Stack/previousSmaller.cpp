#include<bits/stdc++.h>
using namespace std;

void previousSmaller(int arr[],int ps[],int n){
   stack<int> st;
   for(int i=0;i<n;i++){
      while(!st.empty() && arr[st.top()] >= arr[i]){
         st.pop();
      }
      if(st.empty()){
         ps[i] = -1;
      }else{
         ps[i] = st.top();
      }
      st.push(i);
   }
}


int main()
{
   int arr[] = {6,2,5,4,5,1,6};
   int n = 7;
   int ps[n];

   previousSmaller(arr,ps,n);

   for(int i:ps){
      cout<<i<<" ";
   }

   return 0;
}