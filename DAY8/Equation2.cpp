#include<bits/stdc++.h>
using namespace std;

float Go(int n){
   float s = 0.0;
   for(int i=1;i<n+1;i++){
      s = s*1.0 + ((i+i+1)*1.0)/((i+2+i+3)*1.0);
   }
   return s;
}

int main()
{
   int n;
   cin>>n;
   cout<<Go(n);
}