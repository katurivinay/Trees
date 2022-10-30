#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
  int val;
  Node*left;
  Node*right;
  Node(int d){
    val=d;
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
  cout<<root->val<<" ";
  print(root->left);
  print(root->right);
}
bool root_path(Node *root, int a,vector<int> &arr){
    if(!root)return false;
    arr.push_back(root->val);
    if(root->val == a)return true;
    if(root_path(root->left,a,arr) || root_path(root->right,a,arr))return true;
    arr.pop_back();
    return false;
}
void helper(Node *root , int a){
    vector<int> arr;
    if(root_path(root,a,arr)){
        for(auto i : arr)
            cout<<i<<" ";
    }
    else{
    cout<<0<<" ";
    }
    return ;
}
int main()
{
    Node*root=buildtree();  
    //print(root);
    int a ;
    cin>>a;
    helper(root,a);
  return 0;
}
