#include<bits/stdc++.h>
using namespace std;

//Time :- 2^N ,as it calls repeteadly for previously calculated items.
int lcs(string s1,string s2,int i,int j){
   if(i<0 || j<0){
      return 0;
   }
   if(s1[i]==s2[j]){
      return 1 + lcs(s1,s2,i-1,j-1); 
   }else{
      return max(lcs(s1,s2,i-1,j),lcs(s1,s2,i,j-1));
   }
}

int lcs2(){
   
}

int main(){

   string s1 = "AGGTAB";
   string s2 = "GXTXAYB";

   int i = s1.length() - 1;
   int j = s2.length() - 1;
   cout<<lcs(s1,s2,i,j)<<"\n";

   return 0;
}