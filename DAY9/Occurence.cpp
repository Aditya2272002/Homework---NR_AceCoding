#include<bits/stdc++.h>
using namespace std;


int main(){

   int n,x;
   int arr[n];
   cin>>n>>x;
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
   int c=0;
   for(int i=0;i<n;i++){
      if(arr[i]==x)
         c++;
   }
   cout<<c<<"\n";
   return 0;
}