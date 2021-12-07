#include<bits/stdc++.h>
using namespace std;

//Divide and Conqure
//It returns the index of partition
int partition(vector<int>& v,int l,int h){
   int pivot = v[l];
   int less = l;
   int more = h;

   while (less < more)
   {
      while(less < h && v[less] <= pivot){
         less++;
      }
       while(more > l && v[more] > pivot){
         more--;
      }
      if(less<more){
         int temp = v[less];
         v[less] = v[more];
         v[more] = temp;
      }
   }

   //Moving pivot to it's correct position
   int temp = v[l];
   v[l] = v[more];
   v[more] = temp;

   return more;
}

void quickSort(vector<int>& v,int l,int h){
   if(l>=h)
      return;
   int pivot_index = partition(v,l,h); 
   quickSort(v,l,pivot_index-1);
   quickSort(v,pivot_index+1,h);  
}

int main()
{
   vector<int> v = {435,342,4,36,1,435,47,42,1000,67,568,542};
   int n = v.size();
   quickSort(v,0,n-1);

   for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
   return 0;
}