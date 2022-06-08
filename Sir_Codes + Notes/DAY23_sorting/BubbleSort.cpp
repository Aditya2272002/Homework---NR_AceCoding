#include<bits/stdc++.h>
using namespace std;

/*
CONCEPT :-
 Swap adjacent elements if they are in wrong order till n-1 times.
*/

void printVector(vector<int>& v,int n){
   for(int i=0;i<n;i++){
      cout<<v[i]<<" ";
   }
   cout<<"\n";
}

void swap(int *a,int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}

void bubbleSort(vector<int>&v,int n){
   int i,j;
   for(i=0;i<n-1;i++){
      for(j=0;j<n-1-i;j++){
         if(v[j] > v[j+1]){
            swap(&v[j],&v[j+1]);
         }
      }
   }

}

int main()
{
   vector<int> v = {5,4,3,2,1};
   int n = v.size();
   bubbleSort(v,n);
   printVector(v,n);
   return 0;
}