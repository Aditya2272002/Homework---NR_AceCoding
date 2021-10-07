#include<bits/stdc++.h>
using namespace std;

float add(float a, float b){
   return a+b;
}

float substract(float a, float b){
   return a-b;
}

float multiply(float a, float b){
   return a*b;
}

float divide(float a, float b){
   return a/b;
}

int main(){
   while(true){
      char choice;
      float a,b;
      cout<<"Enter numbers:-  " ;
      cin>>a>>b;
      cout<<"Enter operation to perform (+,-,/,*) and press 'e' to exit :- ";
      cin>>choice; 
      switch(choice){
         case '+':cout<<add(a,b)<<"\n";
                  break;
         case '-':cout<<substract(a,b)<<"\n";
                  break;
         case '*':cout<<multiply(a,b)<<"\n";
                  break;
         case '/':cout<<divide(a,b)<<"\n";
                  break;
         case 'e':exit(1);
                  break;
         default:cout<<"Invalid operator ! ";
      }
   }
   return 0;
}