#include<bits/stdc++.h>
using namespace std;

// Important Concept use of STL concepts.
/*
https://practice.geeksforgeeks.org/tracks/cip-non-mutating-stl-algorithms/?batchId=238&tab=1
*/

int median(int arr[3][5],int r,int c){
   int minA = arr[0][0],maxA = arr[0][c-1];
   for(int i=0;i<r;i++){
      minA = min(minA, arr[i][0]);
      maxA = max(maxA,arr[i][c-1]);
   }
   int medianPostion = (r*c+1)/2;
   int midPos = 0;
  
   while(minA<maxA){
      int mid = (minA + maxA)/2;
      midPos = 0;
      for(int i=0;i<r;i++){
         midPos += upper_bound(arr[i],arr[i]+c,mid) - arr[i];
      }
      if(midPos < medianPostion)
         minA = mid + 1;
      else
         maxA = mid;
   }
   return minA;
}


int main(){

   int arr[3][5] = {{5,10,20,30,40},
                    {1,2,3,4,6},
                    {11,13,15,17,19}
                   };

   cout<<median(arr,3,5);
   return 0;
}