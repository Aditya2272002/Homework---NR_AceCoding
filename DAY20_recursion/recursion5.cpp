#include<bits/stdc++.h>
using namespace std;

// 5.
// write down the recursive code to calculate the sum of series till n terms.
// (1)/(1!)+ (1+2)/2!+ (1+2+3)/3!+ (1+2+3+4)/4! +(1+2+3+4+5)/5! +......

int f(int n){
   int fact = 1;
   while(n>0){
      fact = fact*n;
      n--;
   }
   return fact;
}

float Sum(int i){
   return ((i*1.0)*(i+1.0))/2.0;
}

float S(int i){
   if(i==0) return 0;
   float sum = S(i-1) + (Sum(i))/(f(i));
   return sum;
}

float SS(int i,int& fact,float& s){
   if(i==0) return 0;
   float sum = SS(i-1,fact,s);
   fact = fact * i * 1.0;
   s = i*(i+1.0)/2.0;
   return sum*1.0 + s/(fact*1.0);
}

int main()
{
   cout<<S(2)<<" ";
   int p=1;
   float q=0;
   cout<<SS(2,p,q)<<" ";
   return 0;
}