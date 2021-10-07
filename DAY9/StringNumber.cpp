#include<bits/stdc++.h>
using namespace std;

string Go(string S){
   string ans = "";
   for(int i=0;i<S.length();i++){
      int a = int(S[i]) - 96;
      ans = ans + to_string(a);
   }
   return ans;
}
int main()
{
   string S;
   cin>>S;
   cout<<Go(S)<<"\n";
  return 0;
}