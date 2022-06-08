// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

//Find sum of odd and even numbers from start to end.

ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start,ull end){
   for(ull i=start;i<=end;i++){
      if((i & 1) == 0){ 
         EvenSum += i;
      }
   }
}

void findOdd(ull start,ull end){
   for(ull i=start;i<=end;i++){
      if((i & 1) != 0){ 
         OddSum += i;
      }
   }
}

int main(){
   ull start = 0, end = 1900000000;

   std::thread t1(findOdd,start,end);
   std::thread t2(findEven,start,end);
    
   t1.join();
   t2.join();
  
//   findOdd(start,end);
//   findEven(start,end);

   cout<<"Odd Sum : "<<OddSum<<"/n";
   cout<<"Even Sum : "<<EvenSum<<"/n";

   return 0;
}
