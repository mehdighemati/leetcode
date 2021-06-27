#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



int maxDepth(TreeNode* root) {
  // q.push(root);
  // max_depth++;
  
  // if(root->left != nullptr){
  //   q.push(root->left);
  // }
  
  // if(root->right != nullptr){
  //   q.push(root->right);
  // }
  
  if(root == nullptr){
    return 0;
  }
  return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
}



int main(){
  
  return 0;
}