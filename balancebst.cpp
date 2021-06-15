#include <iostream>
#include <vector>

using namespace std;



struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> visited = {};

void helper(TreeNode* node){
  //left
  if(node->left != nullptr){
    helper(node->left);
  }
  
  //add node to visited
  visited.push_back(node);

  //right
  if(node->right != nullptr){
    helper(node->right);
  }
}


TreeNode* constructTree(int left, int right){
  if(left > right){
    return nullptr;
  }
  int mid = (left + right) / 2;

  TreeNode* root = visited[mid];
  root->left = constructTree(left, mid-1);
  root->right = constructTree(mid+1, right);
  return root;
}


TreeNode* balanceBST(TreeNode* root) {
  helper(root);
  //In order is lnr

  TreeNode* newtree = constructTree(0, visited.size() - 1);


  return newtree;
}