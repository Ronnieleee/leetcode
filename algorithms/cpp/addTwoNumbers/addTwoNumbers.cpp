// Source : https://leetcode.com/problems/add-two-numbers/
// Author : Ronnie
// Date   : 2015-12-04

/*******************************************************************************
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
        int x = 0;
        int y = 0;
        int upper = 0;
        int lower = 0;
        ListNode *p = NULL;
        ListNode **t = &p;

        while (l1 != NULL || l2 != NULL) {
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);

            lower = x + y + upper;

            ListNode *node = new ListNode(lower%10);
            *t = node;
            t = (&node->next);

            upper = lower/10;
        }
        if (upper > 0) {
            ListNode *node = new ListNode(upper%10);
            *t = node;
        }

        return p;
    }

private:
    int getValueAndMoveNext(ListNode* &list){
        int x = 0;
        if (list != NULL){
            x = list->val;
            list = list->next;
        }
        return x;
    }
};
