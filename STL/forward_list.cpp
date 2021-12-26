#include<bits/stdc++.h>
using namespace std;

void removeFromFront(forward_list<int> &list)
{
    cout<<"removeFront\n";
    list.pop_front();
}

void removeAfter(forward_list<int> &list, int X)
{
   int mx = INT_MAX;
   auto it = list.begin();

   while(it!=list.end()){
      int key = (*it);
      int mx = min()
   }
   
}

void removeFromInRange(forward_list<int> &list, int start, int end)
{   
   forward_list<int>::iterator it1 = list.begin();
   forward_list<int>::iterator it2 = list.begin();
   int i=1,j=1;
   while(i<start){
      it1++;
      i++;
   }
    
   while(j<end){
      it2++;
      j++;
   }
    
   list.erase_after(it1,it2);
   cout<<"removeRange\n";
}

void removeAll(forward_list<int> &list)
{
   list.clear();
   cout<<"clearAll\n";
}

void printing(forward_list<int> l){
   for(int i:l){
      cout<<i<<" ";
   }
   cout<<"\n";
}


int main()
{
   forward_list<int> l = {4,15,18,20};
   int n = 4;
   printing(l);
   removeAfter(l,2);
   printing(l);

   return  0;
}