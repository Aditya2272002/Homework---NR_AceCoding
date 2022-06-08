#include<bits/stdc++.h>
using namespace std;
#define N 4
int board[N][N] = {0};

void printing(){
   for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
         cout<<board[i][j]<<" ";
      }
      cout<<"\n";
   }
   cout<<"\n\n";
}

bool isSafe(int row,int col){
   //Left Row checking
   for(int i=0;i<col;i++){
      if(board[row][i]==1){
         return false;
      }
   }

   //Checking left upper Diagonal 
   int i = row;
   int j = col;
   while(i>=0 && j>=0){
      if(board[i][j]==1){
         return false;
      }
      i--;
      j--;
   }

   //Checking lower left Diagonal
   int p = row,q = col;
   while(p<=N && q>=0){
      if(board[p][q]==1){
         return false;
      }
      p++;
      q--;
   }
   return true;
}

void solveRec(int col){
   if(col==N) {
      printing();
      return;
   }

   for(int i=0;i<N;i++){
      if(isSafe(i,col)){
         board[i][col] = 1;
         solveRec(col+1);
         board[i][col] = 0;
      }
   }
   return;
}

int main(){

   solveRec(0);

   return 0;
}