#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node*left;
  Node*right;
  Node(int d){
    data=d;
    left=NULL;
    right=NULL;
  }
};
Node* buildtree(){
  int d;
  cin>>d;
  Node*root;
  if(d==-1){
    return NULL;
  }
  root=new Node(d);
  root->left=buildtree();
  root->right=buildtree();
  return root;
}
int depth_of_tree(Node* root, int &daimeter){
    if(root == NULL)return 0;
    int l = depth_of_tree(root->left,daimeter);
    int r = depth_of_tree(root->right,daimeter);
    daimeter = max(daimeter, 1 + l + r);
    return 1 + max(l,r);
}
// bool balanced_binary(Node* root){
//     if(root == NULL)return true;
//     int l = depth_of_tree(root->left);
//     int r = depth_of_tree(root->right);
//     if(abs(r - l) > 1)return false;
//     if(!depth_of_tree(root->left) or !(depth_of_tree(root->right)))return false
//     ;
//     return true;
// }

int main()
{
    Node *root=buildtree();  
    int daimeter = 0;
    //cout<<balanced_binary(root);
    int h = depth_of_tree(root,daimeter);
    cout<<daimeter<<" ";
  return 0;
}
