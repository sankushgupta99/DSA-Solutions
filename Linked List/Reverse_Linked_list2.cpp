class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev = NULL, *curr = head; int i;
        
        for(i = 1; i < left; i++){
            prev = curr;
            curr = curr->next;
        }
        
        ListNode* leftMinus1 = prev;
        ListNode* leftNode = curr;
        
        while(i <= right){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            i++;
        }
        
        leftNode->next = curr;
        (leftMinus1 != NULL) ? leftMinus1->next = prev : head = prev;
        
        return head;
    }
};