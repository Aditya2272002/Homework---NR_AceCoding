#include<bits/stdc++.h>
using namespace std;

// Time Complexity :-  (n*(2^n))  => because we have '2^n' subsets and printing each subset in 'n', So (n*(2^n)) is TC
// Space Complexity :- 

  // 📔 This is a function which gives the subset till i index in vector v

set<vector<int>> s;
void subSet(vector<int>& v,int i,vector<vector<int>>& allSubset,vector<int> currentSet,int n){

   if(i==n){
      allSubset.push_back(currentSet);
      sort(currentSet.begin(),currentSet.end());
      s.insert(currentSet);
      return;
   }
   //if current element is not selected
   subSet(v,i-1,allSubset,currentSet,n);

   //if current element is selected then push it
   currentSet.push_back(v[i]);
   subSet(v,i-1,allSubset,currentSet,n);

   //removing all currentSet's old element i.e referesh currentSet
   currentSet.pop_back();

}

void ssubSet(int arr[],int n,vector<int> ans){

   if(n<0){
      for(int i:ans){
         cout<<i<<",";
      }  
      cout<<"\n"; 
      return;
   }
   ssubSet(arr,n-1,ans);

   ans.push_back(arr[n]);
   ssubSet(arr,n-1,ans);
   ans.pop_back();
   
}

int main()
{
   // vector<int> v = {1,2,3,4};
   // int n = 4;
   // vector<vector<int>> allSubset;
   // vector<int> currentSet;

   // subSet(v,n-1,allSubset,currentSet);

   // for(vector<int> current:allSubset){
   //    for(int i:current){
   //       cout<<i<<" ";
   //    }
   //    cout<<"\n";
   // }

   int arr[] = {1,2,3};
   int n = sizeof(arr)/sizeof(arr[0]);
   vector<int> ans;
   ssubSet(arr,n-1,ans);

   return 0;
}