#include<bits/stdc++.h>
using namespace std;

string convert(string &s){
   for(int i=0;i<s.size();++i){
      if(s[i]>='a' && s[i]<='z') 
         s[i] = 'A'+s[i]-'a';
      else if(s[i]>='A' && s[i]<='Z' ) 
         s[i] = 'a'+s[i]-'A';
   }
   return s;
}

int main(){
   // char s[] = {'s','i','m','r','a','n','\0'};
   // cout<<*(s+2)<<" "<<(s+2);
   string s = "rAveEt@726abBCd";
   cout<<convert(s);

   return 0;
}