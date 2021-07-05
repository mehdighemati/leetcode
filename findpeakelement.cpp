#include <vector>
#include <iostream>

using namespace std;

int helper(vector<int>& nums, int left, int right){

  if (left == right){
    return left;
  }

  int mid = left + (right - left) / 2;

  if(nums[mid] > nums[mid + 1]){
    //check LHS
    
    return helper(nums, left, mid);

  }
  //check RHS
  return helper(nums, mid+1, right);

  // if(left < right){
  //   int leftPeak = mid - 1;
  //   int rightPeak = mid + 1;
  
  //   cout << nums[leftPeak] << " " << nums[mid] << " " << nums[rightPeak];
  //   cout << endl;
  //   // if(nums[leftPeak] < nums[mid] && nums[mid] > nums[rightPeak]){
  //   //   cout << "THIS IS BEING RUN";
  //   //   cout << endl;
  //   //   return mid;

  
  //   // }
    
  //   // else{
    
  //   //   return helper(nums, left, mid - 1);
  //   //   return helper(nums, mid + 1, right);
    
  //   // }  
    

  // }
  // else{
  //   return left;
  // }
}

int findPeakElement(vector<int>& nums) {
  int left = 0;
  int right = nums.size();
  return helper(nums, 0, right);
}