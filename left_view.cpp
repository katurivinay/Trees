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
void left_view(Node *root){
    if(root == NULL)return;
                     //axis    
    queue<pair<Node*,int>> q;
    q.push({root,0});
     //axis,data;
    map<int,int> mp;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0 ; i < n ; i++){
        auto curr = q.front();
        q.pop();
        Node* curr_node = curr.first;
        int axis = curr.second;
        if(mp.find(axis) == mp.end())
        mp[axis] = curr_node->data;
        if(curr_node->left){
            q.push({curr_node->left,axis + 1});
        }
        if(curr_node->right){
            q.push({curr_node->right,axis+1});
        }
     }
    }
    for(auto it : mp)cout<<it.first<<" "<<it.second<<"\n";
}
int main()
{
    Node*root=buildtree();
    left_view(root);
  return 0;
}
