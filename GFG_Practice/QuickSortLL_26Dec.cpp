#include<bits/stdc++.h>
using namespace std;

forward_list<int> LL = {20,6,9,7,10};

forward_list<int>::iterator getTail(forward_list<int>::iterator head){

   forward_list<int>::iterator temp = head;
   forward_list<int>::iterator t = temp++;

   while(temp!=LL.end()){
      temp++;
      t++;
   }
   return t;
}

forward_list<int>::iterator partition(forward_list<int> l,forward_list<int>::iterator head,forward_list<int>::iterator tail){
  forward_list<int>::iterator pivot = head;
  forward_list<int>::iterator cur = head++;
  forward_list<int>::iterator prev = head;

 
}

void QuickSort(forward_list<int>& l,forward_list<int>::iterator head,forward_list<int>::iterator tail){
   if(head==LL.end() || tail==LL.end() || head==tail){
      return;
   }
   forward_list<int>::iterator pivot = partition(l,head,tail);
   QuickSort(l,head,pivot);
   QuickSort(l,pivot++,tail);
}

int main(){

  
   forward_list<int>::iterator head = LL.begin();
   forward_list<int>::iterator tail = getTail(head);

   // cout<<(*tail)<<" ";

   // for(int x:LL){
   //    cout<<x<<" ";
   // }cout<<"\n";

   // QuickSort(LL,5);

   // for(int x:LL){
   //    cout<<x<<" ";
   // }

}