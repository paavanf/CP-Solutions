class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp={}
        for i in range(len(nums)):
            diff=target-nums[i]
            if diff in mp:
                return [i,mp[diff]]
            mp[nums[i]]=i
        return []