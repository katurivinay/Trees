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
    int l = max(0,depth_of_tree(root->left,daimeter));
    int r = max(0,depth_of_tree(root->right,daimeter));
    daimeter = max(daimeter, root->data + l + r);
    return (root->data) + max(l,r);
}
int main()
{
    Node *root=buildtree();  
    int daimeter = 0;
    int h = depth_of_tree(root,daimeter);
    cout<<daimeter<<" ";
  return 0;
}
