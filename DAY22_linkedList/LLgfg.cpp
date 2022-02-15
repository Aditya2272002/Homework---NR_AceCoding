#include<bits/stdc++.h>
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

//Loop Detection :- Floyd Algo
void loopedLL(Node* head){
   int flag = 0;
   Node* slow = head;
   Node* fast = head;
   while(fast!=NULL && fast->next!=NULL){
      fast = fast->next->next;
      slow = slow->next;
      if(fast==slow){
         flag = 1;
         cout<<"Looped LL\n";
         break;
      }
   }
   if(flag==0){
      cout<<"No Looped LL\n";
   }
}

void displayLoopedLL(Node* head){
   vector<Node*> v;
   Node* temp = head;
   vector<Node*> :: iterator it;
   
   while(temp!=NULL){
      it = find(v.begin(),v.end(),temp);
      if(it==v.end()){
         v.push_back(temp);
      }else{
         cout<<temp->next->data<<"->";
         break;
      }
      cout<<temp->data<<"->";
      temp=temp->next;
   }
} 

//Removing Loop from LL
Node* removeLoopfromLL(Node* head){
   Node* slow = head;
   Node* fast = head;
   int flag = 0;
   while(fast!=NULL && fast->next!=NULL){
      fast = fast->next->next;
      slow = slow->next;
      if(fast==slow){
         flag = 1;
         break;
      }
   }
   if(flag==1){
      Node* t = slow;
      fast = head;
      while(t->next!=fast && fast->next!=t->next){
         fast=fast->next;
         t=t->next;
      }
      t->next = NULL;
   }
   else{ 
      cout<<"Linked List is Not LOOPED\n";
   }
   return head;
}

pair<bool,Node*> detectLoop(Node* head)
    {
       // your code here
       Node* slow = head;
       Node* fast = head;
       while(fast!=NULL && fast->next!=NULL){
          slow = slow->next;
          fast=fast->next->next;
          if(slow==fast){
             return {true,fast};
          }
       }
       return {false,NULL};
    }
    
//Function to remove a loop in the linked list.
void removeLoop(Node* head)
    {
        pair<bool,Node*> t =  detectLoop(head);
        Node* slow = t.second;
    
        if(t.first){
            cout<<"Slow and Fast meets at Node :- "<<t.second->data<<"\n";
           
            Node* t = slow;
            Node* fast = head;
            if(slow==head){
                while(t->next!=slow){
                    t=t->next;
                }
            }
            else{
                while(t->next!=fast && fast->next!=t->next){
                    t=t->next;
                    fast=fast->next;
                }
            }
            t->next = NULL;
        }else{
           return;
        }
    }

Node* add1ToLL(Node* root){
   Node* h1 = reverse(root);
   int carry = 0;
   int x = 0,y = 1;
   Node* t = h1;

   while(t!=NULL){
      x = t->data;
      t->data = (x+y)%10;
      carry = (x+y)/10;
      t = t->next;
      y = carry;
   }
   if(carry!=0){
      Node* temp = h1;
      while(temp->next!=NULL){
         temp=temp->next;
      }
      temp->next = new Node(carry);
   }
   Node* ans = reverse(h1);
   return ans;
}

Node* fun (){
      long long int add=0;
        int l=0;
        Node* temp=head;
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        
        
        Node* temp2=head;
        while(temp2!=NULL){
            l=l-1;
            add=add + (temp2->data* pow(10,l));
            temp2=temp2->next;
        }
        
        head->data=add+1;
        head->next=NULL;
        return head;
}

int main()
{
   head = new Node(9);
   head->next = new Node(9);
   head->next->next = new Node(9);
   head->next->next->next = NULL;
   
   cout<<"\n";
   disPlay(head);
   Node* ans = add1ToLL(head);
   cout<<"\n";
   disPlay(ans);
   cout<<"\n";

   return 0;
}