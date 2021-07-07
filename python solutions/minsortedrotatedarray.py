def helper(nums, left, right):
        mid = left + (right - left) // 2
        if(left <=  right):
            if nums[mid+1] < nums[mid]:
                return nums[mid+1]
            if nums[mid] < nums[mid-1]:
                return nums[mid]
            if nums[mid] > nums[0]:
                return helper(nums, mid + 1, right)
            else:
                return helper(nums, left, mid - 1)
        
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if nums[len(nums) - 1] > nums[0]:
            return nums[0]
        return helper(nums, 0, len(nums) - 1)
        
        