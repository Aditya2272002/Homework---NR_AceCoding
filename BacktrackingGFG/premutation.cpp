#include<bits/stdc++.h>
using namespace std;

bool isSafe(string str,int l,int i,int r){
   if(l!=0 && str[l-1] == 'A' && str[i] == 'B')
      return false;
   if(r==(l+1) && str[i]=='A' && str[l]=='B')
      return false;
   return true;
}

void go(string str,int l,int r){
   if(l==r){
      cout<<str<<"\n";
      return;
   }else{
      for(int i=l;i<=r;i++){
         if(isSafe(str,l,i,r)){
            swap(str[l],str[i]);
            go(str,l+1,r);
            swap(str[l],str[i]);
         }
      }
   }
}

void go1(string str,int i){
   if(i==str.length()-1){
      cout<<str<<" ";
      return ;
   }
   for(int j=i;j<str.length();j++){
      swap(str[i],str[j]);
      go1(str,i+1);
      swap(str[i],str[j]);
   }
}

int main()
{

   go("ABC",0,2);

   return 0;
}