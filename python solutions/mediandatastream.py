class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.nums = []
        
        
        

    def addNum(self, num: int) -> None:
#         i = 0
#         j = 0
#         newnums = []
#         arr2 = [num]
        
#         while(i < len(self.nums) and j < len(arr2)):
#             if(self.nums[i] < arr2[j]):
#                 newnums.append(self.nums[i])
#                 i += 1
#             else:
#                 newnums.append(arr2[j])
#                 j += 1
        
#         while i < len(self.nums):
#             newnums.append(self.nums[i])
#             i += 1
        
#         while j < len(arr2):
#             newnums.append(arr2[j])
#             j += 1
        
#         self.nums = newnums
        self.nums.append(num)
        self.nums = sorted(self.nums)
        

    def findMedian(self) -> float:
        if len(self.nums) == 0:
            return 0
        if len(self.nums) % 2 != 0:
            index = int((len(self.nums) - 1) / 2)
            #print(index)
            return self.nums[index]
        else:
            index2 = int(len(self.nums) / 2)
            index1 = int((len(self.nums) / 2) - 1)
            ans = (self.nums[index1] + self.nums[index2] ) / 2
            return ans
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()