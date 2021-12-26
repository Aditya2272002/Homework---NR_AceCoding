#include<iostream>
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

class BST{
   private:
      Node* root;
      int size;
   
   public:
      BST(){
         root = NULL;
         size = 0;
      }

      Node* insertHelper(Node* root,int data){
         if(root==NULL){
            return new Node(data);
         }
         if(data > root->data){
            root->right = insertHelper(root->right,data);
         }
         else{
            root->left = insertHelper(root->left,data);
         }
         return root;
      }

      void insert(int data){
         root = insertHelper(root,data);
         size++;
      }

      void inorderHelper(Node* root){
         if(root==NULL){
            return;
         }
         inorderHelper(root->left);
         cout<<root->data<<" ";
         inorderHelper(root->right);
      }
      void inorder(){
         cout<<"Inoder traversal : \n";
         inorderHelper(root);
         cout<<"\n";
      }

      bool searchHelper(int data, Node* root){
         if(root==NULL){
            return false;
         }
         if(root->data==data){
            return true;
         }
         else if(root->data > data){
            return searchHelper(data,root->left);
         }else{
            return searchHelper(data,root->right);
         }
      }
      void search(int data){
         cout<<searchHelper(data,root)<<"\n";
      }
};


int main(){

   BST b;
   b.insert(10);
   b.insert(30);
   b.insert(100);
   b.insert(20);
   b.insert(-120);
   b.inorder();
   b.search(100);
   b.search(20323);


   return 0;
}