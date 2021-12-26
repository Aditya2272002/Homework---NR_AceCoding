#include<bits/stdc++.h>
using namespace std;

//🌟 Stack implementation Question STL

// Check for balanaced parenthesis in a String
bool checkBalanced(string data){
   stack<char> st;
   
   for(int i=0;i<data.size();i++){
      if(data[i]=='(' || data[i]=='[' || data[i]=='{'){
         st.push(data[i]);
      }else if((data[i]==')' && st.top()=='(') || (data[i]=='}' && st.top()=='{') || (data[i]==']' && st.top()=='[')){
         st.pop();
      }else{
        return false;
      }
   }
   if(st.size()!= 0){
     return false;
   }else{
      return true;
   }
}

//stock span
int spanStock(int arr[],int n){
   stack<int> st;
   st.push(arr[0]);
   int span = 1;
   cout<<span<<" ";
   for(int i=1;i<n;i++){
      if(arr[i] > st.top()){
         span++;
         st.pop();
      }else{
         st.push(arr[i]);
         cout<<span<<" ";
         span = 1;
      }
   }
}

int main()
{
   // cout<<checkBalanced("{{{()}}[]")<<" ";
   // cout<<checkBalanced(")(")<<" ";
   int arr[] = {15,13,12,14,16,8,6,4,10,30};
   int n = sizeof(arr)/sizeof(arr[0]);
   spanStock(arr,n);
   return 0;
}