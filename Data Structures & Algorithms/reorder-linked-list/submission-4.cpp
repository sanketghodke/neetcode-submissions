/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp = head;
        ListNode* next = nullptr;
        
        while(temp){
            next = temp -> next;
            temp -> next = prev ;
            prev = temp;
            temp = next;
        }


        return prev;
    }

    void reorderList(ListNode* head) {
        
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        ListNode* start = head;
        ListNode* temp1;
        ListNode* temp2;


        while(slowptr && fastptr && fastptr->next){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
        }
        ListNode* midpoint = reverseList(slowptr);
        // (Start) 0 1 2
        // (midpoint) 6 5 4
        while(midpoint -> next){
            temp1 = start -> next;
            start -> next = midpoint;
            temp2 = midpoint -> next;
            midpoint ->next = temp1;
            midpoint = temp2;
            start = temp1;
        }
    }
};
