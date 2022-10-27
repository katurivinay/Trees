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
vector<vector<int>> levelorder(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> v;
        for(int i = 0 ; i < n; i++){
            Node *cur = q.front();
            q.pop();
            if(cur->left != NULL){
                q.push(cur->left);
            }
            if(cur->right != NULL){
                q.push(cur->right);
            }
            v.push_back(cur->data);
        }
        ans.push_back(v);
    }
    return ans;
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
void print(Node*root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  print(root->left);
  print(root->right);
}
int main(){
 Node *root=buildtree();
 print(root);
 cout<<"\n";
 vector<vector<int>> v = levelorder(root);
 for(auto i : v){
     for(int j = 0 ; j < i.size() ; j++){
         cout<<i[j]<<" ";
     }
     cout<<"\n";
 }
}
