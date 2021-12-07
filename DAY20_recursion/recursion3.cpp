#include<bits/stdc++.h>
using namespace std;
// 3.
// write down the recursive code to calculate the sum of series till n terms.
// 1/2+ 2/3+ 3/4+ 4/5 +5/6 +.......

//General :- (i)/(i+1)

float S(int i){
   if(i==0)return 0;
   float sum = ((i)*1.0)/((i+1)*1.0) + S(i-1);
   return sum;
}

int main(){
   int terms = 4;
   cout<<S(terms)<<" ";
   return 0;
}