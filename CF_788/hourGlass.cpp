#include<bits/stdc++.h>
using namespace std;

void fun(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("i.txt","r",stdin);
   freopen("o.txt","w",stdout);
   #endif
}

int go(vector<vector<int>> &arr,int n,int m){
   if(n<3 || m<3) return -1;

   int ans = INT_MIN;
   for(int i=0;i<n-2;i++){
      for(int j=0;j<m-2;j++){
         int t =  arr[i][j] + arr[i][j+1] + 
                  arr[i][j+2] + arr[i+1][j+1] + 
                  arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

         ans = max(t,ans); 
      }
   }
   return ans;
}

int main(){
   fun();
   int t;
   cin>>t;
   while(t--){
      int n,m;
      cin>>n>>m;
      vector<vector<int>> arr(n,vector<int> (m,0));

      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            cin>>arr[i][j];
         }
      }

      cout<<go(arr,n,m)<<"\n";
   }
   
   return 0;
}