// Source : https://leetcode.com/problems/add-two-numbers/
// Author : Ronnieleee
// Date   : 2021-01-06

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *l3 = NULL;
        listNode **navigator = &l3;

        while(l1 || l2 || sum > 0)
        {
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            (*navigator) = new ListNode(sum%10);
            sum /= 10;
            navigator = &((*navigator)->next);
        }
        return l3;
    }
};

/*
cpp new keyword
Complex *pc = new Complex(1, 2);
return a point.
*/