#include<bits/stdc++.h>
using namespace std;

float Go(int n)
{
   float s = 0.0;
   int fact=1;
   for(int i=1;i<n+1;i++){
      fact = fact*i;
     
      s = s*1.0 + ()/(fact*1.0);
     
   }
   return s;
}

int main(){
   int n;
   cin>>n;
   cout<<Go(n);
   return 0;
}