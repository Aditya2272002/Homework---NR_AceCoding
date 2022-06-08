#include<bits/stdc++.h>
using namespace std;

class MyHash{
   int *arr;
   int tableSize,size;

   MyHash(int tabelSize){
      this->tableSize = tableSize;
      size = 0;

      arr = new int[tableSize];
      for(int i=0;i<tableSize;i++){
         arr[i] = -1;
      }
   }

   void insert(int x){
      if(size==tableSize){
         return;
      }
      int i = x % tableSize;
      while(arr[i] != -1 && arr[i] != x){
         i = (i + 1) % tableSize;
      }

      if(arr[i]==x){
         return;
      }
      else{
         arr[i] = x;
         size++;
      }
   }



};


int main(){


   return 0;
}