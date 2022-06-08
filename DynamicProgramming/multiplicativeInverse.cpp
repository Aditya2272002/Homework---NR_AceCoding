#include<bits/stdc++.h>
using namespace std;
    
int power1(long long int a,long long int b,long long int m){
   if(b==0){
      return 1;
   }
   if(b==1){
      return a%m;
   }
        
   long long int res = 1;
   long long int half = power1(a,b/2,m);
        
   res = (half%m * half%m+0ll) % m;
       
   if(b%2!=0){
      res = (res%m * a%m+0ll) % m;
   }
       
   return res;
}

int modInverse1(int a, int m)
{   
   return power1(a,m-2,m);
}

int main(){
   int a = 3, m = 1000000007;
   // int a =45 ,m= 88;
   // int a = 6 ,m = 34;
   if(__gcd(a,m)==1){
      cout<<modInverse1(a,m)<<"\n";
   }else{
      cout<<"-1"<<"\n";
   }
   
   return 0;
}