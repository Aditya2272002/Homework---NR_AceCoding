#include<bits/stdc++.h>
using namespace std;


int main()
{
   int arr[] = {1,5,8,3,2,4};
   int n = 6;
   int m = ceil(log2(n));
   vector<vector<int>> dp(2*n,vector<int>(m,INT_MAX));

   for(int j=0;j<m;j++){
      for(int i=0;i<n;i++){
         if(j==0){
            dp[i][j] = arr[i];
         }else{
            dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
         }
      }
   }

   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cout<<dp[i][j]<<" ";
      }
      cout<<"\n";
   }
   cout<<"\n";

   int l,r;
   cin>>l>>r;
   int j = l,ans = INT_MAX;
   int x = r - l + 1;
   for(int i=m-1;i>=0;i--){
      if(x & (1<<i) !=0){
         ans = min(ans,dp[j][i]);
         j = j + (1<<i);
      }
   }

   cout<<ans<<" ";
   

   return 0;
}