#include <iostream>
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
void print(Node*root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  print(root->left);
  print(root->right);
}
int lowestcommon(Node *root, int a , int b){
    if(root == NULL)return 0;
    if(root->data == a)return a;
    if(root->data == b)return b;
    
    int l =0;
    if(root->left)
    l = lowestcommon(root->left,a,b);
    int r = 0;
    if(root->right)
    r = lowestcommon(root->right,a,b);
    if(l == 0)return r;
    else if(r == 0)return l;
    else{
        return root->data;
    }
}
int main()
{
    Node*root=buildtree();  
    //print(root);
    int a,b;
    cin>>a>>b;
    cout<<lowestcommon(root,a,b);
    return 0;
}
