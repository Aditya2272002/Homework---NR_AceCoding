#include<bits/stdc++.h>
using namespace std;


int main()
{  
   int marks;
   cout<<"Enter marks : ";
   cin>>marks;
   if(marks>=90  && marks<=100){
      cout<<"A+";
   }
   else if(marks>=80  && marks<=89){
      cout<<"A";
   }
   else if(marks>=70  && marks<=79){
      cout<<"B+";
   }
   else if(marks>=60  && marks<=69){
      cout<<"B";
   }
   else if(marks>=50  && marks<=59){
      cout<<"C+";
   }
   else if(marks>=40  && marks<=49){
      cout<<"C";
   }
   else if(marks>=30 && marks<=39){
      cout<<"D";
   }else{
      cout<<"Fail";
   }
   
   return 0;
}