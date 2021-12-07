#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
   public:
   T data;
   Node<T>* next;

   Node(T data){
      this->data = data;
      this->next = NULL;
   }
};

template<typename T>
class CircularLL{
   private:
   Node<T>* head;
   int length;
   
   public:
   CircularLL(){
      head = NULL;
      length = 0;
   }

   void insertAtHead(T data){
      Node<T>* ptr = new Node<T>(data);
      if(head==NULL){
         head = ptr;
         ptr->next = head;
      }
      else{
         Node<T>* temp = head;
         while(temp->next!=head){
            temp = temp->next;
         }
         ptr->next = head;
         head = ptr;
         temp->next = head;
      }
      length++;
   }

   void insertAtLast(T data){
      Node<T>* ptr = new Node<T>(data);
      if(head==NULL){
         head = ptr;
         ptr->next = head;
      }
      else{
         Node<T>* temp = head;
         while(temp->next!=head){
            temp = temp->next;
         }
         temp->next = ptr;
         ptr->next = head;
      }
      length++;
   }

   void insertAtKth(T data, int position){
      Node<T>* ptr = new Node<T>(data);

      if(position==length+1){
         insertAtLast(data);
      }else if(position==1){
         insertAtHead(data);
      }else{
         Node<T>* temp = head;
         int i=1;
         while(i<(position-1)){
            temp=temp->next;
            i++;
         }
         ptr->next = temp->next;
         temp->next = ptr;
      }
      length++;
   }


   void displayCLL(){
      Node<T>* temp = head;
      while(temp->next!=head){
         cout<<temp->data<<"->";
         temp = temp->next;
      }
      cout<<temp->data<<" ";
      cout<<"\n";
   }

   void deleteHead(){
      if(head==NULL){
         cout<<"No data..."<<"\n";
      }else if(head->next==head){
         cout<<head->data<<"\n";
         delete(head);
         length--;
      }
      else{
         Node<T>* temp1 = head;
         Node<T>* temp2 = head->next;
         while(temp2->next!=head){
            temp2 = temp2->next;
         }
         head = head->next;
         temp2->next = head;
         cout<<temp1->data<<"\n";
         delete(temp1);
         length--;
      }
   }

   void deleteEnd(){

      if(head==NULL){
         cout<<"No data..."<<"\n";
      }
      else if(head->next == head){
         cout<<head->data<<"\n";
         delete(head);
         length--;
      }
      else{   
      Node<T>* temp = head;
      while(temp->next->next!=head){
         temp = temp->next;
      }
      Node<T>* del = temp->next;
      cout<<del->data<<"\n";
      temp->next = head;
      delete(del);
      length--;
      } 
   }

   void deleteKth(int position){
      if(head==NULL){
         cout<<"No data.."<<"\n";
      }
      else if(position==1){
         deleteHead();
      }
      else if(position==length){
         deleteEnd();
      }
      else{
          Node<T>* temp = head;
          int i=2;
          while(i<(position-1)){
             temp = temp->next;
             i++;
          }
          Node<T>* del = temp->next;
          cout<<del->data<<"\n";
          temp->next = del->next;
          delete(del);
          length--;
      }
   }

};

int main()
{
   CircularLL<int> CLL;
   CLL.insertAtHead(10);
   CLL.insertAtHead(30);
   CLL.insertAtHead(20);
   CLL.insertAtLast(50);
   CLL.displayCLL();
   CLL.deleteEnd();
   CLL.displayCLL();
   CLL.deleteKth(2);
   CLL.displayCLL();

   return 0;

}