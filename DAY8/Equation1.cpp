#include<bits/stdc++.h>
using namespace std;

float Go(int n){
   float s = 0.0;
   int fact1=1;
   int fact2=1;
   for(int i=1;i<n+1;i++){
      fact1 = fact1 * i;
      fact2 = fact1 * (i+1);
      s = s*1.0 + (i*(i+2)*1.0)/((fact1*1.0) + (fact2*1.0)); 
   } 
   return s;
}

int main()
{
   int n;
   cin>>n;
   cout<<Go(n);
}