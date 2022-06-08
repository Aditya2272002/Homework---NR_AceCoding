#include<bits/stdc++.h>
using namespace std;

int countDisarrangements(int n){
   vector<int> dp(n+1,-1);
   dp[1] = 0;
   dp[2] = 1; 

   for(int i=3;i<=n;i++)
    dp[i] = (i-1) * (dp[i-1] + dp[i-2]);

   return dp[n];
}

int countDisarrangements2(int n){
   if(n==1 || n==2) return n-1;
   int a = 0;
   int b = 1; 
   int c;

   for(int i=3;i<=n;i++){
      c = (i-1) * (a + b);
      a = b;
      b = c;
   }

   return c;
}


int main()
{
   int n = 4;
   cout<<countDisarrangements(n)<<" ";
   cout<<countDisarrangements2(n);

   return 0;
}