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
void postorder(Node* root){
    stack<Node*> s1;
    stack<int> s2;
    s1.push(root);
    while(!s1.empty()){
        Node *curr = s1.top();
        s1.pop();
        s2.push(curr->data);
        if(curr->left)s1.push(curr->left);
        if(curr->right)s1.push(curr->right);
    }
    vector<int> postorders;
    while(!s2.empty()){
        postorders.push_back(s2.top());
        s2.pop();
    }
    for(auto i : postorders){
        cout<<i<<" ";
    }
}
int main()
{
    Node*root=buildtree();  
    postorder(root);
  return 0;
}
