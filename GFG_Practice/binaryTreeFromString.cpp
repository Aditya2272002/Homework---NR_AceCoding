#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

Node* go(string& str,int n,int index){
   
   Node* root = newNode(str[index] - '0');
   
   root->left = go(str,n,index+1);
   

   


   


}

int main(){

   string str = "4(2(3)(1))(6(5))";
   int n = str.length();
   Node* root = go(str,n,0);
   preOrder(root);
   return 0;
}