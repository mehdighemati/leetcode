#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

TreeNode* searchBST(TreeNode* root, int val) {
  if(root == nullptr){
    return root;
  }
  if(root->val == val){
    return root;
  }


  // TreeNode* left = searchBST(root->left, val);
  // TreeNode* right = searchBST(root->right, val);
  
  if(root->val < val){
    return searchBST(root->right, val);
  }
  else{
    return searchBST(root->left, val);;
  }


  
}

int main(){
  return 0;
}