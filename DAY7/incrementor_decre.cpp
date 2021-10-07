#include<bits/stdc++.h>
using namespace std;

// a++ -> use then increment
// ++a -> increment then use
// a-- -> use then decrement
// --a -> decrement then use

int main(){

   int a = 10;
   int b = a--;
   cout<<b<<" "<<a<<"\n";//10  9
   a = 10;
   int c = --a;
   cout<<c<<" "<<a<<"\n";//9  9
   return 0;
}