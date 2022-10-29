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
void vertical_order_travel(Node *root){
    if(root == NULL)return;
                         //axis,level    
    queue<pair<Node*, pair<int,int>>> q;
    q.push({root,{0,0}});
     //axis,level,data;
    map<int,map<int,multiset<int>>> mp;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        Node* curr_node = curr.first;
        int axis = curr.second.first, level = curr.second.second;
        mp[axis][level].insert(curr_node->data);
        if(curr_node->left){
            q.push({curr_node->left,{axis-1,level+1}});
        }
        if(curr_node->right){
            q.push({curr_node->right,{axis+1,level+1}});
        }
    }
        vector<vector<int>> ans;
        for(auto axis : mp){
            vector<int> col;
            for(auto ele : axis.second){
                col.insert(col.end(),ele.second.begin(),ele.second.end());
            }
            ans.push_back(col);
        }
        for(auto i : ans){
            for(auto k : i){
                cout<<k<<" ";
            }
            cout<<"\n";
        }
}
int main()
{
    Node*root=buildtree();
    vertical_order_travel(root);
  return 0;
}
