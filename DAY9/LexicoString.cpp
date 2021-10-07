#include<bits/stdc++.h>
using namespace std;

string Go(string s){
   string ans = "";
   int i=0;
   int j=i+1;
   int n =s.length();
   while(j<n || i<n){
      if(s[j] >= s[i]){
         ans = ans + s[j];
      }else{
         ans = ans + s[i];
      }
      i = j + 1;
      j = i + 1;
   }
   if(n%2){
      ans = ans + s[i];
   }
   ans = ans + "\0";
   return ans;
}

int main(){
   string s;
   cin>>s;
   cout<<Go(s);
}