#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int>& nums, int target, int left, int right){
  int mid = (left + right)/2;

  if(left <= right){

  
    if(nums[mid] == target){
      return mid;
    }
    else if(nums[mid] < target){
      return helper(nums, target, mid+1, right);
    }
    else{
      return helper(nums, target, left, mid - 1);
    }
  }
  else{
    return -1;
  }

}

int search(vector<int>& nums, int target) {
  return helper(nums, target, 0, nums.size() - 1);
    
}



int search(vector<int>& nums, int target){
  int L = 0;
  int R = nums.size() - 1;

  while(L <= R){
    int m = (L+R)/2;
    if (target > nums[m]){
      L = m + 1;
    }

    else if(target < nums[m]){
      R = m - 1;
    }
    
    else{
      return m;
    }

  }
 return -1;
}


int main(){
  vector<int> nums = {-1,0,3,5,9,12};
  int target = 2;
  int idx = search2(nums, target);

  cout << idx;
  
  return 0;
}