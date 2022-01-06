# Source : https://leetcode.com/problems/add-two-numbers/
# Author : Ronnieleee
# Date   : 2021-01-06
"""
/*******************************************************************************
*
* You are given two linked lists representing two non-negative numbers.
* The digits are stored in reverse order and each of their nodes contain a
* single digit. Add the two numbers and return it as a linked list.
*
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*
*******************************************************************************/
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        result = ListNode(0)
        navigator = result
        sum = 0
        
        while l1 or l2 or sum > 0:
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next
            navigator.next = ListNode(sum % 10)
            navigator = navigator.next
            sum = int(sum / 10)
        
        return result.next