#include<bits/stdc++.h>
using namespace std;

struct Node{
   int data;
   Node* next;
   Node* prev;

   Node(int data){
      this->data = data;
      this->next = NULL;
      this->prev = NULL;
   }
};

Node* top = NULL;
Node* mid = top;
int n = 0;

void printing(){
   Node* t = top;
   cout<<"Stack :- ";
   while(t!=NULL){
      cout<<t->data<<" ";
      t = t->next;
   }
   cout<<"\n";
}

void push(int x){
   n++;
   Node* ptr = new Node(x);
   if(top==NULL){
      top = ptr;
      mid = top;
   }else{
      if(n%2==0){
         top->prev = ptr;
         ptr->next = top;
         top = top->prev;
      }else{
         top->prev = ptr;
         ptr->next = top;
         top = top->prev;
         mid = mid->prev;
      }
   }
}

void pop(){
   n--;
   Node* temp = top;
   top = top->next;
   cout<<"Poped :- "<<temp->data<<"\n";
   free(temp);
   if(n%2==0){
      mid = mid->next;
   }
}

int getMiddle(){
   cout<<"Middle :- "<<mid->data<<"\n";
}


int main()
{
   push(3);
   push(5);
   push(6);
   push(7);
   push(14);
   printing();
   getMiddle();
   pop();
   printing();
   getMiddle();
   pop();
   printing();
   getMiddle();

   return 0;
}