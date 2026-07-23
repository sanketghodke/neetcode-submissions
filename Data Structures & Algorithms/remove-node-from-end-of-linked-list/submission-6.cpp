class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slowptr = dummy;
        ListNode* fastptr = dummy;

        for (int i = 0; i <= n; i++) {
            fastptr = fastptr->next;
        }

        while (fastptr) {
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }

        ListNode* delNode = slowptr->next;
        slowptr->next = delNode->next;
        delete delNode;

        return dummy->next;
    }
};