#include<bits/stdc++.h>
using namespace std;

/*
CONCEPT:-
 Pick index of smallest element and swap it with first element.
*/

void printVector(vector<int> &v,int n){
   for(int i=0;i<n;i++){
      cout<<v[i]<<" ";
   }
   cout<<"\n";
}

void swaps(int *a,int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}

void selectionSort(vector<int>&v,int n){
   int i,j;
   for(i=0;i<n;i++){
      int indexSmall = i;
      for(j=i+1;j<n;j++){
         if(v[j] < v[indexSmall]){
            indexSmall = j;
         }
      }
      swaps(&v[indexSmall],&v[i]);
   }
}

int main()
{
   vector<int> v = {5100,90,80,70,333,3,1,20,11,3000,32,345};
   int n = v.size();
   selectionSort(v,n);
   printVector(v,n);
   return 0;
}