#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> ans(nums.size());
  vector<int> LHS(nums.size());
  vector<int> RHS(nums.size());

  cout << "Test 1" << "\n";

  //LHS
  LHS[0] = 1;
  cout << "Test 2" << "\n";
  for(int i = 1; i < nums.size(); i++){
    LHS[i] = LHS[i-1] * nums[i-1];
  }

  //RHS
  RHS[nums.size()-1] = 1;
  
  for(int i= nums.size()-2; i >= 0; i--){
    RHS[i] = RHS[i+1] * nums[i+1];
  }

  //product
  for(int i = 0; i < LHS.size(); i++){
    ans[i] = LHS[i] * RHS[i];
  }

   for(int i = 0; i < ans.size(); i++){
    cout << LHS[i] << ", ";
  }
  cout << endl; 
  for(int i = 0; i < ans.size(); i++){
    cout << RHS[i] << ", ";
  }
  cout << endl;

  return ans;
}


int main(){
  // Input: nums = [1,2,3,4]
  // Output: [24,12,8,6] 
  vector<int> input = {1,2,3,4};
  auto ans = productExceptSelf(input);
  
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << ", ";
  }
    cout << endl;

  return 0;
}