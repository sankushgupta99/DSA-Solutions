class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL)
        return head;
        node* prev = NULL;
        node* curr = head;
        node* next_node = NULL;
        int i = 0;
        while(curr != NULL && i < k){
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
            i++;
        }
        head->next = reverse(curr, k);
        node* res = prev;
        return res;
    }
};

//OR

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head;
        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        
        ListNode* prev = NULL;
        curr = head;
        
        for(int i = 0; i < count / k; i++){
            ListNode* prev_grp_last = prev;
            ListNode* this_grp_first = curr;
            
            for(int j = 0; j < k; j++){
                ListNode* currp1 = curr->next;
                curr->next = prev;
                prev = curr;
                curr = currp1;
            }
            
            ListNode* this_grp_last = prev;
            ListNode* next_grp_first = curr;
            
            this_grp_first->next = next_grp_first;
            (prev_grp_last == NULL) ? head = this_grp_last : prev_grp_last->next = this_grp_last;
            prev = this_grp_first;
        }
        
        return head;
    }
};