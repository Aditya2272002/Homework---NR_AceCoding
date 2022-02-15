#include <bits/stdc++.h>
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


void printing(Node* parent)
{
    Node* curr = parent;
    while (curr != NULL){
        cout << curr->data << " ";
        curr = curr->right;
    }
}


/*

1. Create a dummy node.
2. Create a variable called ‘prev’ and make it point to the dummy node.
3. Perform in-order traversal and at each step. 
    Set prev -> right = curr
    Set prev -> left = NULL
    Set prev = curr

*/


void inorder(Node* root,Node*& prev){
    if(root==NULL){
        return;
    }
    
    inorder(root->left,prev);
    prev->right = root;
    prev->left = NULL;
    prev = root;
    inorder(root->right,prev);
}


Node* flatten(Node* root){
    Node* prev = new Node(-1);
    Node* ans = prev;
    inorder(root,prev);
   //  printing(ans);
    return ans->right;
}


int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
 
   
    printing(flatten(root));
 
    return 0;
}





