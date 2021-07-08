class Solution:
    
    def findBound(self, nums, target, isFirst):
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                if isFirst:
                    if mid == left or nums[mid- 1] < target:
                        return mid
                    else:
                        right = mid - 1
                else:
                    if mid == right or nums[mid+1] > target:
                        return mid
                    else:
                        left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        return -1
                    
                        
                    
            
    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        bound1 = self.findBound(nums, target, True)
        
        if bound1 == -1:
            return [-1,-1]
        bound2 = self.findBound(nums, target, False)
        return [bound1, bound2]