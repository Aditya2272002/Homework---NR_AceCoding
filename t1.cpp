#include<bits/stdc++.h>
using namespace std;

void fun(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("input_test.txt","r",stdin);
   freopen("output_test.txt","w",stdout);
   #endif
   
}


int main(){

  set<int> s;
  s.insert(10);
  s.insert(30);
  s.insert(40);

 for(int i:s){
    cout<<i<<" ";
 }
  s.erase(30);


for(int i:s){
    cout<<i<<" ";
 }
   return 0;
}




