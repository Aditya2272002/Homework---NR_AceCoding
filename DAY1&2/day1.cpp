#include"day1.txt"

namespace Sample{
   int k = 1000;
}

int main()
{
   int a,b;
   
   cout<<Intro::s1<<"\n";
   cout<<"I am Sample created namespace"<<Sample::k<<"\n";
   cin>>a>>b;
   //Addition
   cout<<a+b<<"\n";
   //Substrcation
   cout<<a-b<<"\n";
   //Multiplication
   cout<<a*b<<"\n";
   //Divide
   cout<<a/b<<"\n";
   //Remainder Operator
   cout<<a%b;
   cout<<"Done";
   return 0;
}