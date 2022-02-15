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

//iterativePreorder
void iterativePreorder(Node* root){
   stack<pair<Node*,int>> st;
   st.push({root,0});
   while(!st.empty()){
      Node* cur = st.top().first;
      int state = st.top().second;
      st.pop();   

      if(cur==NULL){
         continue;
      }
      else if(state==0){
         cout<<cur->data<<" ";
         st.push({cur,1});
      }
      else if(state==1){
         st.push({cur,2});
         st.push({cur->left,0});
      }
      else{
         st.push({cur->right,0});
      }
   }
}

//iterativePostorder
void iterativePostorder(Node* root){
   stack<pair<Node*,int>> st;
   st.push({root,0});
   while(!st.empty()){
      Node* cur = st.top().first;
      int state = st.top().second;
      st.pop();

      if(cur==NULL){
         continue;
      }
      else if(state==0){
         st.push({cur,1});
         st.push({cur->left,0});
      }
      else if(state==1){
         st.push({cur,2});
         st.push({cur->right,0});
      }
      else{
         cout<<cur->data<<" ";
      }
   }
}

//🌟🌟.Level Order with more funcationality O(N)
void levelOrder2(Node* root){
   queue<Node*>q;
   q.push(root);
   int level =0;
   int d = 0;
   while(!q.empty()){
      int n = q.size();
      d = d + n;
      cout<<"Level = "<<level<<" has "<<n<<" nodes :- ";
      for(int i=0;i<n;i++){
         Node* cur = q.front();
         q.pop();
         cout<<cur->data<<" ";
         if(cur->left!=NULL){
            q.push(cur->left);
         }
         if(cur->right!=NULL){
            q.push(cur->right);
         }
      }
      level++;
      cout<<"\n";
   }
}

void leftView(Node* root){
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
      int n = q.size();
      for(int i=0;i<n;i++){
         Node* cur = q.front();
         q.pop();
         if(i==0)
            cout<<cur->data<<" ";
         if(cur->left!=NULL){
            q.push(cur->left);
         }
         if(cur->right!=NULL){
            q.push(cur->right);
         }
      }
   }
   cout<<"\n";
}

void rightView(Node* root){
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
      int n = q.size();
      for(int i=0;i<n;i++){
         Node* cur = q.front();
         q.pop();
         if(i==n-1)
            cout<<cur->data<<" ";
         if(cur->right!=NULL){
            q.push(cur->right);
         }
         if(cur->left!=NULL){
            q.push(cur->left);
         }
      }
   }
   cout<<"\n";
}

void topView(Node* root){
   queue<pair<Node*,int>>q;
   q.push({root,0});
   map<int,int> freq;
  
   while(!q.empty()){
      int n = q.size();
     
      for(int i=0;i<n;i++){
        pair<Node*,int> cur = q.front();
         q.pop();

         if(freq.find(cur.second) == freq.end()){
            freq[cur.second] = cur.first->data;
         }

         if(cur.first->left!=NULL){
            q.push({cur.first->left,cur.second - 1});
         }

         if(cur.first->right!=NULL){
            q.push({cur.first->right,cur.second + 1});
         }
      }
   }

   for(auto i : freq){
      cout<<i.second<<" ";
   }
   cout<<"\n";
}

void bottomView(Node* root){
   map<int,int> freq;
   queue<pair<Node*,int>> q;
   q.push({root,0});

   while(!q.empty()){
      int n = q.size();

      for(int i=0;i<n;i++){
         pair<Node*,int> cur = q.front();
         q.pop();

         freq[cur.second] = cur.first->data;
         
         if(cur.first->left!=NULL){
            q.push({cur.first->left,cur.second - 1});
         }
         if(cur.first->right!=NULL){
            q.push({cur.first->right,cur.second + 1});
         }
      }
   }

   for(auto i:freq){
      cout<<i.second<<" ";
   }
   cout<<"\n";
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
      // root=insert(root,data);
   // }

   Node* root = new Node(1);
   root->left = new Node(2);
   root->left->left= new Node(4);
   root->left->right = new Node(5);
   root->right = new Node(3);
   root->right->left= new Node(6);
   root->right->right = new Node(7);
   root->right->right->left = new Node(8);
   // iterativeInorder(root);
   // iterativePreorder(root);
   // preorderTraversal(root);
   // postorderTraversal(root);
   iterativePostorder(root);

   return 0;
}