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
int depth_of_tree(Node* root){
    if(root == NULL)return 0;
    int l = depth_of_tree(root->left);
    int r = depth_of_tree(root->right);
    return 1 + max(l,r);
}
int main()
{
    Node*root=buildtree();  
    cout<<depth_of_tree(root);
  return 0;
}
