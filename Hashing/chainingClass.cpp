#include<bits/stdc++.h>
using namespace std;

class MyHash{
   public:
      int tableSize;
      list<int> *table;

      MyHash(int tableSize){
         this->tableSize = tableSize;
         table = new list<int>[tableSize];
      }

      void insert(int x){
         int i = x % tableSize;
         table[i].push_back(x);
      }

      void deleting(int x){
         int i = x % tableSize;
         table[i].remove(x);
      }

      bool searching(int x){
         int i = x % tableSize;
         for(int e:table[i]){
            if(e==x){
               return true;
            }
         }
         return false;
      }

      void display(){
         for(int i=0;i<tableSize;i++){
            for(int e:table[i]){
               cout<<e<<" ";
            }
         }
      }

};

int main(){
   MyHash myhash(7);
   myhash.insert(50);
   myhash.insert(21);
   myhash.insert(58);
   myhash.insert(49);
   myhash.insert(28);
   myhash.display();
   cout<<"\n";
   myhash.deleting(58);
   myhash.deleting(28);
   myhash.display();
   cout<<"\n"<<myhash.searching(49);

   return 0;
}