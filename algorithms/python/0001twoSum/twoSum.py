# Source : https://oj.leetcode.com/problems/two-sum/
# Author : Ronnieleee
# Date   : 2021-01-06
"""
/*******************************************************************************
*
* Given an array of integers, find two numbers such that they add up to a
* specific target number.
*
* The function twoSum should return indices of the two numbers such that they
* add up to the target, where index1 must be less than index2. Please note that
* your returned answers (both index1 and index2) are not zero-based.
*
* You may assume that each input would have exactly one solution.
*
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*
*******************************************************************************/
"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i in range(len(nums)):
            other = target - nums[i]
            if other in hashmap:
                return [i, hashmap[other]]
            hashmap[nums[i]] = i

# in python dict is a hashmap.
        