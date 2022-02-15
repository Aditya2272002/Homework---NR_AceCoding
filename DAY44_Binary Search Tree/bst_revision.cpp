#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
      int data;
      Node* left;
      Node* right;
      Node(int data){
         this->data = data;
         left = NULL;
         right = NULL;
      }
};

void inorder(Node* root){
   if(root==NULL){
      return;
   }
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}

Node* insert(Node* root,int data){
   if(root==NULL){
      return new Node(data);
   }
   if(data > root->data){
      root->right = insert(root->right,data);
   }else{
      root->left = insert(root->left,data);
   }
}

bool searchNode(Node* root,int key){
   if(root==NULL){
      return  false;
   }
   if(root->data == key){
      return true;
   }
   else if(root->data > key){
      return searchNode(root->left,key);
   }else{
      return searchNode(root->right,key);
   }
}

Node* MAX(Node* root){
   if(root==NULL){
      return NULL;
   }
   Node* cur = root;
   while(cur->right!=NULL){
      cur= cur->right;
   }
   return cur;
}

//V.V.IMPO
Node* deletionBST(Node* root,int key){
   if(root==NULL){
      return NULL;
   }
   //Searching for key Node
   if(key > root->data){
      root->right = deletionBST(root->right,key);
   }else if(key < root->data){
      root->left = deletionBST(root->left,key);
   }else{
      if(root->left==NULL && root->right==NULL){
         return NULL;
      }else if(root->left==NULL){
         return root->right;
      }else if(root->right==NULL){
         return root->left;
      }else{
         Node* predecessor = MAX(root->left);
         root->data = predecessor->data;
         predecessor->data = key;
         root->left = deletionBST(root->left,key);
      }
   }
   return root;
}


int main()
{
   Node* root = NULL;
   int n;
   cout<<"Enter number of nodes:- ";
   cin>>n;

   for(int i=0;i<n;i++){
      int data;
      cout<<"Data :- ";
      cin>>data;
      root = insert(root,data);
   }  
   inorder(root);
   cout<<"\n";
   Node* r = deletionBST(root,12);
   inorder(r);
   
   return 0;
}