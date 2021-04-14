class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        Node* curr = head;
        Node* currp1 = NULL;
        Node* currp2 = NULL;
        Node* prev = NULL;
        while(curr != NULL && curr->next != NULL){
            currp1 = curr->next;
            currp2 = curr->next->next;
            currp1->next = curr;
            if(curr == head)
            head = currp1;
            curr->next = currp2;
            if(prev != NULL)
            prev->next = currp1;
            curr = curr->next;
            prev = currp1->next;
        }
        return head;
    }
};