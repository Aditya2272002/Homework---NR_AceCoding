#include<iostream>
using namespace std;

struct Node{
   int data;
   Node*next;
   
   //constructor
   Node(int data){
      this->data = data;
      next = NULL;
   }
};

Node* head=NULL;
int size=0;

void insertAtHead(int data){
   Node* temp = new Node(data);
   if(head==NULL){
      head = temp;
   }else{
      temp->next = head;
      head = temp;
   }
   size++;
}

void insertAtLast(int data){
   Node* temp = new Node(data);
   if(head == NULL){
      head = temp;
   }else{
      Node* t = head;
      while(t->next!=NULL){
         t=t->next;
      }
      t->next = temp;
   }
   size++;
}

void insertAtKth(int data,int k){
   
   if(k==1){
      insertAtHead(data);
   }else if(k==size){
      insertAtLast(data);
   }else{
      Node* temp = new Node(data);
      Node* t = head;
      int i=2;
      while(i<k){
         t=t->next;
         i++;
      }
      temp->next = t->next;
      t->next = temp;
   }
}

void deleteAtHead(){
   if(head==NULL){
      cout<<"LL empty\n";
   }else{
      Node* t = head;
      head = head->next;
      delete(t);
   }
}

void deleteAtLast(){
    if(head==NULL){
      cout<<"LL empty\n";
   }else if(size==1){
      deleteAtHead();
   }
   else{
       Node* t  = head;
       while(t->next->next!=NULL){
          t = t->next;
       }
       Node* t1 = t->next;
       t->next = NULL;
       delete(t1);
   }
}

void deleteAtKth(int k){
   if(head==NULL){
      cout<<"LL empty\n";
   }
   else if(k==1){
      deleteAtHead();
   }else if(k==size){
      deleteAtLast();
   }else{
      Node* temp = head;
      Node* t = head;
      int i=2;
      while(i<k){
         t=t->next;
         i++;
      }
      t->next = t->next->next;
   }
}

void disPlay(Node* head){
   Node* t = head;
   while(t!=NULL){
      cout<<t->data<<"->";
      t = t->next;     
   }
   cout<<"NULL\n";
}

void displayRecursive(Node* t){
   if(t==NULL){
      cout<<"NULL\n";
      return;
   }
   cout<<t->data<<"->";
   displayRecursive(t->next);
}

int searchKey(int key){
   Node* t = head;
   int k=0;
   while (t!=NULL){
      k++;
      if(t->data == key){
         return k;
      }
      t = t->next;
   }
   if(t==NULL){
      return -1;
   }
}

int searchKeyRecursive(Node* head,int key){
   static int k = 0;
   k++;
   if(head==NULL){
      return -1;
   }
   if(head->data == key){
      return k;
   }
   searchKeyRecursive(head->next,key);
}

void insertSortedElement(int key){
   Node* ptr = new Node(key);
   Node* t = head;
   if((t->data) > (ptr->data)){
      insertAtHead(key);
   }else{
      while((t->next!=NULL)&&((t->next->data) < (ptr->data))){
         t = t->next;
      }
      if(t->next==NULL){
         insertAtLast(key);
      }else{
         ptr->next = t->next;
         t->next = ptr;
      }
   }
}

//Naive Solution i.e having two traversal
int middleOfLL(Node* head){
   if(head==NULL){
      return NULL||0;
   }
   int n=0;
   Node* t = head;
   while(t!=NULL){
      n++;
      t=t->next;
   }
   if(n==1){
      return head->data;
   }
   //even
   if(n%2==0){
      int k = n/2 + 1;
      Node* ans =head;
      while(k>1){
         ans=ans->next;
         k--;
      }
      return ans->data;
   }//odd
   else{
      int k = n/2 + 1;
      Node* ans =head;
      while(k>1){
         ans=ans->next;
         k--;
      }
      return ans->data;
   }
}

//One traversal only :-SLOW FAST POINTER
int middleOneLL(Node* head){
   if(head==NULL){
      return NULL||0;
   }
   Node* slow = head;
   Node* fast = head;
   while((fast!=NULL) && (fast->next!= NULL)){
      slow = slow->next;
      fast = fast->next->next;
   }
   return slow->data;
}

//Method 1️⃣ :- Using length of LL
int NthNodeFromEnd(Node* head,int n){
   int size=0;
   if(head==NULL){
      return NULL||0;
   }
   Node* t = head;
   while(t!=NULL){
      t=t->next;
      size++;
   }
   if(n>size){
      return 0;
   }
   int k = size - n;
   Node* ptr = head;
   while(k>0){
      ptr=ptr->next;
      k--;
   }
   return ptr->data;
}

//Method 2️⃣ :- Using two pointer,one pointer ahead by k from first
int NthFromEndTwoPointer(Node* head,int k){
   if(head==NULL){
      return 0;
   }
   Node* first = head;
   Node* second = head;
   for(int i=0;i<k;i++){
      if(second!=NULL){
         second = second->next;
      }else{
         return 0;
      }
   }
   if(second==NULL){
      return 0;
   }
   while(second!=NULL){
      second = second->next;
      first = first->next;
   }
   return first->data;
}

Node* reverse(Node* head){
   Node *cur = head;
   Node *curNext = NULL;
   Node *prev = NULL;        
   while(cur !=NULL){
      curNext = cur->next;
      cur->next = prev;
      prev = cur;
      cur = curNext;
   }       
   head = prev;
   return head;
}

void removeDublicateSortedLL(Node* head){
   Node* cur = head;
   while(cur->next!=NULL && cur!=NULL){
      if(cur->data!=cur->next->data){
         cur=cur->next;
      }else{
         cur->next=cur->next->next;
      }
   }
}

//🌟Important Recursion :-
Node* reverseInKthGroup(Node* head,int k){
   if(head==NULL){
      return NULL;
   }

   Node *cur = head;
   Node *curNext = NULL;
   Node *prev = NULL;  
   int count = k;      
   while(count-- && cur !=NULL){
      curNext = cur->next;
      cur->next = prev;
      prev = cur;
      cur = curNext;
   }       
   head->next = reverseInKthGroup(cur,k);
   head = prev;
   return head;
}

int main()
{
   insertAtLast(100);
   insertAtLast(200);
   insertAtLast(300);
   insertAtLast(400);
   insertAtLast(500);
   insertAtLast(600);
     
   disPlay(head);  
   Node* h = reverseInKthGroup(head,2);
   disPlay(h);
   
   return 0;
}