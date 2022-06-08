#include<bits/stdc++.h>
using namespace std;
#define N 100000

int nthPrime(int n)
{
	if(n <= 0)
		return 0;
   
   if(n==1){
      return 2;
   }

   vector<bool> isPrime(N,true);
	for(int i=2; i*i <= N; i++)
	{
		if(isPrime[i])
		{
			for(int j = 2*i; j <= N; j = j+i)
			{
				isPrime[j] = false;
			}
		}
	}

   for(int i = 2;i<N;i++){
      if(isPrime[i]){
			n--;
         if(n==0){
            return i;
         }
      }
   }
}


int main(){

   cout<<nthPrime(4)<<" ";
   cout<<nthPrime(5)<<" ";
   cout<<nthPrime(16)<<" ";
   cout<<nthPrime(1049)<<" ";
   return 0;
}