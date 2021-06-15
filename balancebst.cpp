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


void helper(TreeNode* node, vector<int> visited){
  //left
  if(node->left != nullptr){
    helper(node->left, visited);
  }
  
  //add node to visited
  visited.push_back(node->val);

  //right
  if(node->right != nullptr){
    helper(node->right, visited);
  }
}


TreeNode* constructTree(vector<int> arr, int left, int right){
  if(left > right){
    return nullptr;
  }
  int mid = (left + right) / 2;

  TreeNode* root = new TreeNode(arr[mid], nullptr, nullptr);
  root->left = constructTree(arr, left, mid-1);
  root->right = constructTree(arr, mid+1, right);
  return root;
}


TreeNode* balanceBST(TreeNode* root) {
  vector<int> visited;
  helper(root, visited);
  //In order is lnr
  
  TreeNode newtree = *constructTree(visited, 0, visited.size() - 1);

  
  

}


