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
bool same_tree(Node *tree1 , Node *tree2){
    if(tree1 == NULL and tree2 == NULL)return true;
    if(tree1 == NULL || tree2 == NULL)return false;
    return (tree1->data == tree2->data)&&(same_tree(tree1->left,tree2->left))&&(same_tree(tree1->right,tree2->right));
}
int main()
{
    Node *root=buildtree();
    Node *root1 = buildtree();
    cout<<same_tree(root,root1);
  return 0;
}
