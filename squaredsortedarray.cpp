#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
  int a = 0;
  int b = nums.size() - 1;
  vector<int> ans(nums.size());
  int leftover = nums.size()-1;

  while(a <= b){
    int num1 = nums[a];
    int num2 = nums[b];
    if(num1*num1 < num2*num2){
      ans[leftover] = num2*num2;
      b--;
    }
    else{
      ans[leftover] = num1*num1;
      a++;
    }
    leftover--;
  }

  return ans;
  
  
}