#include<bits/stdc++.h>
using namespace std;

// 4.
// write down the recursive code to calculate the sum of series till n terms.
// 1!/2+ 2!/3+ 3!/4+ 4!/5 +5!/6 +.......
int f(int n){
   int fact = 1;
   while(n>0){
      fact = fact*n;
      n--;
   }
   return fact;
}

float S(int i){
   if(i==0) return 0;
   float sum = S(i-1) + ((f(i))*1.0)/((i+1)*1.0); 
   return sum; 
}

float SS(int i,int& fact){
   if(i==0) return 0;
   float sum = SS(i-1,fact);
   fact = fact * i * 1.0;
   return sum*1.0 + fact/(i+1.0);
}   

int main()
{
   int f = 1;
   cout<<S(2)<<" ";
   cout<<SS(2,f)<<" ";
   return 0;
}