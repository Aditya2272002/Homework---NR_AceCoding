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

Node* insert(int data,Node* root){
   if(root==NULL){
      return new Node(data);
   }
   char t;
   cout<<"Enter 'L' to insert left otherwise 'R' : "; 
   cin>>t;

   if(t == 'L'){
      root->left = insert(data,root->left);
   }else{
      root->right = insert(data,root->right);
   }
   return root;
}

void inorder(Node* root){
   if(root==NULL){
      return;
   }
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}

void preorder(Node* root){
   if(root==NULL){
      return ;
   }
   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
}

void postorder(Node* root){
   if(root==NULL){
      return;
   }
   postorder(root->left);
   postorder(root->right);
   cout<<root->data<<" ";
}
 
void inoderInterative(Node* root){
   stack<pair<Node*,char>> st;
   st.push({root,'L'});

   while(!st.empty()){
      Node* cur = st.top().first;
      char state = st.top().second;
      st.pop();

      if(cur==NULL){
         continue;
      }
      if(state=='L'){
         st.push({cur,'V'});
         st.push({cur->left,'L'});
      }else if(state=='R'){
         st.push({cur->right,'L'});
      }else{
         cout<<cur->data<<" ";
         st.push({cur->right,'L'});
      }
   }
}

void preorderIterative(Node* root){
   stack<pair<Node*,char>> st;
   st.push({root,'V'});

   while(!st.empty()){
      Node* cur = st.top().first;
      char state = st.top().second;
      st.pop();

      if(cur==NULL){
         continue;
      }
      if(state=='V'){
         cout<<cur->data<<" ";
         st.push({cur,'L'});
      }else if(state=='L'){
         st.push({cur,'R'});
         st.push({cur->left,'V'});
      }else{
         st.push({cur->right,'V'});
      }
   }
}

void postorderIterative(Node* root){
   stack<pair<Node*,char>> st;
   st.push({root,'L'});

   while(!st.empty()){
      Node* cur = st.top().first;
      char state = st.top().second;
      st.pop();

      if(cur==NULL){
         continue;
      }
      if(state=='L'){
         st.push({cur,'R'});
         st.push({cur->left,'L'});
      }else if(state=='R'){
         st.push({cur,'V'});
         st.push({cur->right,'L'});
      }else{
         cout<<cur->data<<" ";
      }
   }
}

void levelorder(Node* root){
   queue<Node*> q;
   q.push(root);

   while(!q.empty()){
      Node* cur = q.front();
      q.pop();
      cout<<cur->data<<" ";
      if(cur->left!= NULL)
         q.push(cur->left);
      if(cur->right!=NULL)
         q.push(cur->right);
   }
}

void levelorder2(Node* root){
   queue<Node*> q;
   q.push(root);
   int level = 0;

   while(!q.empty()){
      int n = q.size();
      cout<<"Level "<<level<<" :- ";
      for(int i=0;i<n;i++){
         Node* cur = q.front();
         q.pop();

         cout<<cur->data<<" ";
         if(cur->left!= NULL)
            q.push(cur->left);
         if(cur->right!=NULL)
            q.push(cur->right);
      }
      cout<<"\n";
      level++;
   }
}

void leftview(Node* root){
   queue<Node*> q;
   q.push(root);

   while(!q.empty()){
      int n = q.size();
      for(int i=0;i<n;i++){
         Node* cur = q.front();
         q.pop();

         if(i==0){
            cout<<cur->data<<" ";
         }
         if(cur->left!=NULL){
            q.push(cur->left);
         }
         if(cur->right!=NULL){
            q.push(cur->right);
         }
      }
   }
}

void rightview(Node* root){
   queue<Node*> q;
   q.push(root);

   while(!q.empty()){
      int n = q.size();
      for(int i=0;i<n;i++){
         Node* cur = q.front();
         q.pop();

         if(i==n-1){
            cout<<cur->data<<" ";
         }
         if(cur->left!=NULL){
            q.push(cur->left);
         }
         if(cur->right!=NULL){
            q.push(cur->right);
         }
      }
   }
}

void topview(Node* root){
   queue<pair<Node*,int>> q;
   q.push({root,0});
   map<int,Node*> m;
  
   while(!q.empty()){
      int n = q.size();     

      for(int i=0;i<n;i++){
         Node* cur = q.front().first;
         int state = q.front().second;
         q.pop();
         if(m.find(state)==m.end())
            m.insert({state,cur});  //   1 : 200     1:300 

         if(cur->left!=NULL){
            q.push({cur->left,state-1});
         }
         if(cur->right!=NULL){
            q.push({cur->right,state+1});
         }
      }
   }
   for(auto x : m){
      cout<<x.second->data<<" ";
   }

}

