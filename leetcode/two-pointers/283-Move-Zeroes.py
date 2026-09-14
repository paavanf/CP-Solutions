class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        w=0
        for x in nums:
            if x!=0:
                nums[w]=x
                w+=1
        while w<len(nums):
            nums[w]=0
            w+=1
        