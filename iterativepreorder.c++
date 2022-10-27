#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node *left;
Node *right ;
Node(int val){
    data = val;
  left = NULL;
  right = NULL;
}
};
void iterativepreorder(Node *root){
    if(root == NULL)return ;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* current = s.top();
        cout<<current->data<<" ";
        s.pop();
        if(current->right != NULL)s.push(root->right);
        if(current->left != NULL)s.push(root->left);
    }
}
Node* buildtree(){
  int d;
  cin>>d;
  Node *root;
  if(d==-1){
    return NULL;
  }
  root=new Node(d);
  root->left=buildtree();
  root->right=buildtree();
  return root;
}
// void print(Node*root){
//   if(root==NULL){
//     return;
//   }
//   cout<<root->data<<" ";
//   print(root->left);
//   print(root->right);
// }
int main(){
 Node *root=buildtree();
//  print(root);
 cout<<"\n";
 iterativepreorder(root);
}
