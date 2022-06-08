#include<bits/stdc++.h>
using namespace std;

/*
CONCEPT :- 
 We divide the array in Sorted and Un-Sorted parts ,we take i as points to 
 first element of sorted and j to last element of un-sorted then comapare
 both, if they are in wrong order then make (j+1)th element  = (j)th element
 and repeat.
*/

void printVector(vector<int>&v,int n){
   for(int i=0;i<n;i++){
      cout<<v[i]<<" ";
   }
   cout<<"\n";
}

void insertionSort(vector<int> &v,int n){
   int i,j;
   for(int i=1;i<n;i++){
      int temp = v[i];
      j = i-1;
      while(j>=0 && v[j] > temp){
         v[j+1] = v[j];
         j--;
      }
      v[j+1] = temp;
   }
}

int main()
{
   vector<int> v = {9090,34,564,677,22,56,2,156,1};
   int n = v.size();
   insertionSort(v,n);
   printVector(v,n);
   return 0;
}