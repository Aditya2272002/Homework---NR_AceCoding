#include<bits/stdc++.h>
using namespace std;

int main(){
   int a,b;
   cout<<"Enter two number : ";
   cin>>a>>b;
   char oper;
   cout<<"Enter +,-,/,* : ";
   cin>>oper;
   if(oper=='+'){
      cout<<a+b;
   }
   else if(oper=='-'){
      cout<<a-b;
   }
   else if(oper=='*'){
      cout<<a*b;
   }
   else if(oper=='/'){
      cout<<(float)a/(float)b;
   }else{
      cout<<"Wrong Operator";
   }

   return 0;
}