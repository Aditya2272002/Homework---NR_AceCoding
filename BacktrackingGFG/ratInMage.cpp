#include<bits/stdc++.h>
using namespace std;
#define n 4
vector<string> ans;

void printing(int sol[n][n]){
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         cout<<sol[i][j]<<" ";
      }
      cout<<"\n";
   }
}

bool isSafe(int mat[n][n],int i,int j){
   return (i<n && j<n && mat[i][j]==1);
}

void solMazeRec1(int mat[n][n],int sol[n][n],int i,int j,string path){
   if(i==n-1 && j==n-1 && mat[i][j]==1){
      ans.push_back(path);
      path = "";
      return;
   }

   if(isSafe(mat,i,j)){
      solMazeRec1(mat,sol,i+1,j,path+"D");
      solMazeRec1(mat,sol,i,j+1,path+"R");
   }
}


bool solMazeRec(int mat[n][n],int sol[n][n],int i,int j,string path){
   if(i==n-1 && j==n-1 && mat[i][j]==1){
      sol[i][j] = 1;
      ans.push_back(path);
      return true;
   }

   if(isSafe(mat,i,j)){
      sol[i][j] = 1;
      if(solMazeRec(mat,sol,i+1,j,path+"D")) return true;
      else if(solMazeRec(mat,sol,i,j+1,path+"R")) return true;
      sol[i][j] = 0;
   }
   return false;
}

bool solMaze(int mat[n][n],int sol[n][n],int i,int j){
   string path = "";
   if(solMazeRec(mat,sol,i,j,path)==false){
      return false;
   }
   printing(sol);
   return true;
}

int main()
{
   int mat[n][n] = { {1, 0, 0, 0},
                     {1, 1, 0, 1}, 
                     {1, 1, 0, 0},
                     {0, 1, 1, 1}};

   int sol[n][n] = {0};

   // cout<<"\n"<<solMaze(mat,sol,0,0)<<"\n";

   string path = "";
   solMazeRec1(mat,sol,0,0,path);

   for(string x:ans){
      cout<<x<<" ";
   }
   return 0;
}