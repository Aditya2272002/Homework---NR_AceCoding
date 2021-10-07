// write a function to take three values (int ,int,float) return in float :- a +b*c

#include<bits/stdc++.h>
using namespace std;

float fun(int a,int b,float c){
   return (float)(a+b*c);
}

int main(){

  cout<<fun(3,2,2.15);
}