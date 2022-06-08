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

int go(int ind,int target,vector<int> &arr){
   if(ind==0){
      return {arr[ind] == target};
   }

   int notPicked = go(ind-1,target,arr);
   int picked = 1 + go(ind-1,target-arr[ind],arr);

   return min(picked,notPicked);
}

int main(){

   fun();

   int t;
   cin>>t;

   while(t--){
     int n,x;
     cin>>n>>x;
     vector<int> arr(n,0);
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }


   }
}
