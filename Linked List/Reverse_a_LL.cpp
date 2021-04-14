class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next_node = NULL;
        while(curr != NULL){
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        head = prev;
        return head;
    }
    
};