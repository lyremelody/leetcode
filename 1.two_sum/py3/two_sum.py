#!/usr/bin/env python3


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) < 2:
            return []
        
        for i in range(len(nums)):
            new_target = target - nums[i]
                
            for j in range(i + 1, len(nums)):
                if new_target == nums[j]:
                    return [i, j]
        
        return []


if __name__ == '__main__':
	nums = [2, 7, 11, 15]
	target = 9
	s = Solution()
	print (s.twoSum(nums, target))

