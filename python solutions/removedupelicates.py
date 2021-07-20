class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return
        i = 0
        for j,num in enumerate(nums[1::]):
            if nums[i] != num:
                i += 1
                nums[i] = num
        return i + 1
            
            