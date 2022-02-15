#include<bits/stdc++.h>
using namespace std;

/*

CODE:- 
Aditya Maurya
follow on Medium :- https://adi22maurya.medium.com/

*/

class Node{
   public:
      int data;
      vector<Node*> child;

      Node(int data){
         this->data = data;
      }
};



void preorder(Node* root){
   if(root==NULL){
      return;
   }
   cout<<root->data<<" ";
   for(Node* nbr:root->child){
      preorder(nbr);
   }
}

void postorder(Node* root){
   if(root==NULL){
      return;
   }
   for(Node* nbr:root->child){
      postorder(nbr);
   }
   cout<<root->data<<" ";
}

void levelorder(Node* root){
   queue<Node*> q;
   q.push(root);
   cout<<"\n";

   while(!q.empty()){
      int n = q.size();
      for(int i=0;i<n;i++){
         Node* cur = q.front();
         q.pop();
         cout<<cur->data<<" ";

         for(Node* t:cur->child){
            q.push(t);
         }
      }
      cout<<"\n";
   }
}




int main()
{

   Node* root = new Node(1);

   root->child.push_back(new Node(2));
   root->child.push_back(new Node(3));
   root->child.push_back(new Node(4));

   root->child[0]->child.push_back(new Node(5));
   root->child[0]->child.push_back(new Node(6));
   root->child[0]->child.push_back(new Node(7));

   root->child[2]->child.push_back(new Node(8));

   root->child[0]->child[2]->child.push_back(new Node(9));
   root->child[0]->child[2]->child.push_back(new Node(10));




   cout<<"\nPreorder :- ";
   preorder(root);

   cout<<"\nPostorder :- ";
   postorder(root);

   cout<<"\nLevelorder :- ";
   levelorder(root);
   
   cout<<"\n\n";
   return 0;
}
