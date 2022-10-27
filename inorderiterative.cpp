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
void iterativeinorder(Node *root){
    if(root == NULL)return ;
    stack<Node*> s;
    while(true){
       if(root != NULL){
           s.push(root);
           root = root->left;
       }
       else
       {
         if(s.empty())break;
         root = s.top();
         s.pop();
         cout<<root->data<<" ";
         root = root->right;
       }
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
 iterativeinorder(root);
}
