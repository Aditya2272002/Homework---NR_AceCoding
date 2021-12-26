#include<bits/stdc++.h>
using namespace std;

int main()
{
   vector<int> v1 = {2,4,13,2765};
   // make_heap(v.begin(),v.end(),greater<int>());
   vector<int> v2 = {10,200,300};
   vector<int> v3(7);
   merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

   for(int x:v3){
      cout<<x<<" ";
   }

   return 0;
}