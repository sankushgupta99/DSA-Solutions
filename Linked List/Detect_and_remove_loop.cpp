class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head == NULL)
        return;
        Node* slow_ptr = head;
        Node* fast_ptr = head;
        int flag = 0;
        while(fast_ptr != NULL && fast_ptr->next != NULL){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            if(slow_ptr == fast_ptr){
                flag++;
                break;
            }
        }
        if(flag){
            slow_ptr = head;
            while(slow_ptr != fast_ptr){
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
            while(slow_ptr->next != fast_ptr){
                slow_ptr = slow_ptr->next;
            }
            slow_ptr->next = NULL;
        }
    }
};