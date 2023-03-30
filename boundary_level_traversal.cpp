#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct Node * left, * right;
};
void addleftboundary(Node* root, vector<int> &res){
    Node* curr= root->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }    
}
void addrightboundary(Node* root, vector<int> &res){
    Node* curr = root->right;
    while(curr){
        if(isLeaf(curr)) res.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
}
void addleaves(Node* root, vector<int> &res){
    if (isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addleaves(root->left, res);
    if(root->right) addleaves(root->right, res);
}
bool isLeaf(Node* root){
    return !root->left && !root->right;
}
vector<int> printboundary(Node* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addleftboundary(root, res);
    addleaves(root, res);
    addrightboundary(root, res);
    return res;
}
int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);

  vector < int > boundaryTraversal;
  boundaryTraversal = printboundary(root);

  cout << "The Boundary Traversal is : ";
  for (int i = 0; i < boundaryTraversal.size(); i++) {
    cout << boundaryTraversal[i] << " ";
  }
  return 0;
}
