#include<bits/stdc++.h>
using namespace std;

//1️⃣. Prime number -> number divisible from 1 and itself.
//2️⃣. Prime Factors
//3️⃣.  Eucludian Algo for finding GCD
//4️⃣. 

//1️⃣O(root n)
void isPrime(int n){
   int flag=0;
   for(int i=2;i*i<=n;i++){
      if(n%i==0){
         flag=1;
         cout<<"Not Prime"<<"\n";
         break;
      }
   }
   if(flag!=1){
      cout<<"Prime"<<"\n";
   }
}

//2️⃣
void primeFactors(int n){
   for(int i=2;i*i<=n;i++){
      while(n%i==0){
         cout<<i<<" ";
         n = n/i;
      }
   }
   if(n>1){
      cout<<n;
   }
}

int gcd(int a,int b){
   if(b>a){
      swap(a,b);
   }
   if(b==0){
      return a;
   }
   return gcd(a%b,b);
}


int main()
{
   // isPrime(30);
   // primeFactors(34);
   cout<<gcd(16,3);
   return 0;
}
