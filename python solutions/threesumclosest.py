class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        i =0
        j = 2
        curSum = 0
        diff = 100000000
        
        for i, val in enumerate(nums):
            low = i+1
            high = len(nums)-1
            while low < high:
                curSum = val + nums[low] + nums[high]
                if abs(target - curSum) < abs(diff):
                    diff = target - curSum
                if curSum < target:
                    low += 1
                else:
                    high -= 1
                if diff == 0:
                    break
        return target - diff
                    
            
            
            
        