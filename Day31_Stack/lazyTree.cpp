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

int sumQuery(vector<int>& tree,vector<int>& lazyTree,int lt,int rt,int l,int r,int index){
   if(l>rt || lt>r) return 0; // Disjoint

   if(lazyTree[index]!=0){
      tree[index] += lazyTree[index]*(rt-lt+1);
      lazyTree[2*index+1] += lazyTree[index];
      lazyTree[2*index+2] += lazyTree[index];
      lazyTree[index] = 0; 
   }

   if(lt>=l && rt<=r) return tree[index]; //Lies Inside
   //Overlapping
   int mid = (lt+rt)/2;
   return sumQuery(tree,lazyTree,lt,mid,l,r,2*index+1) + sumQuery(tree,lazyTree,mid+1,rt,l,r,2*index+2);
}

void updateRangeQuery(vector<int>& tree,vector<int>& lazyTree,int lt,int rt,int l,int r,int x,int index){
   if(l>rt || lt>r || lt>rt || l>r) return; // Disjoint

   if(lazyTree[index]!=0){
      tree[index] += lazyTree[index]*(rt-lt+1);
      lazyTree[2*index+1] += lazyTree[index];
      lazyTree[2*index+2] += lazyTree[index];
      lazyTree[index] = 0; 
   }

   //Lies Inside
   if(lt>=l && rt<=r) {
      tree[index] += x*(rt-lt+1); 
      lazyTree[2*index+1] += x;
      lazyTree[2*index+2] += x;
   }
   //Overlapping
   else{
      int mid = (lt+rt)/2;
      updateRangeQuery(tree,lazyTree,lt,mid,l,r,x,2*index+1);
      updateRangeQuery(tree,lazyTree,mid+1,rt,l,r,x,2*index+2);
      //Updating upper root of changed nodes
      tree[index] = tree[2*index+1] + tree[2*index+2] ;
   }
}

int main()
{
   int arr[] = {5,1,6,3,2,10,7,9};
   int n = 8;
   vector<int> tree(4*n,0),lazyTree(4*n,0);

   build(arr,0,n-1,tree,0);

   // 1.k=1 sum in range l to r 
   // 2.k=2 update every element in range l to r with value x

   int t;
   cin>>t;
   while(t--){
      int k; 
      int l,r;
      cin>>k>>l>>r;
      if(k==1){
         int ans = sumQuery(tree,lazyTree,0,n-1,l,r,0);
         cout<<"Sum between "<<l<<" to "<<r<<": "<<ans<<"\n";
      }
      else if(k==2){
         int x;
         cin>>x;
         updateRangeQuery(tree,lazyTree,0,n-1,l,r,x,0);
      }
   }

   cout<<"\n";

   return 0;
} 