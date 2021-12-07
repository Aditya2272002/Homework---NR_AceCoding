//📑 Aditya Solution
#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node{
   public:
   T data;
   Node* next;
   Node* prev;
   
   Node(T data){
      this->data=data;
      this->next = NULL;
      this->prev = NULL;
   }
};

template<class T>
class DoublyLL{
   public:
   Node<T>* head;
   Node<T>* middle;
   Node<T>* top;
   Node<T>* curNode;
   int count;

  
   DoublyLL(){
      head = NULL;
      middle=head;
      count=0;
      top = head;
      curNode = head;
   }

   void push(T data){
      Node<T>* ptr = new Node<T>(data);
      if(head==NULL){
         head=ptr;
         top=ptr;
         middle=ptr;
         curNode=ptr;
      }else{
         curNode->next = ptr;
         ptr->prev = curNode;
         curNode=curNode->next;
      }
      count++;
      if(count%2!=0 && count!=1){
         middle=middle->next;
      }
   }

   void pop(){
      Node<T>* temp = curNode;
      // cout<<"Count = "<<count<<"\n";
      if(count==0){
         cout<<"No data to delete"<<"\n";
      }
      else if(count==1){
         delete(temp);
      }
      else if(count%2==0){
         curNode=curNode->prev;
         curNode->next=NULL;
         delete(temp);
      }
      else{
         middle=middle->prev;
         curNode=curNode->prev;
         curNode->next=NULL;
         delete(temp);
      }
      count--; 
   }

   void getTop(){
      if(count==0){
         cout<<"No data"<<"\n";
      }else
      cout<<"Top = "<<top->data<<"\n";
   }

   void getMiddle(){
      if(count==0){
         cout<<"No data"<<"\n";
      }else{
      cout<<"Middle = "<<middle->data<<"\n";
      }
   }

   void deleteMiddle(){
      Node<T>* d = middle;

      if(count==0){
         cout<<"No data to delete"<<"\n";
      }
      else if(count==1){
         delete(d);
      }
      else if(count%2==0){
         if(middle==head){
            middle=middle->next;
            head = middle;
            head->prev=NULL;
            d->next=NULL;
            delete(d);
         }
         else{
            middle=middle->next;
            middle->prev = d->prev;
            d->prev->next = d->next;
            delete(d);
         }
      }
      else{
         middle=middle->prev;
         middle->next = d->next;
         d->next->prev = middle;
         delete(d);
      }
      count--;
   }

   void display(){
        Node<T>* temp=head;
        while(temp != NULL){
            cout<<temp->data<<" , ";
            temp=temp->next;
        }
        cout<<"\n";
    }
};

int main()
{
   DoublyLL<int> d;
   d.push(100);
   d.push(200);
   d.push(300);
   d.push(400);
   d.getMiddle();
   
   d.deleteMiddle();
   d.getMiddle();
   d.pop();
   d.getMiddle();

   return 0;
}