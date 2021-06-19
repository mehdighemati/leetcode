#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums){
  int count = 0;
  int max = 0;

  for(int i=0; i<nums.size(); i++){
    if(nums[i] == 1){
      count += 1;
       
    }else{
      if (count> max){
        max = count;
      }
      count = 0;
    }
  }
  if (count > max){
    max = count;
  }
  return max;
}