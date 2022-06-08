#include<bits/stdc++.h>
using namespace std;

int prefix(int i){
   int sum =0;
   
   return sum;
}

int main()
{
   int arr[] = {2,3,1,4,6,7};
   int n = 6;

   //Making prefixArray
   int prefix[n] = {0};
   prefix[0] = arr[0];
   for(int i=1;i<n;i++){
      prefix[i] = prefix[i-1] + arr[i];
   }

   //Sum between l to r
   int l,r;
   cin>>l>>r;
   // if l==0 then l-1 will give garbage so using conditional operator.
   cout<<prefix[r]-(l==0?0:prefix[l-1])<<" "; 
   cout<<"\n";

   //Array printing
   for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }
   cout<<"\n";

   //prefix Array printing
   for(int i=0;i<n;i++){
      cout<<prefix[i]<<" ";
   }
   return 0;
}