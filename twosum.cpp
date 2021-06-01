#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, std::vector<int>> hm = {};
  int curr_size = hm.size();
  for(int n = 0; n < nums.size(); n++){
    if (hm.find(n) != hm.end()){
      hm[nums[n]].push_back(n);
    }
    else{
      hm[nums[n]] = {n};
    }
    curr_size = hm.size();
  }
  std::vector<int> ans;
  for(int n = 0; n < nums.size(); n++){
    int diff = target - nums[n];
    auto search = hm.find(diff);
    if(search != hm.end()){
      int sec_size = search->second.size();
      if (sec_size > 1){
        for (int i = 0; i<sec_size;i++){
          if (search->second[i] != n){
            ans = {n, search->second[i] };
            return ans;
          } 
        }
      }
      else{
        if (search->second[0] != n){
            ans = {n, search->second[0] };
            return ans;
          }
      }
    }
  }
  return ans;
}

int main() {
  std::cout << "Hello World!\n";
  std::vector<int> vec = {3, 3,3};
  int targ = 6;
  std::vector<int> ans = twoSum(vec, targ);
  std::cout << ans[0] << ", " << ans[1];
  
}

