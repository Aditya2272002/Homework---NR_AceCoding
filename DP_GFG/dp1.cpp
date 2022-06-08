#include<bits/stdc++.h>
using namespace std;

int mp[10000];
int fib(int n){
   if(n==0 || n==1){
      return mp[n] = n;
   }
   if(mp[n] != -1){
      return mp[n];
   }

   return mp[n] = fib(n-1) + fib(n-2);
}

int main()
{
   
   memset(mp,-1,sizeof(mp));

   int n;
   n = 5;
   fib(n);

   for(int x=0;x<n+1;x++){
      if(mp[x] != -1){
         cout<<mp[x]<<" "; 
      }
   }

   
   return 0;
}  