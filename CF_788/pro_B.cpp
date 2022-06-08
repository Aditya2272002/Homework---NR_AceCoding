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

      vector<vector<int>> ans(n,vector<int> (m,-1));
      int maxi = INT_MIN;


      for(int i=0;i<n;i++){
         int a,b;
         for(int j=0;j<m;j++){

            //up left
            int cur = 0;
            a = i-1;
            b = j-1;
            while(a>=0 && b>=0){
               cur += arr[a][b];
               a--;
               b--;
            }

            //up right
            a = i-1;
            b = j+1;
            while(a>=0 && b<m){
               cur += arr[a][b];
               a--;
               b++;
            }

            //down left
            a = i+1;
            b = j-1;
            while(a<n && b>=0){
               cur += arr[a][b];
               a++;
               b--;
            }

            //down right
            a = i+1;
            b = j+1;
            while(a<n && b<m){
               cur += arr[a][b];
               a++;
               b++;
            }

            maxi = max(maxi,cur + arr[i][j]);
         }
      }

      cout<<maxi<<"\n";
   }
}
