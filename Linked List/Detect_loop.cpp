class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        if(head == NULL)
        return false;
        Node* slow_ptr = head;
        Node* fast_ptr = head;
        while(fast_ptr!=NULL && fast_ptr->next!=NULL){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            if(slow_ptr == fast_ptr)
            return true;
        }
        return false;
    }
};