// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Ronnieleee
// Date   : 2021-01-06

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

class Solution {
public:
    //
    // 1) Traverse the vector one by one
    // 2) just search the 'target - numbers[i]' in the map.
    // 3) if yes return i unorder_map[other]
    //    if not add map[number[i]] = i to the map
    //    until you search the right i and the unorder_map[other]
    //
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> unorder_map;
        vector<int> result;

        for (int i = 0; i < numbers.size(); i++) {
            int other = target - numbers[i];
            if (unorder_map.count(other)) {
                result.push_back(unorder_map[other]);
                result.push_back(i);
                return result;
            }
            unorder_map[numbers[i]] = i;
        }
        return result;
    }
};

/*
by using cpp unordered_map container and its member function count.
we often call it hashmap in datastruct course.
*/