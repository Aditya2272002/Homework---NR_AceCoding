#include <bits/stdc++.h>
using namespace std;

int build(int arr[],vector<int>& tree,int l,int h,int index){
   if(l > h){
      return 0;
   }
   if(l==h){
      return tree[index] = arr[l];
   }

   int mid = (l+h)/2;
   return tree[index] = build(arr,tree,l,mid,2*index+1) + build(arr,tree,mid+1,h,2*index+2);
}

int main()
{
   int arr[] = {5,1,6,3,2,10,7};
   int n = 7;

   vector<int> tree(4*n,0);


   build(arr,tree,0,n-1,0);

   return 0;
}