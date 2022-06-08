#include<bits/stdc++.h>
using namespace std;

//Here "index" variable denotes that the answer of sum of range from l to r stored at index "index"
int build(int arr[],int l,int h,vector<int>& tree,int index){
   if(l>h){
      return 0;
   }
   //Leaf Node building
   if(l==h){
      return tree[index] = arr[l];
   }
   //Root Node building
   int mid = (l+h)/2;
   return tree[index] = build(arr,l,mid,tree,2*index+1) + build(arr,mid+1,h,tree,2*index+2);
}

int sumQuery(vector<int>& tree,int lt,int rt,int l,int r,int index){
   if(l>rt || lt>r) return 0; // Disjoint
   if(lt>=l && rt<=r) return tree[index]; //Lies Inside
   
   //Overlapping
   int mid = (lt+rt)/2;
   return sumQuery(tree,lt,mid,l,r,2*index+1) + sumQuery(tree,mid+1,rt,l,r,2*index+2);
}

int maxQuery(vector<int>& tree,int lt,int rt,int l,int r,int index){
   if(l>rt || lt>r) return 0; // Disjoint
   if(lt>=l && rt<=r) return tree[index]; //Lies Inside
   
   //Overlapping
   int mid = (lt+rt)/2;
   return max(sumQuery(tree,lt,mid,l,r,2*index+1) ,sumQuery(tree,mid+1,rt,l,r,2*index+2));
}

void updatePointQuery(vector<int>& tree,int l,int h,int i,int x,int index){
   if(l>h){
      return;
   }
   if(l==h){
      tree[index] = x;
      return;
   }
   int mid = (l+h)/2;
   //Go left tree
   if(i <= mid){
      updatePointQuery(tree,l,mid,i,x,2*index+1);
   }
   //Go right tree
   else if(i > mid){
      updatePointQuery(tree,mid+1,h,i,x,2*index+2);
   }
   //left or right updated now update root
   tree[index] = tree[2*index + 1] + tree[2*index+2];
}


int main()
{
   int arr[] = {5,1,6,3,2,10,7,9};
   int n = 8;
   vector<int> tree(4*n,0);

   build(arr,0,n-1,tree,0);
   cout<<maxQuery(tree,0,n-1,0,3,0);

   // 1.k=1 sum in range l to r 
   // 2.k=2 update at l with value r

/*
   int t;
   cin>>t;
   while(t--){
      int k; 
      int l,r;
      cin>>k>>l>>r;
      if(k==1){
         int ans = sumQuery(tree,0,n-1,l,r,0);
         cout<<"Sum between "<<l<<" to "<<r<<": "<<ans<<"\n";
      }
      else if(k==2){
         updatePointQuery(tree,0,n-1,l,r,0);
      }
   }
   */
   

   cout<<"\n";

   return 0;
}