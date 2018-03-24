/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */

//注意点 新链表的游标newList也要移动
class Solution {
        public:
                ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
                        if (l1 == NULL){
                                return l2;
                        }
                        if (l2 == NULL) {
                                return l1;
                        }
                        ListNode* p1 = l1;
                        ListNode* p2 = l2;
                        ListNode *newlist,*head;
                        if (p1->val <= p2->val){
                                newlist = p1;
                                p1 = p1 ->next;
                        } else {
                                newlist = p2;
                                p2 = p2->next;
                        }
                        head = newlist;
                        while (p1 != NULL && p2 != NULL) {
                                if (p1->val <= p2->val){
                                        newlist->next = p1;
                                        newlist = p1;
                                        p1 = p1 ->next;
                                } else {
                                        newlist->next = p2;
                                        newlist = p2;
                                        p2 = p2->next;
                                }
                        }
                        if (p1 == NULL && p2 != NULL) {
                                newlist->next = p2;
                        }
                        if (p1 != NULL && p2 == NULL) {
                                newlist->next = p1;
                        }
                        return head;
                }
};
