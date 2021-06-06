class Solution {
public:
   int maxSubArray(vector<int>& nums) {
  int maxSum = -1000000;
  int curSum = 0;
  int anchor = 0;
  int explorer;
  if(nums.size() == 0){
    return 0;
  }
  if(nums.size() < 2){
    return nums[0];
  }
  
  for(explorer = 0; explorer < nums.size();explorer++){
    
    curSum += nums[explorer];
    
    if(curSum> maxSum){
      maxSum = curSum;
    }
    if (curSum<0){
      curSum = 0;
      anchor = explorer+1;
    }
    
  }
  cout << maxSum;
  cout << "\n";
  return maxSum;
}
};