void bottomview(Node* root){
   queue<pair<Node*,int>> q;
   q.push({root,0});
   map<int,Node*> m;
  
   while(!q.empty()){
      int n = q.size();

      for(int i=0;i<n;i++){
         Node* cur = q.front().first;
         int state = q.front().second;
         q.pop();
         m[state] = cur;

         if(cur->left!=NULL){
            q.push({cur->left,state-1});
         }
         if(cur->right!=NULL){
            q.push({cur->right,state+1});
         }
      }
   }
   for(auto x : m){
      cout<<x.second->data<<" ";
   }
}

int widthBinaryTree(Node* root){
   queue<Node*> q;
   q.push(root);
   int h = 0;

   while(!q.empty()){
      int n = q.size();
      h = max(h,n);
      for(int i=0;i<n;i++){
         Node* cur = q.front();
         q.pop();
         if(cur->left!= NULL)
            q.push(cur->left);
         if(cur->right!=NULL)
            q.push(cur->right);
      }
   }
   return h;
}

int height_Recursive(Node* root){
   if(root==NULL){
      return 0;
   }
   else{
      return max(height_Recursive(root->left),height_Recursive(root->right)) + 1;
   }
}

//Iterative
void printKthLevel(Node* root,int k){
   queue<Node*> q;
   q.push(root);
   int level = 0;
   int j = 0;

   while(!q.empty()){
      int n = q.size();
      for(int i=0;i<n;i++){
         Node* cur = q.front();
         q.pop();
         if(j==k)
            cout<<cur->data<<" ";
         if(cur->left!= NULL)
            q.push(cur->left);
         if(cur->right!=NULL)
            q.push(cur->right);
      }
      j++;
   }
}

// 🌟 IMPORTANT RECUSRIVE IMPLEMENTATION
void printKthLevel_Recursive(Node* root,int k){
   if(root==NULL) return;
   else if(k==0){ 
      cout<<root->data<<" ";
      return ;
   }
   else{
      printKthLevel_Recursive(root->left,k-1);
      printKthLevel_Recursive(root->right,k-1);
   }   
}

vector<int> reverseLevelOrder(Node* root){
   vector<int> ans;
   queue<Node*> q;
   q.push(root);

   while(!q.empty()){
      int n = q.size();
      for(int i=0;i<n;i++){
         Node* cur = q.front();
         q.pop();

         ans.push_back(cur->data);
        
         if(cur== NULL){
            continue;
         }
         if(cur->right!=NULL){
            q.push(cur->right);
         }
         if(cur->left!=NULL){
            q.push(cur->left);
         }
      }
   }
   reverse(ans.begin(),ans.end());
   return ans;
}

Node* mirrorOfBT(Node* root){
   if(root==NULL){
      return root;
   }
   Node* tempLeft = root->left;
   Node* tempRight = root->right;
   root->left = mirrorOfBT(tempRight);
   root->right =mirrorOfBT(tempLeft);
   return root;
}

void zigZagTraversal(Node* root){
   stack<Node*> StOdd;
   stack<Node*> StEven;
   StEven.push(root);
   int level = 0;

   while(!StEven.empty() || !StOdd.empty()){
      if(!StEven.empty()){
         while(!StEven.empty()){
            Node* cur = StEven.top();
            StEven.pop();
            cout<<cur->data<<" ";
            if(cur->left!=NULL){
               StOdd.push(cur->left);
            }
            if(cur->right!=NULL){
               StOdd.push(cur->right);
            }
         }
      }else{
         while(!StOdd.empty()){
            Node* cur = StOdd.top();
            StOdd.pop();
            cout<<cur->data<<" ";
            if(cur->right!=NULL){
               StEven.push(cur->right);
            }
            if(cur->left!=NULL){
               StEven.push(cur->left);
            }
         }
      }
   }
}


void diagonalTraversal(Node* root){
   queue<Node*> q;
   q.push(root);

   while(!q.empty()){
      Node* cur = q.front();
      q.pop();
      while(cur!=NULL){
         if(cur->left!= NULL){
            q.push(cur->left);
         }
         cout<<cur->data<<" ";
         cur = cur->right;
      }
   }
}


//Doing preorder traversal with additonal found variable 
bool found = false;
void pathOfNode(Node* root,int key,vector<Node*>& ans){
   if(root==NULL){
      return;
   }

   if(!found){
      ans.push_back(root);
   }
   if(root->data == key){
      found = true;
      return;
   }

   pathOfNode(root->left,key,ans);
   pathOfNode(root->right,key,ans);
   
   if(!found){
      ans.pop_back();
   }
}


int main()
{
   Node* root = new Node(10);
   root->left = new Node(20);
   root->right = new Node(30);
   root->left->left = new Node(40);
   root->left->right = new Node(50);
   root->left->right->right = new Node(70);
   root->left->right->left = new Node(9);
   root->left->right->right->left = new Node(3);

   vector<Node*> ans;
   found = false;
   pathOfNode(root,3,ans);

   for(Node* x:ans){
      cout<<x->data<<"->";
   }
   cout<<"NULL\n";
   

   return 0;
}