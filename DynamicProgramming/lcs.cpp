#include<bits/stdc++.h>
using namespace std;

void printing(vector<vector<int>>& dp){
   for(auto it = dp.begin();it!=dp.end();it++){
      vector<int> v = (*it);
      for(int i:v){
         cout<<i<<" ";
      }
      cout<<"\n";
   }
}

//Time :- 2^N ,as it calls repeteadly for previously calculated items.
int lcs(string s1,string s2,int i,int j){
   if(i<0 || j<0){
      return 0;
   }
   if(s1[i]==s2[j]){
      return 1 + lcs(s1,s2,i-1,j-1); 
   }else{
      return max(lcs(s1,s2,i-1,j),lcs(s1,s2,i,j-1));
   }
}

//Top Down Approach 
int lcs2(string s1,string s2,int i,int j,vector<vector<int>>& dp){
    if(i<0 || j<0){
      return 0;
   }

   if(dp[i][j] != -1){   // If value is already calculated
      return dp[i][j];   // then directly return it.
   }

   if(s1[i]==s2[j]){
      return dp[i][j] = 1 + lcs2(s1,s2,i-1,j-1,dp); 
   }else{
      return dp[i][j] = max(lcs2(s1,s2,i-1,j,dp),lcs2(s1,s2,i,j-1,dp));
   }
}

//Bottom Up Approach
int lcs3(string s1,string s2){
   
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>> dp(n+1,vector<int> (m+1,0));
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(s1[i]==s2[j]){
            dp[i][j] = 1 + dp[i-1][j-1]; 
         }else{
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
         }
         cout<<dp[i][j]<<" ";
      }
      cout<<"\n";
   }
   
   return dp[n][m];
}

int main(){

   string s1 = "AGGTAB";
   string s2 = "GXTXAYB";

   int i = s1.length() - 1;
   int j = s2.length() - 1;
   
   //Normal
   // cout<<lcs(s1,s2,i,j)<<"\n";


   //Top Down Approach
   // int n = i + 1;
   // int m = j + 1;
   // vector<vector<int>> dp(n,vector<int> (m,-1));
   // cout<<lcs2(s1,s2,i,j,dp)<<"\n";

   //Bottom Up Approach
   cout<<"\n"<<lcs3(s1,s2)<<"\n";

   

   return 0;
}