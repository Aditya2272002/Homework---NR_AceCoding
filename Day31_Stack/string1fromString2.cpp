#include<bits/stdc++.h>
using namespace std;

char* isFound(string &x,string &y){
   int arr[256] = {0};
   char* res1 = "yes";
   char* res2 = "no";
   for(int i=0;i<x.length();i++){
      arr[x[i]] ++;
   }

   for(int i=0;i<y.length();i++){
      if(arr[y[i]] == 0){
         return res1;
      }
      arr[y[i]]--;
   }
   return res2 ;
}

int main()
{
   string x = "zbk";
   string y = "zkb";
   cout<<isFound(x,y)<<"\n";

   return 0;
}