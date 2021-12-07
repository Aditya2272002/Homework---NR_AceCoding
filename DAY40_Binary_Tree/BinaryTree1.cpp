#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   Node* left;
   int data;
   Node* right;

   Node(int data){
      this->data = data;
      left = NULL;
      right = NULL;
   }
};

Node* insert(Node* root, int data){
   if(root == NULL){
      return new Node(data);
   }
   cout<<"Current Node is "<<root->data<<"\n";
   cout<<"Enter 'L' to insert at LEFT and 'R' to insert at RIGHT :- \n";
   char input;
   cin>>input;
   
   if(input=='L'){
      root->left = insert(root->left,data);
   }else{
      root->right = insert(root->right,data);
   }
   return root;
}

//Left Visit Right (LVR)
void inorderTraversal(Node* root){
   if(root==NULL){
      return;
   }
   inorderTraversal(root->left);
   cout<<root->data<<" ";
   inorderTraversal(root->right);
}

//Visit Left Right (VLR) 
void preorderTraversal(Node* root){
   if(root==NULL){
      return;
   }
   cout<<root->data<<" ";
   preorderTraversal(root->left);
   preorderTraversal(root->right);
}

//Left Right Visit (LRV)
void postorderTraversal(Node* root){
   if(root==NULL){
      return;
   }
   postorderTraversal(root->left);
   postorderTraversal(root->right);
   cout<<root->data<<" ";
}

//LevelOrder Traversal :-HINT (Use Queue)
void levelorderTraversal(Node* root){
   queue<Node*> q;
   q.push(root);

   while(!q.empty()){
      Node* cur = q.front();
      q.pop();
      cout<<cur->data<<" ";
      if(cur->left!=NULL)
         q.push(cur->left);
      if(cur->right!=NULL){
         q.push(cur->right);
      }
   }
}

void iterativeInorder(Node* root){
   stack<pair<Node*,int>> st;
   st.push({root,0});
   while(!st.empty()){
      Node* cur = st.top().first;
      int state = st.top().second;
      st.pop();

      if(cur==NULL){
         continue;
      }
      if(state==0){
         st.push({cur,1});
         st.push({cur->left,0});
      }
      else if(state==1){
         cout<<cur->data<<" ";
         st.push({cur,2});
      }else{
         st.push({cur->right,0});
      }
   }
}

int main()
{  
   // Node* root = NULL;
   // int n;
   // cout<<"Enter number of nodes :- \n";
   // cin>>n;
   // for(int i=0;i<n;i++){
   //    int data;
   //    cout<<"Enter node data :- \n";
   //    cin>>data;
   //    root=insert(root,data);
   // }
   Node* root = new Node(10);
   root->left = new Node(20);
   root->left->left= new Node(40);
   root->right = new Node(30);
   root->right->left = new Node(50);
   root->right->right = new Node(60);

   // inorderTraversal(root);
   cout<<"\n";
   // preorderTraversal(root);
   // cout<<"\n";
   // postorderTraversal(root);

   iterativeInorder(root);
   return 0;
}