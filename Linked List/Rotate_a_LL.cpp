class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if(k == 0)
        return head;
        Node* curr = head;
        for(int i = 0; i < k - 1; i++){
            curr = curr->next;
        }
        Node* next_node = curr->next;
        if(next_node == NULL)
        return head;
        curr->next = NULL;
        curr = next_node;
        while(curr->next != NULL)
        curr = curr->next;
        curr->next = head;
        head = next_node;
        return head;
    }
};