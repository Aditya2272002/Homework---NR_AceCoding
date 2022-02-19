#include<bits./stdc++.h>
using namespace std;

//Time :- 2^N 
int go(int arr[],int start,int end){
   if(start >= end){
      return 0;
   }
   int ans = INT_MAX;
   for(int k=start;k<end;k++){
      int firstPart = go(arr,start,k);
      int secondPart = go(arr,k+1,end);
      ans = min(ans,firstPart + secondPart + arr[start] * arr[k+1] * arr[end+1]);
   }  
   return ans;
}

int main()
{
   int arr[] = {2,3,4,2,6};   //A[2][3]  B[3][4]  C[4][2]  D[2][6];
   int n = 5;
   int start = 0;
   int end = n-2;
   cout<<go(arr,start,end)<<"\n";
   return 0;
}